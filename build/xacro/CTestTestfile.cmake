# CMake generated Testfile for 
# Source directory: /home/jaqueline/catkin_ws/src/xacro
# Build directory: /home/jaqueline/catkin_ws/build/xacro
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(_ctest_xacro_nosetests_test "/home/jaqueline/catkin_ws/build/catkin_generated/env_cached.sh" "/usr/bin/python3" "/opt/ros/noetic/share/catkin/cmake/test/run_tests.py" "/home/jaqueline/catkin_ws/build/test_results/xacro/nosetests-test.xml" "--return-code" "\"/home/jaqueline/.local/lib/python3.8/site-packages/cmake/data/bin/cmake\" -E make_directory /home/jaqueline/catkin_ws/build/test_results/xacro" "/usr/bin/nosetests3 -P --process-timeout=60 --where=/home/jaqueline/catkin_ws/src/xacro/test --with-xunit --xunit-file=/home/jaqueline/catkin_ws/build/test_results/xacro/nosetests-test.xml")
set_tests_properties(_ctest_xacro_nosetests_test PROPERTIES  _BACKTRACE_TRIPLES "/opt/ros/noetic/share/catkin/cmake/test/tests.cmake;160;add_test;/opt/ros/noetic/share/catkin/cmake/test/nosetests.cmake;83;catkin_run_tests_target;/home/jaqueline/catkin_ws/src/xacro/CMakeLists.txt;20;catkin_add_nosetests;/home/jaqueline/catkin_ws/src/xacro/CMakeLists.txt;0;")
subdirs("test")