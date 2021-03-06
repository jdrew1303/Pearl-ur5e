#!/usr/bin/env python

#Used https://github.com/ros-planning/moveit_tutorials/blob/master/doc/move_group_python_interface/scripts/move_group_python_interface_tutorial.py as template. See what they do for better explanations. There are parts here--such as setup--which are almost exactly as in that document.

#necessary imports
import sys
import copy
import rospy
import moveit_commander
import moveit_msgs.msg
import geometry_msgs.msg
from math import pi
from std_msgs.msg import String
from moveit_commander.conversions import pose_to_list
import h5py
import roslib
import numpy as np
import preprocessing
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import lte

#not actually sure why this is here or why its necessary, but I suppose its a good way to test tolerances
def all_close(goal, actual, tolerance):
  """
  Convenience method for testing if a list of values are within a tolerance of their counterparts in another list
  @param: goal       A list of floats, a Pose or a PoseStamped
  @param: actual     A list of floats, a Pose or a PoseStamped
  @param: tolerance  A float
  @returns: bool
  """
  all_equal = True
  if type(goal) is list:
    for index in range(len(goal)):
      if abs(actual[index] - goal[index]) > tolerance:
        return False

  elif type(goal) is geometry_msgs.msg.PoseStamped:
    return all_close(goal.pose, actual.pose, tolerance)

  elif type(goal) is geometry_msgs.msg.Pose:
    return all_close(pose_to_list(goal), pose_to_list(actual), tolerance)

  return True

