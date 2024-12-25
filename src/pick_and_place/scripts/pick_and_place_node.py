#!/usr/bin/env python

import rospy
from std_msgs.msg import String

class PickAndPlace:
    """
    Docstring: A brief description of the class.
    """

    def __init__(self, scan_poses):
        """
        Constructor: Initializes the object's attributes.
        """
        self.attribute1 = scan_poses
        #self.attribute2 = arg2 
        print("Setting attribute 1")
        #print("Setting attribute 2")

    def convert_point_cloud(self):#, arg1, arg2):
        """
        Method: Performs a specific action on the object.
        """
        print("Converting point cloud")
        pass


class PickAndPlaceNode:
    def __init__(self):
        rospy.init_node('pick_and_place_node')
        self.pick_and_place = PickAndPlace([1,2,3,4])  # Create an instance of your PickAndPlace class
        self.subscriber = rospy.Subscriber('/pick_and_place_commands', String, self.command_callback)

    def command_callback(self, data):
        if data.data == 'convert_point_cloud':
            self.pick_and_place.convert_point_cloud()

if __name__ == '__main__':
    node = PickAndPlaceNode()
    rospy.spin() 