// Generated by gencpp from file autosense_msgs/TrackingObjectArray.msg
// DO NOT EDIT!


#ifndef AUTOSENSE_MSGS_MESSAGE_TRACKINGOBJECTARRAY_H
#define AUTOSENSE_MSGS_MESSAGE_TRACKINGOBJECTARRAY_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <sensor_msgs/PointCloud2.h>
#include <geometry_msgs/Point.h>
#include <geometry_msgs/Point.h>
#include <geometry_msgs/Point.h>
#include <geometry_msgs/Point.h>

namespace autosense_msgs
{
template <class ContainerAllocator>
struct TrackingObjectArray_
{
  typedef TrackingObjectArray_<ContainerAllocator> Type;

  TrackingObjectArray_()
    : header()
    , ids()
    , segments()
    , sizes()
    , positions()
    , directions()
    , velocities()  {
    }
  TrackingObjectArray_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , ids(_alloc)
    , segments(_alloc)
    , sizes(_alloc)
    , positions(_alloc)
    , directions(_alloc)
    , velocities(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef std::vector<uint32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint32_t>> _ids_type;
  _ids_type ids;

   typedef std::vector< ::sensor_msgs::PointCloud2_<ContainerAllocator> , typename std::allocator_traits<ContainerAllocator>::template rebind_alloc< ::sensor_msgs::PointCloud2_<ContainerAllocator> >> _segments_type;
  _segments_type segments;

   typedef std::vector< ::geometry_msgs::Point_<ContainerAllocator> , typename std::allocator_traits<ContainerAllocator>::template rebind_alloc< ::geometry_msgs::Point_<ContainerAllocator> >> _sizes_type;
  _sizes_type sizes;

   typedef std::vector< ::geometry_msgs::Point_<ContainerAllocator> , typename std::allocator_traits<ContainerAllocator>::template rebind_alloc< ::geometry_msgs::Point_<ContainerAllocator> >> _positions_type;
  _positions_type positions;

   typedef std::vector< ::geometry_msgs::Point_<ContainerAllocator> , typename std::allocator_traits<ContainerAllocator>::template rebind_alloc< ::geometry_msgs::Point_<ContainerAllocator> >> _directions_type;
  _directions_type directions;

   typedef std::vector< ::geometry_msgs::Point_<ContainerAllocator> , typename std::allocator_traits<ContainerAllocator>::template rebind_alloc< ::geometry_msgs::Point_<ContainerAllocator> >> _velocities_type;
  _velocities_type velocities;





  typedef boost::shared_ptr< ::autosense_msgs::TrackingObjectArray_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::autosense_msgs::TrackingObjectArray_<ContainerAllocator> const> ConstPtr;

}; // struct TrackingObjectArray_

typedef ::autosense_msgs::TrackingObjectArray_<std::allocator<void> > TrackingObjectArray;

typedef boost::shared_ptr< ::autosense_msgs::TrackingObjectArray > TrackingObjectArrayPtr;
typedef boost::shared_ptr< ::autosense_msgs::TrackingObjectArray const> TrackingObjectArrayConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::autosense_msgs::TrackingObjectArray_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::autosense_msgs::TrackingObjectArray_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::autosense_msgs::TrackingObjectArray_<ContainerAllocator1> & lhs, const ::autosense_msgs::TrackingObjectArray_<ContainerAllocator2> & rhs)
{
  return lhs.header == rhs.header &&
    lhs.ids == rhs.ids &&
    lhs.segments == rhs.segments &&
    lhs.sizes == rhs.sizes &&
    lhs.positions == rhs.positions &&
    lhs.directions == rhs.directions &&
    lhs.velocities == rhs.velocities;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::autosense_msgs::TrackingObjectArray_<ContainerAllocator1> & lhs, const ::autosense_msgs::TrackingObjectArray_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace autosense_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::autosense_msgs::TrackingObjectArray_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::autosense_msgs::TrackingObjectArray_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::autosense_msgs::TrackingObjectArray_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::autosense_msgs::TrackingObjectArray_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::autosense_msgs::TrackingObjectArray_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::autosense_msgs::TrackingObjectArray_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::autosense_msgs::TrackingObjectArray_<ContainerAllocator> >
{
  static const char* value()
  {
    return "58293c548ad89b5f0072e8120a1fdc02";
  }

  static const char* value(const ::autosense_msgs::TrackingObjectArray_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x58293c548ad89b5fULL;
  static const uint64_t static_value2 = 0x0072e8120a1fdc02ULL;
};

template<class ContainerAllocator>
struct DataType< ::autosense_msgs::TrackingObjectArray_<ContainerAllocator> >
{
  static const char* value()
  {
    return "autosense_msgs/TrackingObjectArray";
  }

  static const char* value(const ::autosense_msgs::TrackingObjectArray_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::autosense_msgs::TrackingObjectArray_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header\n"
"# tracker id, all data relates in order\n"
"uint32[] ids\n"
"sensor_msgs/PointCloud2[] segments\n"
"geometry_msgs/Point[] sizes\n"
"geometry_msgs/Point[] positions\n"
"geometry_msgs/Point[] directions\n"
"geometry_msgs/Point[] velocities\n"
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
"MSG: sensor_msgs/PointCloud2\n"
"# This message holds a collection of N-dimensional points, which may\n"
"# contain additional information such as normals, intensity, etc. The\n"
"# point data is stored as a binary blob, its layout described by the\n"
"# contents of the \"fields\" array.\n"
"\n"
"# The point cloud data may be organized 2d (image-like) or 1d\n"
"# (unordered). Point clouds organized as 2d images may be produced by\n"
"# camera depth sensors such as stereo or time-of-flight.\n"
"\n"
"# Time of sensor data acquisition, and the coordinate frame ID (for 3d\n"
"# points).\n"
"Header header\n"
"\n"
"# 2D structure of the point cloud. If the cloud is unordered, height is\n"
"# 1 and width is the length of the point cloud.\n"
"uint32 height\n"
"uint32 width\n"
"\n"
"# Describes the channels and their layout in the binary data blob.\n"
"PointField[] fields\n"
"\n"
"bool    is_bigendian # Is this data bigendian?\n"
"uint32  point_step   # Length of a point in bytes\n"
"uint32  row_step     # Length of a row in bytes\n"
"uint8[] data         # Actual point data, size is (row_step*height)\n"
"\n"
"bool is_dense        # True if there are no invalid points\n"
"\n"
"================================================================================\n"
"MSG: sensor_msgs/PointField\n"
"# This message holds the description of one point entry in the\n"
"# PointCloud2 message format.\n"
"uint8 INT8    = 1\n"
"uint8 UINT8   = 2\n"
"uint8 INT16   = 3\n"
"uint8 UINT16  = 4\n"
"uint8 INT32   = 5\n"
"uint8 UINT32  = 6\n"
"uint8 FLOAT32 = 7\n"
"uint8 FLOAT64 = 8\n"
"\n"
"string name      # Name of field\n"
"uint32 offset    # Offset from start of point struct\n"
"uint8  datatype  # Datatype enumeration, see above\n"
"uint32 count     # How many elements in the field\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Point\n"
"# This contains the position of a point in free space\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
;
  }

  static const char* value(const ::autosense_msgs::TrackingObjectArray_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::autosense_msgs::TrackingObjectArray_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.ids);
      stream.next(m.segments);
      stream.next(m.sizes);
      stream.next(m.positions);
      stream.next(m.directions);
      stream.next(m.velocities);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct TrackingObjectArray_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::autosense_msgs::TrackingObjectArray_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::autosense_msgs::TrackingObjectArray_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "ids[]" << std::endl;
    for (size_t i = 0; i < v.ids.size(); ++i)
    {
      s << indent << "  ids[" << i << "]: ";
      Printer<uint32_t>::stream(s, indent + "  ", v.ids[i]);
    }
    s << indent << "segments[]" << std::endl;
    for (size_t i = 0; i < v.segments.size(); ++i)
    {
      s << indent << "  segments[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::sensor_msgs::PointCloud2_<ContainerAllocator> >::stream(s, indent + "    ", v.segments[i]);
    }
    s << indent << "sizes[]" << std::endl;
    for (size_t i = 0; i < v.sizes.size(); ++i)
    {
      s << indent << "  sizes[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::geometry_msgs::Point_<ContainerAllocator> >::stream(s, indent + "    ", v.sizes[i]);
    }
    s << indent << "positions[]" << std::endl;
    for (size_t i = 0; i < v.positions.size(); ++i)
    {
      s << indent << "  positions[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::geometry_msgs::Point_<ContainerAllocator> >::stream(s, indent + "    ", v.positions[i]);
    }
    s << indent << "directions[]" << std::endl;
    for (size_t i = 0; i < v.directions.size(); ++i)
    {
      s << indent << "  directions[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::geometry_msgs::Point_<ContainerAllocator> >::stream(s, indent + "    ", v.directions[i]);
    }
    s << indent << "velocities[]" << std::endl;
    for (size_t i = 0; i < v.velocities.size(); ++i)
    {
      s << indent << "  velocities[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::geometry_msgs::Point_<ContainerAllocator> >::stream(s, indent + "    ", v.velocities[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // AUTOSENSE_MSGS_MESSAGE_TRACKINGOBJECTARRAY_H
