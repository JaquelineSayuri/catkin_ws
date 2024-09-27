#!/usr/bin/env python3

import sys
import rospy
from open_manipulator_msgs.srv import *
from intelligent_manipulator.manipulator import manipulator

if __name__ == "__main__":
    n_episodes = 100
    for e in range(n_episodes):
        