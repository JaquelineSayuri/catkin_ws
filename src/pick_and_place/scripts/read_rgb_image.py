#!/usr/bin/env python

import rospy
from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError
import cv2

def image_callback(msg):
    # Initialize CvBridge
    bridge = CvBridge()
    
    try:
        # Convert the ROS Image message to OpenCV format
        cv_image = bridge.imgmsg_to_cv2(msg, "bgr8")
    except CvBridgeError as e:
        rospy.logerr("CvBridge Error: {0}".format(e))
        return

    # Display the image using OpenCV
    cv2.imshow("Camera Image", cv_image)
    
    # Add a delay to process OpenCV's window events
    cv2.waitKey(1)

def main():
    # Initialize the ROS node
    rospy.init_node('image_subscriber_node')

    # Subscribe to the image topic
    image_topic = "/camera/rgb/image_raw"  # Replace with the actual topic name
    rospy.Subscriber(image_topic, Image, image_callback)

    # Spin to keep the script running
    rospy.spin()

    # Clean up when done
    cv2.destroyAllWindows()

if __name__ == "__main__":
    main()
