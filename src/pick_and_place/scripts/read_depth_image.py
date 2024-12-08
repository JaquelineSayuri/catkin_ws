#!/usr/bin/env python

import rospy
from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError
import cv2

def depth_image_callback(msg):
    bridge = CvBridge()
    
    try:
        # Convert the ROS image message to an OpenCV image (float32 encoding for depth in meters)
        depth_image = bridge.imgmsg_to_cv2(msg, desired_encoding="32FC1")
    except CvBridgeError as e:
        rospy.logerr("CvBridge Error: {0}".format(e))
        return
    
    # Display or process the depth image
    cv2.imshow("Depth Image", depth_image)
    cv2.waitKey(1)

def main():
    rospy.init_node('depth_image_subscriber')

    # Subscribe to the depth image topic
    rospy.Subscriber("/camera/depth/image_raw", Image, depth_image_callback)

    rospy.spin()

    cv2.destroyAllWindows()

if __name__ == "__main__":
    main()
