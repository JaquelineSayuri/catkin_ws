// Generated by gencpp from file object_msgs/ObjectInfoResponse.msg
// DO NOT EDIT!


#ifndef OBJECT_MSGS_MESSAGE_OBJECTINFORESPONSE_H
#define OBJECT_MSGS_MESSAGE_OBJECTINFORESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <object_msgs/Object.h>

namespace object_msgs
{
template <class ContainerAllocator>
struct ObjectInfoResponse_
{
  typedef ObjectInfoResponse_<ContainerAllocator> Type;

  ObjectInfoResponse_()
    : success(false)
    , object()
    , error_code(0)  {
    }
  ObjectInfoResponse_(const ContainerAllocator& _alloc)
    : success(false)
    , object(_alloc)
    , error_code(0)  {
  (void)_alloc;
    }



   typedef uint8_t _success_type;
  _success_type success;

   typedef  ::object_msgs::Object_<ContainerAllocator>  _object_type;
  _object_type object;

   typedef int8_t _error_code_type;
  _error_code_type error_code;



// reducing the odds to have name collisions with Windows.h 
#if defined(_WIN32) && defined(NO_ERROR)
  #undef NO_ERROR
#endif
#if defined(_WIN32) && defined(OBJECT_NOT_FOUND)
  #undef OBJECT_NOT_FOUND
#endif
#if defined(_WIN32) && defined(OTHER_ERROR)
  #undef OTHER_ERROR
#endif

  enum {
    NO_ERROR = 0,
    OBJECT_NOT_FOUND = 1,
    OTHER_ERROR = 2,
  };


  typedef boost::shared_ptr< ::object_msgs::ObjectInfoResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::object_msgs::ObjectInfoResponse_<ContainerAllocator> const> ConstPtr;

}; // struct ObjectInfoResponse_

typedef ::object_msgs::ObjectInfoResponse_<std::allocator<void> > ObjectInfoResponse;

typedef boost::shared_ptr< ::object_msgs::ObjectInfoResponse > ObjectInfoResponsePtr;
typedef boost::shared_ptr< ::object_msgs::ObjectInfoResponse const> ObjectInfoResponseConstPtr;

// constants requiring out of line definition

   

   

   



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::object_msgs::ObjectInfoResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::object_msgs::ObjectInfoResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::object_msgs::ObjectInfoResponse_<ContainerAllocator1> & lhs, const ::object_msgs::ObjectInfoResponse_<ContainerAllocator2> & rhs)
{
  return lhs.success == rhs.success &&
    lhs.object == rhs.object &&
    lhs.error_code == rhs.error_code;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::object_msgs::ObjectInfoResponse_<ContainerAllocator1> & lhs, const ::object_msgs::ObjectInfoResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace object_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::object_msgs::ObjectInfoResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::object_msgs::ObjectInfoResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::object_msgs::ObjectInfoResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::object_msgs::ObjectInfoResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::object_msgs::ObjectInfoResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::object_msgs::ObjectInfoResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::object_msgs::ObjectInfoResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "a9fe6ed8f44295e2c52c2814c09b1b79";
  }

  static const char* value(const ::object_msgs::ObjectInfoResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xa9fe6ed8f44295e2ULL;
  static const uint64_t static_value2 = 0xc52c2814c09b1b79ULL;
};

