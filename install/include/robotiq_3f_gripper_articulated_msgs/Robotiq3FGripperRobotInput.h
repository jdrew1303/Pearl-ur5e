// Generated by gencpp from file robotiq_3f_gripper_articulated_msgs/Robotiq3FGripperRobotInput.msg
// DO NOT EDIT!


#ifndef ROBOTIQ_3F_GRIPPER_ARTICULATED_MSGS_MESSAGE_ROBOTIQ3FGRIPPERROBOTINPUT_H
#define ROBOTIQ_3F_GRIPPER_ARTICULATED_MSGS_MESSAGE_ROBOTIQ3FGRIPPERROBOTINPUT_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace robotiq_3f_gripper_articulated_msgs
{
template <class ContainerAllocator>
struct Robotiq3FGripperRobotInput_
{
  typedef Robotiq3FGripperRobotInput_<ContainerAllocator> Type;

  Robotiq3FGripperRobotInput_()
    : gACT(0)
    , gMOD(0)
    , gGTO(0)
    , gIMC(0)
    , gSTA(0)
    , gDTA(0)
    , gDTB(0)
    , gDTC(0)
    , gDTS(0)
    , gFLT(0)
    , gPRA(0)
    , gPOA(0)
    , gCUA(0)
    , gPRB(0)
    , gPOB(0)
    , gCUB(0)
    , gPRC(0)
    , gPOC(0)
    , gCUC(0)
    , gPRS(0)
    , gPOS(0)
    , gCUS(0)  {
    }
  Robotiq3FGripperRobotInput_(const ContainerAllocator& _alloc)
    : gACT(0)
    , gMOD(0)
    , gGTO(0)
    , gIMC(0)
    , gSTA(0)
    , gDTA(0)
    , gDTB(0)
    , gDTC(0)
    , gDTS(0)
    , gFLT(0)
    , gPRA(0)
    , gPOA(0)
    , gCUA(0)
    , gPRB(0)
    , gPOB(0)
    , gCUB(0)
    , gPRC(0)
    , gPOC(0)
    , gCUC(0)
    , gPRS(0)
    , gPOS(0)
    , gCUS(0)  {
  (void)_alloc;
    }



   typedef uint8_t _gACT_type;
  _gACT_type gACT;

   typedef uint8_t _gMOD_type;
  _gMOD_type gMOD;

   typedef uint8_t _gGTO_type;
  _gGTO_type gGTO;

   typedef uint8_t _gIMC_type;
  _gIMC_type gIMC;

   typedef uint8_t _gSTA_type;
  _gSTA_type gSTA;

   typedef uint8_t _gDTA_type;
  _gDTA_type gDTA;

   typedef uint8_t _gDTB_type;
  _gDTB_type gDTB;

   typedef uint8_t _gDTC_type;
  _gDTC_type gDTC;

   typedef uint8_t _gDTS_type;
  _gDTS_type gDTS;

   typedef uint8_t _gFLT_type;
  _gFLT_type gFLT;

   typedef uint8_t _gPRA_type;
  _gPRA_type gPRA;

   typedef uint8_t _gPOA_type;
  _gPOA_type gPOA;

   typedef uint8_t _gCUA_type;
  _gCUA_type gCUA;

   typedef uint8_t _gPRB_type;
  _gPRB_type gPRB;

   typedef uint8_t _gPOB_type;
  _gPOB_type gPOB;

   typedef uint8_t _gCUB_type;
  _gCUB_type gCUB;

   typedef uint8_t _gPRC_type;
  _gPRC_type gPRC;

   typedef uint8_t _gPOC_type;
  _gPOC_type gPOC;

   typedef uint8_t _gCUC_type;
  _gCUC_type gCUC;

   typedef uint8_t _gPRS_type;
  _gPRS_type gPRS;

   typedef uint8_t _gPOS_type;
  _gPOS_type gPOS;

   typedef uint8_t _gCUS_type;
  _gCUS_type gCUS;





  typedef boost::shared_ptr< ::robotiq_3f_gripper_articulated_msgs::Robotiq3FGripperRobotInput_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::robotiq_3f_gripper_articulated_msgs::Robotiq3FGripperRobotInput_<ContainerAllocator> const> ConstPtr;

}; // struct Robotiq3FGripperRobotInput_

typedef ::robotiq_3f_gripper_articulated_msgs::Robotiq3FGripperRobotInput_<std::allocator<void> > Robotiq3FGripperRobotInput;

typedef boost::shared_ptr< ::robotiq_3f_gripper_articulated_msgs::Robotiq3FGripperRobotInput > Robotiq3FGripperRobotInputPtr;
typedef boost::shared_ptr< ::robotiq_3f_gripper_articulated_msgs::Robotiq3FGripperRobotInput const> Robotiq3FGripperRobotInputConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::robotiq_3f_gripper_articulated_msgs::Robotiq3FGripperRobotInput_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::robotiq_3f_gripper_articulated_msgs::Robotiq3FGripperRobotInput_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace robotiq_3f_gripper_articulated_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'robotiq_3f_gripper_articulated_msgs': ['/home/bhertel/catkin_ws/src/robotiq/robotiq_3f_gripper_articulated_msgs/msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::robotiq_3f_gripper_articulated_msgs::Robotiq3FGripperRobotInput_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::robotiq_3f_gripper_articulated_msgs::Robotiq3FGripperRobotInput_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::robotiq_3f_gripper_articulated_msgs::Robotiq3FGripperRobotInput_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::robotiq_3f_gripper_articulated_msgs::Robotiq3FGripperRobotInput_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::robotiq_3f_gripper_articulated_msgs::Robotiq3FGripperRobotInput_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::robotiq_3f_gripper_articulated_msgs::Robotiq3FGripperRobotInput_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::robotiq_3f_gripper_articulated_msgs::Robotiq3FGripperRobotInput_<ContainerAllocator> >
{
  static const char* value()
  {
    return "4d0701156e580a420c48833f57bc83f3";
  }

  static const char* value(const ::robotiq_3f_gripper_articulated_msgs::Robotiq3FGripperRobotInput_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x4d0701156e580a42ULL;
  static const uint64_t static_value2 = 0x0c48833f57bc83f3ULL;
};

template<class ContainerAllocator>
struct DataType< ::robotiq_3f_gripper_articulated_msgs::Robotiq3FGripperRobotInput_<ContainerAllocator> >
{
  static const char* value()
  {
    return "robotiq_3f_gripper_articulated_msgs/Robotiq3FGripperRobotInput";
  }

  static const char* value(const ::robotiq_3f_gripper_articulated_msgs::Robotiq3FGripperRobotInput_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::robotiq_3f_gripper_articulated_msgs::Robotiq3FGripperRobotInput_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# gACT : Initialization status, echo of the rACT bit (activation bit).\n\
# 0x0 - Gripper reset.\n\
# 0x1 - Gripper activation.\n\
\n\
uint8 gACT\n\
\n\
# gMOD : Operation mode status, echo of the rMOD bits (grasping mode requested).\n\
# 0x00 - Basic mode.\n\
# 0x01 - Pinch mode.\n\
# 0x02 - Wide mode.\n\
# 0x03 - Scissor mode.\n\
\n\
uint8 gMOD\n\
\n\
# gGTO : Action status. echo of the rGTO bit (go to bit).\n\
# 0x0 - Stopped (or performing activation / grasping mode change / automatic release)\n\
# 0x1 - Go to Position Request\n\
\n\
uint8 gGTO\n\
\n\
# gIMC : Gripper status, returns the current status of the Gripper.\n\
# 0x00 - Gripper is in reset (or automatic release) state. See Fault status if Gripper is activated.\n\
# 0x01 - Activation is in progress.\n\
# 0x02 - Mode change is in progress.\n\
# 0x03 - Activation and mode change are completed.\n\
\n\
uint8 gIMC\n\
\n\
# gSTA : Motion status, returns the current motion of the Gripper fingers.\n\
# 0x00 - Gripper is in motion towards requested position (only meaningful if gGTO = 1)\n\
# 0x01 - Gripper is stopped. One or two fingers stopped before requested position\n\
# 0x02 - Gripper is stopped. All fingers stopped before requested position\n\
# 0x03 - Gripper is stopped. All fingers reached requested position\n\
\n\
uint8 gSTA\n\
\n\
# gDTA : Finger A object detection status returns information on possible object contact from finger A.\n\
# 0x00 - Finger A is in motion (only meaningful if gGTO = 1).\n\
# 0x01 - Finger A has stopped due to a contact while opening.\n\
# 0x02 - Finger A has stopped due to a contact while closing.\n\
# 0x03 - Finger A is at requested position.\n\
\n\
uint8 gDTA\n\
\n\
# gDTB : Finger B object detection status returns information on possible object contact from finger B.\n\
# 0x00 - Finger B is in motion (only meaningful if gGTO = 1).\n\
# 0x01 - Finger B has stopped due to a contact while opening.\n\
# 0x02 - Finger B has stopped due to a contact while closing.\n\
# 0x03 - Finger B is at requested position.\n\
\n\
uint8 gDTB\n\
\n\
# gDTC : Finger C object detection status returns information on possible object contact from finger A.\n\
# 0x00 - Finger C is in motion (only meaningful if gGTO = 1).\n\
# 0x01 - Finger C has stopped due to a contact while opening.\n\
# 0x02 - Finger C has stopped due to a contact while closing.\n\
# 0x03 - Finger C is at requested position.\n\
\n\
uint8 gDTC\n\
\n\
# gDTS : Scissor object detection status returns information on possible object contact from scissor.\n\
# 0x00 - Scissor is in motion (only meaningful if gGTO = 1).\n\
# 0x01 - Scissor has stopped due to a contact while opening.\n\
# 0x02 - Scissor has stopped due to a contact while closing.\n\
# 0x03 - Scissor is at requested position.\n\
\n\
uint8 gDTS\n\
\n\
# gFLT : Fault status returns general error messages useful for troubleshooting.\n\
#   0x00 - No fault (fault LED off)\n\
#   Priority faults (fault LED off)\n\
#     0x05 - Action delayed, activation (reactivation) must be completed prior to action.\n\
#     0x06 - Action delayed, mode change must be completed prior to action.\n\
#     0x07 - The activation bit must be set prior to action.\n\
#   Minor faults (fault LED continuous red)\n\
#     0x09 - The communication chip is not ready (may be booting).\n\
#     0x0A - Changing mode fault, interferences detected on Scissor (for less than 20 sec).\n\
#     0x0B - Automatic release in progress.\n\
#   Major faults (fault LED blinking red) - Reset is required\n\
#     0x0D - Activation fault, verify that no interference or other error occurred.\n\
#     0x0E - Changing mode fault, interferences detected on Scissor (for more than 20 sec).\n\
#     0x0F - Automatic release completed. Reset and activation is required.\n\
\n\
uint8 gFLT\n\
\n\
\n\
# gPRA : Echo of the requested position of the Gripper (rPRA),\n\
#   0x00 is minimum position (full opening) and\n\
#   0xFF is maximum position (full closing).\n\
# If commanding the Gripper in\n\
#   individual control mode, gPRA is the echo of finger A,\n\
#   otherwise it is the general position requested to all fingers.\n\
\n\
uint8 gPRA\n\
\n\
# gPOA : Returns the actual position of the Gripper finger A,\n\
#   0x00 is minimum position (full opening) and\n\
#   0xFF is maximum position (full closing).\n\
\n\
uint8 gPOA\n\
\n\
# gCUA : Returns a value that represents the finger A instantaneous current consumption from 0x00 to 0xFF.\n\
\n\
uint8 gCUA\n\
\n\
# gPRB : Echo of the requested position of finger B (rPRB),\n\
#   0x00 is minimum position (full opening) and\n\
#   0xFF is maximum position (full closing).\n\
\n\
uint8 gPRB\n\
\n\
# gPOB : Returns the actual position of the Gripper finger B,\n\
#   0x00 is minimum position (full opening) and\n\
#   0xFF is maximum position (full closing).\n\
\n\
uint8 gPOB\n\
\n\
# gCUB : Returns a value that represents the finger B instantaneous current consumption from 0x00 to 0xFF.\n\
\n\
uint8 gCUB\n\
\n\
# gPRC : Echo of the requested position of finger C (rPRC),\n\
#   0x00 is minimum position (full opening) and\n\
#   0xFF is maximum position (full closing).\n\
\n\
uint8 gPRC\n\
\n\
# gPOC : Returns the actual position of the Gripper finger C,\n\
#   0x00 is minimum position (full opening) and\n\
#   0xFF is maximum position (full closing).\n\
\n\
uint8 gPOC\n\
\n\
# gCUC : Returns a value that represents the finger C instantaneous current consumption from 0x00 to 0xFF.\n\
\n\
uint8 gCUC\n\
\n\
# gPRS : Echo of the requested position of scissor (rPRS),\n\
#   0x00 is minimum position (full opening) and\n\
#   0xFF is maximum position (full closing).\n\
\n\
uint8 gPRS\n\
\n\
# gPOS : Returns the actual position of the Gripper scissor,\n\
#   0x00 is minimum position (full opening) and\n\
#   0xFF is maximum position (full closing).\n\
\n\
uint8 gPOS\n\
\n\
# gCUS : Returns a value that represents the scissor instantaneous current consumption from 0x00 to 0xFF.\n\
#   0x00 is ...\n\
#   0xFF is ...\n\
\n\
uint8 gCUS\n\
";
  }

  static const char* value(const ::robotiq_3f_gripper_articulated_msgs::Robotiq3FGripperRobotInput_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::robotiq_3f_gripper_articulated_msgs::Robotiq3FGripperRobotInput_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.gACT);
      stream.next(m.gMOD);
      stream.next(m.gGTO);
      stream.next(m.gIMC);
      stream.next(m.gSTA);
      stream.next(m.gDTA);
      stream.next(m.gDTB);
      stream.next(m.gDTC);
      stream.next(m.gDTS);
      stream.next(m.gFLT);
      stream.next(m.gPRA);
      stream.next(m.gPOA);
      stream.next(m.gCUA);
      stream.next(m.gPRB);
      stream.next(m.gPOB);
      stream.next(m.gCUB);
      stream.next(m.gPRC);
      stream.next(m.gPOC);
      stream.next(m.gCUC);
      stream.next(m.gPRS);
      stream.next(m.gPOS);
      stream.next(m.gCUS);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Robotiq3FGripperRobotInput_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::robotiq_3f_gripper_articulated_msgs::Robotiq3FGripperRobotInput_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::robotiq_3f_gripper_articulated_msgs::Robotiq3FGripperRobotInput_<ContainerAllocator>& v)
  {
    s << indent << "gACT: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.gACT);
    s << indent << "gMOD: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.gMOD);
    s << indent << "gGTO: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.gGTO);
    s << indent << "gIMC: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.gIMC);
    s << indent << "gSTA: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.gSTA);
    s << indent << "gDTA: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.gDTA);
    s << indent << "gDTB: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.gDTB);
    s << indent << "gDTC: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.gDTC);
    s << indent << "gDTS: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.gDTS);
    s << indent << "gFLT: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.gFLT);
    s << indent << "gPRA: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.gPRA);
    s << indent << "gPOA: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.gPOA);
    s << indent << "gCUA: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.gCUA);
    s << indent << "gPRB: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.gPRB);
    s << indent << "gPOB: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.gPOB);
    s << indent << "gCUB: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.gCUB);
    s << indent << "gPRC: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.gPRC);
    s << indent << "gPOC: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.gPOC);
    s << indent << "gCUC: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.gCUC);
    s << indent << "gPRS: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.gPRS);
    s << indent << "gPOS: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.gPOS);
    s << indent << "gCUS: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.gCUS);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROBOTIQ_3F_GRIPPER_ARTICULATED_MSGS_MESSAGE_ROBOTIQ3FGRIPPERROBOTINPUT_H