#How the robot is understood and controlled
class MoveGroupPythonInterface(object):
  def __init__(self):
    super(MoveGroupPythonInterface, self).__init__()
    #the moveit_commander is what is responsible for sending info the moveit controllers
    moveit_commander.roscpp_initialize(sys.argv)
    #initialize node
    rospy.init_node('demo_xyz_playback', anonymous=True)
    #Instantiate a `RobotCommander`_ object. Provides information such as the robot's kinematic model and the robot's current joint states
    robot = moveit_commander.RobotCommander()
    #Instantiate a `PlanningSceneInterface`_ object. This provides a remote interface for getting, setting, and updating the robot's internal understanding of the surrounding world:
    scene = moveit_commander.PlanningSceneInterface()
    #Instantiate a `MoveGroupCommander`_ object.  This object is an interface to a planning group (group of joints), which in our moveit setup is named 'manipulator'
    group_name = "manipulator"
    move_group = moveit_commander.MoveGroupCommander(group_name)
    #Create a `DisplayTrajectory`_ ROS publisher which is used to display trajectories in Rviz:
    display_trajectory_publisher = rospy.Publisher('/move_group/display_planned_path', moveit_msgs.msg.DisplayTrajectory, queue_size=20)
 
    #Get all the info which is carried with the interface object
    #We can get the name of the reference frame for this robot:
    planning_frame = move_group.get_planning_frame()
    #print "Planning frame: %s" % planning_frame

    # We can also print the name of the end-effector link for this group:
    eef_link = move_group.get_end_effector_link()
    #print  End effector link: %s" % eef_link

    # We can get a list of all the groups in the robot:
    group_names = robot.get_group_names()
    #print  Available Planning Groups:", robot.get_group_names()

    # Misc variables
    self.box_name1 = ''
    self.box_name2 = ''
    self.robot = robot
    self.scene = scene
    self.move_group = move_group
    self.display_trajectory_publisher = display_trajectory_publisher
    self.planning_frame = planning_frame
    self.eef_link = eef_link
    self.group_names = group_names

  def starting_joint_state(self, js_array):
    # To start the playback of the demo, go to the initial demo position, which can be interpreted as the 0th set of joint states
    # I use joint states instead of cartesians because cartesians will fail if the current state is too far away from the goal state, whereas joint states will simply execute
    joint_goal = self.move_group.get_current_joint_values()
    joint_goal[0] = js_array[0][0]
    joint_goal[1] = js_array[1][0]
    joint_goal[2] = js_array[2][0]
    joint_goal[3] = js_array[3][0]
    joint_goal[4] = js_array[4][0] 
    joint_goal[5] = js_array[5][0]
    # go to the initial position
    # The go command can be called with joint values, poses, or without any parameters if you have already set the pose or joint target for the group
    self.move_group.go(joint_goal, wait=True)
    # Calling ``stop()`` ensures that there is no residual movement
    self.move_group.stop()

  def starting_xyz(self, start_arr):
    wpose = self.move_group.get_current_pose().pose
    wpose.position.x = start_arr[0]
    wpose.position.y = start_arr[1]
    wpose.position.z = start_arr[2]
    wpose.orientation.x = start_arr[3]
    wpose.orientation.y = start_arr[4]
    wpose.orientation.z = start_arr[5]
    wpose.orientation.w = start_arr[6]
    waypoints = []
    waypoints.append(copy.deepcopy(wpose))
    (start_plan, start_fraction) = self.move_group.compute_cartesian_path(waypoints, 0.001, 0.0)
    self.move_group.execute(start_plan, wait=True);
  
  def plan_cartesian_path(self, scale=1):
    #start planning demo playback by reading data from the demo.h5 file
    
    #ask user for the file which the playback is for
    filename = raw_input('Enter the filename of the .h5 demo: ')
    #filename = 'h5 files/recorded_demo Tue Jan 21 10:48:49 2020.h5'
    #filename = 'preprocessedrecorded_demo Tue Jan 21 10:48:49 2020.h5'
    #open the file
    hf = h5py.File(filename, 'r')
    #navigate to necessary data and store in numpy arrays
    demo = hf.get('demo1')
    tf_info = demo.get('tf_info')
    js_info = demo.get('joint_state_info')
    pos_rot_data = tf_info.get('pos_rot_data')
    pos_rot_data = np.array(pos_rot_data)
    js_data = js_info.get('joint_positions')
    js_data = np.array(js_data)
    #close out file
    hf.close()

    #### move to starting position ####
    print "Press 'Enter' to move to starting position"
    raw_input()
    self.starting_joint_state(js_data)

    fig = plt.figure()
    ax = fig.add_subplot(111, projection='3d')
    ax.plot(-pos_rot_data[0],-pos_rot_data[1], pos_rot_data[2])
    #ax.title(filename)
    #ax.ylabel('pos_z')
    #ax.xlabel('pos_y')
    print('Before LTE deformation')
    #print(np.shape(pos_rot_data))
    for i in range (7):
      print(pos_rot_data[i][0])
    for i in range (3):#np.shape(pos_rot_data)[0]):
      #initial = pos_rot_data[i][0]
      initial = pos_rot_data[i][0] + 0.01
      #print(initial)
      end = pos_rot_data[i][(np.shape(pos_rot_data)[1]) - 1]
      #print(end)
      indeces = [0, (np.shape(pos_rot_data)[1]) - 1]
      #print(indeces)
      lte_fixed_points = lte.generate_lte_fixed_points(indeces, [initial, end])
      pos_rot_data[i] = np.reshape(lte.perform_lte(pos_rot_data[i], lte_fixed_points), np.shape(pos_rot_data[i]))
    print('After LTE Deformation')
    #print(np.shape(pos_rot_data))
    for i in range (7):
      print(pos_rot_data[i][0])
    ax.plot(-pos_rot_data[0],-pos_rot_data[1], pos_rot_data[2], 'r')
    #plt.title(filename + ' preprocessed + lte')
    #plt.ylabel('pos_z')
    #plt.xlabel('pos_y')
    plt.show()
    
    print "Press 'Enter' to move to starting position from xyz coords"
    raw_input()
    starting_xyz_position = np.zeros(7);
    starting_xyz_position[0] = -pos_rot_data[0][0]
    starting_xyz_position[1] = -pos_rot_data[1][0]
    starting_xyz_position[2] = pos_rot_data[2][0]
    starting_xyz_position[3] = -pos_rot_data[4][0]
    starting_xyz_position[4] = pos_rot_data[3][0]
    starting_xyz_position[5] = pos_rot_data[6][0]
    starting_xyz_position[6] = -pos_rot_data[5][0]
    self.starting_xyz(starting_xyz_position)

    #record xyz coordinates as a list of waypoints the robot passes through
    waypoints = []
  
    ### TESTING w/ PREPROCESSING
    #print(pos_rot_data)
    ### TESTING ###
    #pos_x = []
    #pos_y = []
    #pos_z = []
    #rot_x = []
    #rot_y = []
    #rot_z = []
    #rot_w = []
    
    #put each xyz into the waypoints array
    wpose = self.move_group.get_current_pose().pose
    for i in range(1, np.size(pos_rot_data, 1)):
      wpose.position.x = -pos_rot_data[0][i]#/tf and rviz have x and y opposite signs
      wpose.position.y = -pos_rot_data[1][i]
      wpose.position.z = pos_rot_data[2][i]
      wpose.orientation.x = -pos_rot_data[4][i]#rviz rotation x is /tf -y
      wpose.orientation.y = pos_rot_data[3][i]#rviz rotation y is /tf x
      wpose.orientation.z = pos_rot_data[6][i]#rviz rotation z is /tf w
      wpose.orientation.w = -pos_rot_data[5][i]#rviz rotation w is /tf -z
      waypoints.append(copy.deepcopy(wpose))
      ### TESTING ###
      #pos_x.append(wpose.position.x)
      #pos_y.append(wpose.position.y)
      #pos_z.append(wpose.position.z)
      #rot_x.append(wpose.orientation.x)
      #rot_y.append(wpose.orientation.y)
      #rot_z.append(wpose.orientation.z)
      #rot_w.append(wpose.orientation.w)
 
    print(waypoints[0])
    print(waypoints[len(waypoints) - 1])
    # We want the Cartesian path to be interpolated at a resolution of 1 mm which is why we will specify 0.001 as the eef_step in Cartesian translation. We will disable the jump threshold by setting it to 0.0, ignoring the check for infeasible jumps in joint space.
    (plan, fraction) = self.move_group.compute_cartesian_path(
                                       waypoints,   # waypoints to follow
                                       0.001,       # eef_step
                                       0.0)       # jump_threshold
    # Note: We are just planning, not asking move_group to actually move the robot yet:
    ### TESTING ###
    #fp = h5py.File ('planned execution.h5', 'w')
    #demo_name = 'demo1'
    #pos_arr = np.array([[pos_x], [pos_y], [pos_z], [rot_x], [rot_y], [rot_z], [rot_w]])
    #dset_pos_rot = fp.create_dataset(demo_name + '/tf_info/pos_rot_data', data=pos_arr)
    #fp.close()
    print('Planning for %f %% of waypoints achieved' % (fraction * 100.0))
    return plan, fraction

  def display_trajectory(self, plan):
    #ask rviz to display the trajectory
    display_trajectory = moveit_msgs.msg.DisplayTrajectory()
    display_trajectory.trajectory_start = self.robot.get_current_state()
    display_trajectory.trajectory.append(plan)
    # Publish
    self.display_trajectory_publisher.publish(display_trajectory);

  def execute_plan(self, plan):
    #execute given plan
    self.move_group.execute(plan, wait=True)

  def wait_for_state_update(self, box_name, box_is_known=False, box_is_attached=False, timeout=4):
    #either this times out and returns false or the object is found within the planning scene and returns true
    start = rospy.get_time()
    seconds = rospy.get_time()
    while (seconds - start < timeout) and not rospy.is_shutdown():
      attached_objects = self.scene.get_attached_objects([box_name])
      is_attached = len(attached_objects.keys()) > 0
      is_known = box_name in self.scene.get_known_object_names()
      if (box_is_attached == is_attached) and (box_is_known == is_known):
        return True
      rospy.sleep(0.1)
      seconds = rospy.get_time()
    return False


  def add_table(self, timeout=4):
    #define a box for the table below the robot
    box_pose = geometry_msgs.msg.PoseStamped()
    box_pose.header.frame_id = self.robot.get_planning_frame()
    #box origin (default = {0, 0, 0, 0, 0, 0, 0})
    box_pose.pose.orientation.w = 1.0
    box_pose.pose.position.z = -0.07
    self.box_name1 = "table"
    #add box to planning scene and specify dimensions
    self.scene.add_box(self.box_name1, box_pose, size=(10, 10, 0.1))
    #wait for the box to be added in or to timeout
    return self.wait_for_state_update(self.box_name1, box_is_known=True, timeout=timeout)

  def add_wall(self, timeout=4):
    #Same as above with different dimensions
    box_pose = geometry_msgs.msg.PoseStamped()
    box_pose.header.frame_id = self.robot.get_planning_frame()
    box_pose.pose.orientation.w = 1.0
    box_pose.pose.position.y = -0.15 # next to the robot
    self.box_name2 = "wall"
    self.scene.add_box(self.box_name2, box_pose, size=(10, 0.02, 10))
    return self.wait_for_state_update(self.box_name2, box_is_known=True, timeout=timeout)
 
  def remove_workspace(self, timeout=4):
    #remove each object from the planning scene, waiting for scene to update before moving on
    self.scene.remove_world_object(self.box_name1)
    self.wait_for_state_update(self.box_name1, box_is_attached=False, box_is_known=False, timeout=timeout)
    self.scene.remove_world_object(self.box_name2)
    return self.wait_for_state_update(self.box_name2, box_is_attached=False, box_is_known=False, timeout=timeout) 


def main():
  try:
    print "Playing back a demo"
    print "Press Ctrl-D to exit at any time"
    print "Press 'Enter' to begin"
    raw_input()
    ur5e_arm = MoveGroupPythonInterface()
    #table and wall have to be added in separately--for some reason adding them together didn't work
    print "Press 'Enter' to add in table"
    raw_input()
    ur5e_arm.add_table()
    print "Press 'Enter' to add in wall"
    raw_input()
    ur5e_arm.add_wall()
    print "Press 'Enter' to begin planning playback"
    raw_input()
    cartesian_plan, fraction = ur5e_arm.plan_cartesian_path()
    print "Press 'Enter' to display planned trajectory"
    raw_input()
    ur5e_arm.display_trajectory(cartesian_plan)
    print "Press 'Enter' to execute planned trajectory"
    raw_input()
    ur5e_arm.execute_plan(cartesian_plan)
    print "Execution complete"
    print "Press 'Enter' to exit'"
    raw_input()
    ur5e_arm.remove_workspace()
  except rospy.ROSInterruptException:
    return
  except KeyboardInterrupt:
    return

if __name__ == '__main__':
  main()