template<class ContainerAllocator>
struct DataType< ::object_msgs::ObjectInfoResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "object_msgs/ObjectInfoResponse";
  }

  static const char* value(const ::object_msgs::ObjectInfoResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::object_msgs::ObjectInfoResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n"
"# true if object exists and information is\n"
"# stored in field 'object'. If false, the\n"
"# error_code contains more information about the error.\n"
"bool success\n"
"\n"
"# information about the object\n"
"Object object\n"
"\n"
"# error code if success is false\n"
"byte error_code\n"
"\n"
"byte NO_ERROR=0\n"
"byte OBJECT_NOT_FOUND=1\n"
"byte OTHER_ERROR=2\n"
"\n"
"\n"
"================================================================================\n"
"MSG: object_msgs/Object\n"
"# a header, used for interpreting the poses\n"
"Header header\n"
"\n"
"# the name of the object. This should usually\n"
"# coincide with the /tf frame of the base/origin\n"
"# of the object, though this is no mandatory\n"
"# requirement.\n"
"string name\n"
"\n"
"# If known: The object type in a database of known objects\n"
"object_recognition_msgs/ObjectType type\n"
"\n"
"# If the model is made up of primitives:\n"
"# Solid geometric primitives\n"
"shape_msgs/SolidPrimitive[] primitives\n"
"geometry_msgs/Pose[] primitive_poses\n"
"\n"
"# If the model is made up of meshes:\n"
"# The model meshes\n"
"shape_msgs/Mesh[] meshes\n"
"geometry_msgs/Pose[] mesh_poses\n"
"\n"
"# If known: bounding plane\n"
"shape_msgs/Plane[] planes\n"
"geometry_msgs/Pose[] plane_poses\n"
"\n"
"# Index into the primitive_poses to the\n"
"# pose which is considered to be the\n"
"# object's root / origin. Can also be\n"
"# set to constants ORIGIN_AVERAGE,\n"
"# ORIGIN_UNDEFINED or ORIGIN_CUSTOM.\n"
"int32 primitive_origin\n"
"\n"
"# Index into the mesh_poses to the\n"
"# pose which is considered to be the\n"
"# object's root / origin. Can also be\n"
"# set to constants ORIGIN_AVERAGE,\n"
"# ORIGIN_UNDEFINED or ORIGIN_CUSTOM.\n"
"int32 mesh_origin\n"
"\n"
"# If 'mesh_origin' or 'primitive_origin'\n"
"# are set to ORIGIN_CUSTOM, this field\n"
"# contains the origin of the overall object.\n"
"geometry_msgs/Pose origin\n"
"\n"
"# Information in the message, either SHAPE or POSE\n"
"byte content\n"
"\n"
"# For field 'content':\n"
"# Message contains the shape(s) of the object including poses\n"
"byte SHAPE=0\n"
"\n"
"# For field 'content':\n"
"# Message contains only the pose of the primitives,\n"
"# i.e. only *_poses will be with values.\n"
"byte POSE=1\n"
"\n"
"# For fields 'mesh_origin' and 'primitives_origin':\n"
"# the root/origin of the object is the\n"
"# average of all poses.\n"
"# Because the average of several quaternions\n"
"# can only be determined approximately when\n"
"# the quaternions are close together, this\n"
"# setting requires at least the orientation part\n"
"# of the field 'origin' to be set in addition.\n"
"int32 ORIGIN_AVERAGE=-1\n"
"\n"
"# For fields 'mesh_origin' and 'primitives_origin':\n"
"# The origin of the object cannot be defined by this\n"
"# set of poses.\n"
"int32 ORIGIN_UNDEFINED=-2\n"
"\n"
"# For fields 'mesh_origin' and 'primitives_origin':\n"
"# The origin is given in the custom field 'origin' \n"
"int32 ORIGIN_CUSTOM=-3\n"
"\n"
"================================================================================\n"
"MSG: std_msgs/Header\n"
"# Standard metadata for higher-level stamped data types.\n"
"# This is generally used to communicate timestamped data \n"
"# in a particular coordinate frame.\n"
"# \n"
"# sequence ID: consecutively increasing ID \n"
"uint32 seq\n"
"#Two-integer timestamp that is expressed as:\n"
"# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n"
"# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n"
"# time-handling sugar is provided by the client library\n"
"time stamp\n"
"#Frame this data is associated with\n"
"string frame_id\n"
"\n"
"================================================================================\n"
"MSG: object_recognition_msgs/ObjectType\n"
"################################################## OBJECT ID #########################################################\n"
"\n"
"# Contains information about the type of a found object. Those two sets of parameters together uniquely define an\n"
"# object\n"
"\n"
"# The key of the found object: the unique identifier in the given db\n"
"string key\n"
"\n"
"# The db parameters stored as a JSON/compressed YAML string. An object id does not make sense without the corresponding\n"
"# database. E.g., in object_recognition, it can look like: \"{'type':'CouchDB', 'root':'http://localhost'}\"\n"
"# There is no conventional format for those parameters and it's nice to keep that flexibility.\n"
"# The object_recognition_core as a generic DB type that can read those fields\n"
"# Current examples:\n"
"# For CouchDB:\n"
"#   type: 'CouchDB'\n"
"#   root: 'http://localhost:5984'\n"
"#   collection: 'object_recognition'\n"
"# For SQL household database:\n"
"#   type: 'SqlHousehold'\n"
"#   host: 'wgs36'\n"
"#   port: 5432\n"
"#   user: 'willow'\n"
"#   password: 'willow'\n"
"#   name: 'household_objects'\n"
"#   module: 'tabletop'\n"
"string db\n"
"\n"
"================================================================================\n"
"MSG: shape_msgs/SolidPrimitive\n"
"# Define box, sphere, cylinder, cone \n"
"# All shapes are defined to have their bounding boxes centered around 0,0,0.\n"
"\n"
"uint8 BOX=1\n"
"uint8 SPHERE=2\n"
"uint8 CYLINDER=3\n"
"uint8 CONE=4\n"
"\n"
"# The type of the shape\n"
"uint8 type\n"
"\n"
"\n"
"# The dimensions of the shape\n"
"float64[] dimensions\n"
"\n"
"# The meaning of the shape dimensions: each constant defines the index in the 'dimensions' array\n"
"\n"
"# For the BOX type, the X, Y, and Z dimensions are the length of the corresponding\n"
"# sides of the box.\n"
"uint8 BOX_X=0\n"
"uint8 BOX_Y=1\n"
"uint8 BOX_Z=2\n"
"\n"
"\n"
"# For the SPHERE type, only one component is used, and it gives the radius of\n"
"# the sphere.\n"
"uint8 SPHERE_RADIUS=0\n"
"\n"
"\n"
"# For the CYLINDER and CONE types, the center line is oriented along\n"
"# the Z axis.  Therefore the CYLINDER_HEIGHT (CONE_HEIGHT) component\n"
"# of dimensions gives the height of the cylinder (cone).  The\n"
"# CYLINDER_RADIUS (CONE_RADIUS) component of dimensions gives the\n"
"# radius of the base of the cylinder (cone).  Cone and cylinder\n"
"# primitives are defined to be circular. The tip of the cone is\n"
"# pointing up, along +Z axis.\n"
"\n"
"uint8 CYLINDER_HEIGHT=0\n"
"uint8 CYLINDER_RADIUS=1\n"
"\n"
"uint8 CONE_HEIGHT=0\n"
"uint8 CONE_RADIUS=1\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Pose\n"
"# A representation of pose in free space, composed of position and orientation. \n"
"Point position\n"
"Quaternion orientation\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Point\n"
"# This contains the position of a point in free space\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Quaternion\n"
"# This represents an orientation in free space in quaternion form.\n"
"\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
"float64 w\n"
"\n"
"================================================================================\n"
"MSG: shape_msgs/Mesh\n"
"# Definition of a mesh\n"
"\n"
"# list of triangles; the index values refer to positions in vertices[]\n"
"MeshTriangle[] triangles\n"
"\n"
"# the actual vertices that make up the mesh\n"
"geometry_msgs/Point[] vertices\n"
"\n"
"================================================================================\n"
"MSG: shape_msgs/MeshTriangle\n"
"# Definition of a triangle's vertices\n"
"uint32[3] vertex_indices\n"
"\n"
"================================================================================\n"
"MSG: shape_msgs/Plane\n"
"# Representation of a plane, using the plane equation ax + by + cz + d = 0\n"
"\n"
"# a := coef[0]\n"
"# b := coef[1]\n"
"# c := coef[2]\n"
"# d := coef[3]\n"
"\n"
"float64[4] coef\n"
;
  }

  static const char* value(const ::object_msgs::ObjectInfoResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::object_msgs::ObjectInfoResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.success);
      stream.next(m.object);
      stream.next(m.error_code);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ObjectInfoResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::object_msgs::ObjectInfoResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::object_msgs::ObjectInfoResponse_<ContainerAllocator>& v)
  {
    s << indent << "success: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.success);
    s << indent << "object: ";
    s << std::endl;
    Printer< ::object_msgs::Object_<ContainerAllocator> >::stream(s, indent + "  ", v.object);
    s << indent << "error_code: ";
    Printer<int8_t>::stream(s, indent + "  ", v.error_code);
  }
};

} // namespace message_operations
} // namespace ros

#endif // OBJECT_MSGS_MESSAGE_OBJECTINFORESPONSE_H
