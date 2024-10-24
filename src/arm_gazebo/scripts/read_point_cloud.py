#!/usr/bin/env python

import rospy
from sensor_msgs.msg import PointCloud2
import sensor_msgs.point_cloud2 as pc2

def point_cloud_callback(msg):
    # Convert the ROS PointCloud2 message to a generator of points
    point_cloud = pc2.read_points(msg, field_names=("x", "y", "z"), skip_nans=True)

    # Iterate through the points and process them
    for point in point_cloud:
        x, y, z = point[:3]
        rospy.loginfo("Point: x=%.2f, y=%.2f, z=%.2f", x, y, z)
        # Process the point cloud data here (e.g., filtering, clustering, etc.)

def main():
    rospy.init_node('point_cloud_subscriber')

    # Subscribe to the point cloud topic
    rospy.Subscriber("/camera/depth/points", PointCloud2, point_cloud_callback)

    rospy.spin()

if __name__ == "__main__":
    main()
