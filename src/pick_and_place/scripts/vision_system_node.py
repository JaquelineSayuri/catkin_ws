#!/usr/bin/env python

import rospy
from std_msgs.msg import String
from sensor_msgs.msg import PointCloud2
import sensor_msgs.point_cloud2 as pc2

class VisionSystem:
    """
    Docstring: A brief description of the class.
    """

    def __init__(self):#, arg1, arg2):
        """
        Constructor: Initializes the object's attributes.
        """
        self.point_cloud = None
        print("Setting point cloud:", self.point_cloud)

    def get_rgb_image(self):#, arg1, arg2):
        """
        Method: Performs a specific action on the object.
        """
        print("Getting RGB image")
        pass

    def get_depth_image(self):#, arg1, arg2):
        """
        Method: Performs another action on the object.
        """
        print("Getting depth image")
        pass

    def get_point_cloud(self, point_cloud):
        """
        Method: Performs another action on the object.
        """
        print("Getting point cloud")
        self.point_cloud = point_cloud
        #print('first point:')
        print(self.point_cloud)
        pass


class VisionSystemNode:
    def __init__(self):
        rospy.init_node('vision_system_node')
        self.vision_system = VisionSystem()  # Create an instance of your VisionSystem class
        self.point_cloud_subscriber = rospy.Subscriber("/camera/depth/points", PointCloud2, self.point_cloud_callback)
        self.command_subscriber = rospy.Subscriber('/vision_system_commands', String, self.command_callback)
        
    def point_cloud_callback(self, data):
        # Convert the ROS PointCloud2 message to a generator of points
        point_cloud = pc2.read_points(data, field_names=("x", "y", "z"), skip_nans=True)

        # Iterate through the points and process them
        #for point in point_cloud:
            #x, y, z = point[:3]
            #rospy.loginfo("Point: x=%.2f, y=%.2f, z=%.2f", x, y, z)
            # Process the point cloud data here (e.g., filtering, clustering, etc.)
        self.point_cloud = point_cloud

    def command_callback(self, data):
        if data.data == 'get_rgb_image':
            self.vision_system.get_rgb_image()
        elif data.data == 'get_depth_image':
            self.vision_system.get_depth_image()
        elif data.data == 'get_point_cloud':
            self.vision_system.get_point_cloud(self.point_cloud)

if __name__ == '__main__':
    node = VisionSystemNode()
    rospy.spin() 