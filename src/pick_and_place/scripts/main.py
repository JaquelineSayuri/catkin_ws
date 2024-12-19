import rospy
from std_msgs.msg import String
import pick_and_place.scripts.robot_node as robot_node, pick_and_place.scripts.pick_and_place_node as pick_and_place_node, pick_and_place.scripts.vision_system_node as vision_system_node

def main():
    rospy.init_node('main_node')
    publisher = rospy.Publisher('/robot_commands', String, queue_size=10)
    rate = rospy.Rate(10)  # Publish at 10 Hz

    while not rospy.is_shutdown():
        command = "move_to_pose"  # Replace with your desired command
        publisher.publish(String(data=command))
        rospy.loginfo(f"Published command: {command}")
        rate.sleep()

if __name__ == '__main__':
    main()