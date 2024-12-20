// Generated by gencpp from file intelligent_manipulator/Position.msg
// DO NOT EDIT!


#ifndef INTELLIGENT_MANIPULATOR_MESSAGE_POSITION_H
#define INTELLIGENT_MANIPULATOR_MESSAGE_POSITION_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace intelligent_manipulator
{
template <class ContainerAllocator>
struct Position_
{
  typedef Position_<ContainerAllocator> Type;

  Position_()
    : position()  {
    }
  Position_(const ContainerAllocator& _alloc)
    : position(_alloc)  {
  (void)_alloc;
    }



   typedef std::vector<double, typename ContainerAllocator::template rebind<double>::other >  _position_type;
  _position_type position;





  typedef boost::shared_ptr< ::intelligent_manipulator::Position_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::intelligent_manipulator::Position_<ContainerAllocator> const> ConstPtr;

}; // struct Position_

typedef ::intelligent_manipulator::Position_<std::allocator<void> > Position;

typedef boost::shared_ptr< ::intelligent_manipulator::Position > PositionPtr;
typedef boost::shared_ptr< ::intelligent_manipulator::Position const> PositionConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::intelligent_manipulator::Position_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::intelligent_manipulator::Position_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::intelligent_manipulator::Position_<ContainerAllocator1> & lhs, const ::intelligent_manipulator::Position_<ContainerAllocator2> & rhs)
{
  return lhs.position == rhs.position;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::intelligent_manipulator::Position_<ContainerAllocator1> & lhs, const ::intelligent_manipulator::Position_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace intelligent_manipulator

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::intelligent_manipulator::Position_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::intelligent_manipulator::Position_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::intelligent_manipulator::Position_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::intelligent_manipulator::Position_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::intelligent_manipulator::Position_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::intelligent_manipulator::Position_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::intelligent_manipulator::Position_<ContainerAllocator> >
{
  static const char* value()
  {
    return "50410efb3480c63b23b8b5fe2bea331a";
  }

  static const char* value(const ::intelligent_manipulator::Position_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x50410efb3480c63bULL;
  static const uint64_t static_value2 = 0x23b8b5fe2bea331aULL;
};

template<class ContainerAllocator>
struct DataType< ::intelligent_manipulator::Position_<ContainerAllocator> >
{
  static const char* value()
  {
    return "intelligent_manipulator/Position";
  }

  static const char* value(const ::intelligent_manipulator::Position_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::intelligent_manipulator::Position_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float64[] position\n"
;
  }

  static const char* value(const ::intelligent_manipulator::Position_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::intelligent_manipulator::Position_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.position);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Position_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::intelligent_manipulator::Position_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::intelligent_manipulator::Position_<ContainerAllocator>& v)
  {
    s << indent << "position[]" << std::endl;
    for (size_t i = 0; i < v.position.size(); ++i)
    {
      s << indent << "  position[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.position[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // INTELLIGENT_MANIPULATOR_MESSAGE_POSITION_H
