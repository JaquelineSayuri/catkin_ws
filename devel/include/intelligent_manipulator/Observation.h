// Generated by gencpp from file intelligent_manipulator/Observation.msg
// DO NOT EDIT!


#ifndef INTELLIGENT_MANIPULATOR_MESSAGE_OBSERVATION_H
#define INTELLIGENT_MANIPULATOR_MESSAGE_OBSERVATION_H


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
struct Observation_
{
  typedef Observation_<ContainerAllocator> Type;

  Observation_()
    : observation()  {
    }
  Observation_(const ContainerAllocator& _alloc)
    : observation(_alloc)  {
  (void)_alloc;
    }



   typedef std::vector<double, typename ContainerAllocator::template rebind<double>::other >  _observation_type;
  _observation_type observation;





  typedef boost::shared_ptr< ::intelligent_manipulator::Observation_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::intelligent_manipulator::Observation_<ContainerAllocator> const> ConstPtr;

}; // struct Observation_

typedef ::intelligent_manipulator::Observation_<std::allocator<void> > Observation;

typedef boost::shared_ptr< ::intelligent_manipulator::Observation > ObservationPtr;
typedef boost::shared_ptr< ::intelligent_manipulator::Observation const> ObservationConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::intelligent_manipulator::Observation_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::intelligent_manipulator::Observation_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::intelligent_manipulator::Observation_<ContainerAllocator1> & lhs, const ::intelligent_manipulator::Observation_<ContainerAllocator2> & rhs)
{
  return lhs.observation == rhs.observation;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::intelligent_manipulator::Observation_<ContainerAllocator1> & lhs, const ::intelligent_manipulator::Observation_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace intelligent_manipulator

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::intelligent_manipulator::Observation_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::intelligent_manipulator::Observation_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::intelligent_manipulator::Observation_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::intelligent_manipulator::Observation_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::intelligent_manipulator::Observation_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::intelligent_manipulator::Observation_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::intelligent_manipulator::Observation_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bbbad3e35ac69edda7d7576e4d0cda1c";
  }

  static const char* value(const ::intelligent_manipulator::Observation_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xbbbad3e35ac69eddULL;
  static const uint64_t static_value2 = 0xa7d7576e4d0cda1cULL;
};

template<class ContainerAllocator>
struct DataType< ::intelligent_manipulator::Observation_<ContainerAllocator> >
{
  static const char* value()
  {
    return "intelligent_manipulator/Observation";
  }

  static const char* value(const ::intelligent_manipulator::Observation_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::intelligent_manipulator::Observation_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float64[] observation\n"
;
  }

  static const char* value(const ::intelligent_manipulator::Observation_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::intelligent_manipulator::Observation_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.observation);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Observation_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::intelligent_manipulator::Observation_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::intelligent_manipulator::Observation_<ContainerAllocator>& v)
  {
    s << indent << "observation[]" << std::endl;
    for (size_t i = 0; i < v.observation.size(); ++i)
    {
      s << indent << "  observation[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.observation[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // INTELLIGENT_MANIPULATOR_MESSAGE_OBSERVATION_H
