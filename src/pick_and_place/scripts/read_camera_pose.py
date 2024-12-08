#!/usr/bin/env python

import rospy
import tf

def get_camera_pose():
    rospy.init_node('get_camera_pose_node', anonymous=True)

    # Create a TransformListener object
    listener = tf.TransformListener()

    # Wait for the transform to become available
    listener.waitForTransform('/world', '/camera_link', rospy.Time(), rospy.Duration(4.0))

    try:
        # Get the transformation between '/world' and '/camera_frame' (replace with your frames)
        (trans, rot) = listener.lookupTransform('/world', '/camera_link', rospy.Time(0))

        rospy.loginfo("Translation: %s", str(trans))  # Translation (x, y, z)
        rospy.loginfo("Rotation (Quaternion): %s", str(rot))  # Rotation (x, y, z, w)

    except (tf.LookupException, tf.ConnectivityException, tf.ExtrapolationException):
        rospy.logerr("Transformation not available")

if __name__ == '__main__':
    get_camera_pose()
