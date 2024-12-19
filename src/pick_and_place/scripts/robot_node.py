import rospy
from std_msgs.msg import String

class Robot:
    """
    Docstring: A brief description of the class.
    """

    def __init__(self):#, arg1, arg2):
        """
        Constructor: Initializes the object's attributes.
        """
        #self.attribute1 = arg1
        #self.attribute2 = arg2 
        print("Setting attribute 1")
        print("Setting attribute 2")

    def move_to_pose(self):#, arg1, arg2):
        """
        Method: Performs a specific action on the object.
        """
        print("Moving to pose")
        pass

    def open_gripper(self):#, arg1, arg2):
        """
        Method: Performs another action on the object.
        """
        print("Opening gripper")
        pass

    def close_gripper(self):#, arg1, arg2):
        """
        Method: Performs another action on the object.
        """
        print("Closing gripper")
        pass

    def get_camera_pose(self):#, arg1, arg2):
        """
        Method: Performs another action on the object.
        """
        print("Getting camera pose")
        pass

class RobotNode:
    def __init__(self):
        rospy.init_node('robot_node')
        self.robot = Robot()  # Create an instance of your Robot class
        self.subscriber = rospy.Subscriber('/robot_commands', String, self.command_callback)

    def command_callback(self, data):
        if data.data == 'move_to_pose':
            # Get the desired pose from somewhere (e.g., another topic, a parameter)
            #target_pose = ... 
            #self.robot.move(target_pose)
            self.robot.move_to_pose()
        elif data.data == 'open_gripper':
            self.robot.open_gripper()
        elif data.data == 'close_gripper':
            self.robot.close_gripper()
        elif data.data == 'get_camera_pose':
            self.robot.get_camera_pose()

if __name__ == '__main__':
    node = RobotNode()
    rospy.spin() 