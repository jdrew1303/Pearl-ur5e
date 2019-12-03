// Generated by gencpp from file dmp/DMPTraj.msg
// DO NOT EDIT!


#ifndef DMP_MESSAGE_DMPTRAJ_H
#define DMP_MESSAGE_DMPTRAJ_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <dmp/DMPPoint.h>

namespace dmp
{
template <class ContainerAllocator>
struct DMPTraj_
{
  typedef DMPTraj_<ContainerAllocator> Type;

  DMPTraj_()
    : points()
    , times()  {
    }
  DMPTraj_(const ContainerAllocator& _alloc)
    : points(_alloc)
    , times(_alloc)  {
  (void)_alloc;
    }



   typedef std::vector< ::dmp::DMPPoint_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::dmp::DMPPoint_<ContainerAllocator> >::other >  _points_type;
  _points_type points;

   typedef std::vector<double, typename ContainerAllocator::template rebind<double>::other >  _times_type;
  _times_type times;





  typedef boost::shared_ptr< ::dmp::DMPTraj_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::dmp::DMPTraj_<ContainerAllocator> const> ConstPtr;

}; // struct DMPTraj_

typedef ::dmp::DMPTraj_<std::allocator<void> > DMPTraj;

typedef boost::shared_ptr< ::dmp::DMPTraj > DMPTrajPtr;
typedef boost::shared_ptr< ::dmp::DMPTraj const> DMPTrajConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::dmp::DMPTraj_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::dmp::DMPTraj_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace dmp

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'dmp': ['/home/bhertel/catkin_ws/src/dmp/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::dmp::DMPTraj_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::dmp::DMPTraj_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dmp::DMPTraj_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dmp::DMPTraj_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dmp::DMPTraj_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dmp::DMPTraj_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::dmp::DMPTraj_<ContainerAllocator> >
{
  static const char* value()
  {
    return "1d088d86ab60cf6a2671bc3c0e99932b";
  }

  static const char* value(const ::dmp::DMPTraj_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x1d088d86ab60cf6aULL;
  static const uint64_t static_value2 = 0x2671bc3c0e99932bULL;
};

template<class ContainerAllocator>
struct DataType< ::dmp::DMPTraj_<ContainerAllocator> >
{
  static const char* value()
  {
    return "dmp/DMPTraj";
  }

  static const char* value(const ::dmp::DMPTraj_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::dmp::DMPTraj_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# points and times should be the same length\n\
DMPPoint[] points\n\
\n\
# Times of observations, in seconds, starting at zero\n\
float64[] times\n\
\n\
\n\
\n\
================================================================================\n\
MSG: dmp/DMPPoint\n\
# Positions and velocities of DOFs\n\
#Velocity is only used for movement plans, not for giving demonstrations.\n\
float64[] positions\n\
float64[] velocities\n\
\n\
\n\
";
  }

  static const char* value(const ::dmp::DMPTraj_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::dmp::DMPTraj_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.points);
      stream.next(m.times);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct DMPTraj_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::dmp::DMPTraj_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::dmp::DMPTraj_<ContainerAllocator>& v)
  {
    s << indent << "points[]" << std::endl;
    for (size_t i = 0; i < v.points.size(); ++i)
    {
      s << indent << "  points[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::dmp::DMPPoint_<ContainerAllocator> >::stream(s, indent + "    ", v.points[i]);
    }
    s << indent << "times[]" << std::endl;
    for (size_t i = 0; i < v.times.size(); ++i)
    {
      s << indent << "  times[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.times[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // DMP_MESSAGE_DMPTRAJ_H