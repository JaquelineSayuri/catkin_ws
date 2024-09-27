// Generated by gencpp from file open_manipulator_msgs/SetActuatorStateRequest.msg
// DO NOT EDIT!


#ifndef OPEN_MANIPULATOR_MSGS_MESSAGE_SETACTUATORSTATEREQUEST_H
#define OPEN_MANIPULATOR_MSGS_MESSAGE_SETACTUATORSTATEREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace open_manipulator_msgs
{
template <class ContainerAllocator>
struct SetActuatorStateRequest_
{
  typedef SetActuatorStateRequest_<ContainerAllocator> Type;

  SetActuatorStateRequest_()
    : set_actuator_state(false)  {
    }
  SetActuatorStateRequest_(const ContainerAllocator& _alloc)
    : set_actuator_state(false)  {
  (void)_alloc;
    }



   typedef uint8_t _set_actuator_state_type;
  _set_actuator_state_type set_actuator_state;





  typedef boost::shared_ptr< ::open_manipulator_msgs::SetActuatorStateRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::open_manipulator_msgs::SetActuatorStateRequest_<ContainerAllocator> const> ConstPtr;

}; // struct SetActuatorStateRequest_

typedef ::open_manipulator_msgs::SetActuatorStateRequest_<std::allocator<void> > SetActuatorStateRequest;

typedef boost::shared_ptr< ::open_manipulator_msgs::SetActuatorStateRequest > SetActuatorStateRequestPtr;
typedef boost::shared_ptr< ::open_manipulator_msgs::SetActuatorStateRequest const> SetActuatorStateRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::open_manipulator_msgs::SetActuatorStateRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::open_manipulator_msgs::SetActuatorStateRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::open_manipulator_msgs::SetActuatorStateRequest_<ContainerAllocator1> & lhs, const ::open_manipulator_msgs::SetActuatorStateRequest_<ContainerAllocator2> & rhs)
{
  return lhs.set_actuator_state == rhs.set_actuator_state;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::open_manipulator_msgs::SetActuatorStateRequest_<ContainerAllocator1> & lhs, const ::open_manipulator_msgs::SetActuatorStateRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace open_manipulator_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::open_manipulator_msgs::SetActuatorStateRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::open_manipulator_msgs::SetActuatorStateRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::open_manipulator_msgs::SetActuatorStateRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::open_manipulator_msgs::SetActuatorStateRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::open_manipulator_msgs::SetActuatorStateRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::open_manipulator_msgs::SetActuatorStateRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::open_manipulator_msgs::SetActuatorStateRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "0a8a1fa84fab126c7567fbb489a23ea5";
  }

  static const char* value(const ::open_manipulator_msgs::SetActuatorStateRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x0a8a1fa84fab126cULL;
  static const uint64_t static_value2 = 0x7567fbb489a23ea5ULL;
};

template<class ContainerAllocator>
struct DataType< ::open_manipulator_msgs::SetActuatorStateRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "open_manipulator_msgs/SetActuatorStateRequest";
  }

  static const char* value(const ::open_manipulator_msgs::SetActuatorStateRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::open_manipulator_msgs::SetActuatorStateRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bool set_actuator_state\n"
;
  }

  static const char* value(const ::open_manipulator_msgs::SetActuatorStateRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::open_manipulator_msgs::SetActuatorStateRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.set_actuator_state);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SetActuatorStateRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::open_manipulator_msgs::SetActuatorStateRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::open_manipulator_msgs::SetActuatorStateRequest_<ContainerAllocator>& v)
  {
    s << indent << "set_actuator_state: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.set_actuator_state);
  }
};

} // namespace message_operations
} // namespace ros

#endif // OPEN_MANIPULATOR_MSGS_MESSAGE_SETACTUATORSTATEREQUEST_H
