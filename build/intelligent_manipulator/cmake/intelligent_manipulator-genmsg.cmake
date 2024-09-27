# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "intelligent_manipulator: 3 messages, 0 services")

set(MSG_I_FLAGS "-Iintelligent_manipulator:/home/jaqueline/catkin_ws/src/intelligent_manipulator/msg;-Istd_msgs:/opt/ros/noetic/share/std_msgs/cmake/../msg;-Iintelligent_manipulator:/home/jaqueline/catkin_ws/src/intelligent_manipulator/msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(intelligent_manipulator_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/jaqueline/catkin_ws/src/intelligent_manipulator/msg/Observation.msg" NAME_WE)
add_custom_target(_intelligent_manipulator_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "intelligent_manipulator" "/home/jaqueline/catkin_ws/src/intelligent_manipulator/msg/Observation.msg" ""
)

get_filename_component(_filename "/home/jaqueline/catkin_ws/src/intelligent_manipulator/msg/Action.msg" NAME_WE)
add_custom_target(_intelligent_manipulator_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "intelligent_manipulator" "/home/jaqueline/catkin_ws/src/intelligent_manipulator/msg/Action.msg" ""
)

get_filename_component(_filename "/home/jaqueline/catkin_ws/src/intelligent_manipulator/msg/Position.msg" NAME_WE)
add_custom_target(_intelligent_manipulator_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "intelligent_manipulator" "/home/jaqueline/catkin_ws/src/intelligent_manipulator/msg/Position.msg" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(intelligent_manipulator
  "/home/jaqueline/catkin_ws/src/intelligent_manipulator/msg/Observation.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/intelligent_manipulator
)
_generate_msg_cpp(intelligent_manipulator
  "/home/jaqueline/catkin_ws/src/intelligent_manipulator/msg/Action.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/intelligent_manipulator
)
_generate_msg_cpp(intelligent_manipulator
  "/home/jaqueline/catkin_ws/src/intelligent_manipulator/msg/Position.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/intelligent_manipulator
)

### Generating Services

### Generating Module File
_generate_module_cpp(intelligent_manipulator
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/intelligent_manipulator
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(intelligent_manipulator_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(intelligent_manipulator_generate_messages intelligent_manipulator_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/jaqueline/catkin_ws/src/intelligent_manipulator/msg/Observation.msg" NAME_WE)
add_dependencies(intelligent_manipulator_generate_messages_cpp _intelligent_manipulator_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/jaqueline/catkin_ws/src/intelligent_manipulator/msg/Action.msg" NAME_WE)
add_dependencies(intelligent_manipulator_generate_messages_cpp _intelligent_manipulator_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/jaqueline/catkin_ws/src/intelligent_manipulator/msg/Position.msg" NAME_WE)
add_dependencies(intelligent_manipulator_generate_messages_cpp _intelligent_manipulator_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(intelligent_manipulator_gencpp)
add_dependencies(intelligent_manipulator_gencpp intelligent_manipulator_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS intelligent_manipulator_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(intelligent_manipulator
  "/home/jaqueline/catkin_ws/src/intelligent_manipulator/msg/Observation.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/intelligent_manipulator
)
_generate_msg_eus(intelligent_manipulator
  "/home/jaqueline/catkin_ws/src/intelligent_manipulator/msg/Action.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/intelligent_manipulator
)
_generate_msg_eus(intelligent_manipulator
  "/home/jaqueline/catkin_ws/src/intelligent_manipulator/msg/Position.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/intelligent_manipulator
)

### Generating Services

### Generating Module File
_generate_module_eus(intelligent_manipulator
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/intelligent_manipulator
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(intelligent_manipulator_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(intelligent_manipulator_generate_messages intelligent_manipulator_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/jaqueline/catkin_ws/src/intelligent_manipulator/msg/Observation.msg" NAME_WE)
add_dependencies(intelligent_manipulator_generate_messages_eus _intelligent_manipulator_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/jaqueline/catkin_ws/src/intelligent_manipulator/msg/Action.msg" NAME_WE)
add_dependencies(intelligent_manipulator_generate_messages_eus _intelligent_manipulator_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/jaqueline/catkin_ws/src/intelligent_manipulator/msg/Position.msg" NAME_WE)
add_dependencies(intelligent_manipulator_generate_messages_eus _intelligent_manipulator_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(intelligent_manipulator_geneus)
add_dependencies(intelligent_manipulator_geneus intelligent_manipulator_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS intelligent_manipulator_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(intelligent_manipulator
  "/home/jaqueline/catkin_ws/src/intelligent_manipulator/msg/Observation.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/intelligent_manipulator
)
_generate_msg_lisp(intelligent_manipulator
  "/home/jaqueline/catkin_ws/src/intelligent_manipulator/msg/Action.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/intelligent_manipulator
)
_generate_msg_lisp(intelligent_manipulator
  "/home/jaqueline/catkin_ws/src/intelligent_manipulator/msg/Position.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/intelligent_manipulator
)

### Generating Services

### Generating Module File
_generate_module_lisp(intelligent_manipulator
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/intelligent_manipulator
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(intelligent_manipulator_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(intelligent_manipulator_generate_messages intelligent_manipulator_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/jaqueline/catkin_ws/src/intelligent_manipulator/msg/Observation.msg" NAME_WE)
add_dependencies(intelligent_manipulator_generate_messages_lisp _intelligent_manipulator_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/jaqueline/catkin_ws/src/intelligent_manipulator/msg/Action.msg" NAME_WE)
add_dependencies(intelligent_manipulator_generate_messages_lisp _intelligent_manipulator_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/jaqueline/catkin_ws/src/intelligent_manipulator/msg/Position.msg" NAME_WE)
add_dependencies(intelligent_manipulator_generate_messages_lisp _intelligent_manipulator_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(intelligent_manipulator_genlisp)
add_dependencies(intelligent_manipulator_genlisp intelligent_manipulator_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS intelligent_manipulator_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(intelligent_manipulator
  "/home/jaqueline/catkin_ws/src/intelligent_manipulator/msg/Observation.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/intelligent_manipulator
)
_generate_msg_nodejs(intelligent_manipulator
  "/home/jaqueline/catkin_ws/src/intelligent_manipulator/msg/Action.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/intelligent_manipulator
)
_generate_msg_nodejs(intelligent_manipulator
  "/home/jaqueline/catkin_ws/src/intelligent_manipulator/msg/Position.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/intelligent_manipulator
)

### Generating Services

### Generating Module File
_generate_module_nodejs(intelligent_manipulator
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/intelligent_manipulator
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(intelligent_manipulator_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(intelligent_manipulator_generate_messages intelligent_manipulator_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/jaqueline/catkin_ws/src/intelligent_manipulator/msg/Observation.msg" NAME_WE)
add_dependencies(intelligent_manipulator_generate_messages_nodejs _intelligent_manipulator_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/jaqueline/catkin_ws/src/intelligent_manipulator/msg/Action.msg" NAME_WE)
add_dependencies(intelligent_manipulator_generate_messages_nodejs _intelligent_manipulator_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/jaqueline/catkin_ws/src/intelligent_manipulator/msg/Position.msg" NAME_WE)
add_dependencies(intelligent_manipulator_generate_messages_nodejs _intelligent_manipulator_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(intelligent_manipulator_gennodejs)
add_dependencies(intelligent_manipulator_gennodejs intelligent_manipulator_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS intelligent_manipulator_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(intelligent_manipulator
  "/home/jaqueline/catkin_ws/src/intelligent_manipulator/msg/Observation.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/intelligent_manipulator
)
_generate_msg_py(intelligent_manipulator
  "/home/jaqueline/catkin_ws/src/intelligent_manipulator/msg/Action.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/intelligent_manipulator
)
_generate_msg_py(intelligent_manipulator
  "/home/jaqueline/catkin_ws/src/intelligent_manipulator/msg/Position.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/intelligent_manipulator
)

### Generating Services

### Generating Module File
_generate_module_py(intelligent_manipulator
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/intelligent_manipulator
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(intelligent_manipulator_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(intelligent_manipulator_generate_messages intelligent_manipulator_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/jaqueline/catkin_ws/src/intelligent_manipulator/msg/Observation.msg" NAME_WE)
add_dependencies(intelligent_manipulator_generate_messages_py _intelligent_manipulator_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/jaqueline/catkin_ws/src/intelligent_manipulator/msg/Action.msg" NAME_WE)
add_dependencies(intelligent_manipulator_generate_messages_py _intelligent_manipulator_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/jaqueline/catkin_ws/src/intelligent_manipulator/msg/Position.msg" NAME_WE)
add_dependencies(intelligent_manipulator_generate_messages_py _intelligent_manipulator_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(intelligent_manipulator_genpy)
add_dependencies(intelligent_manipulator_genpy intelligent_manipulator_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS intelligent_manipulator_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/intelligent_manipulator)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/intelligent_manipulator
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(intelligent_manipulator_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()
if(TARGET intelligent_manipulator_generate_messages_cpp)
  add_dependencies(intelligent_manipulator_generate_messages_cpp intelligent_manipulator_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/intelligent_manipulator)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/intelligent_manipulator
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(intelligent_manipulator_generate_messages_eus std_msgs_generate_messages_eus)
endif()
if(TARGET intelligent_manipulator_generate_messages_eus)
  add_dependencies(intelligent_manipulator_generate_messages_eus intelligent_manipulator_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/intelligent_manipulator)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/intelligent_manipulator
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(intelligent_manipulator_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()
if(TARGET intelligent_manipulator_generate_messages_lisp)
  add_dependencies(intelligent_manipulator_generate_messages_lisp intelligent_manipulator_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/intelligent_manipulator)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/intelligent_manipulator
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(intelligent_manipulator_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()
if(TARGET intelligent_manipulator_generate_messages_nodejs)
  add_dependencies(intelligent_manipulator_generate_messages_nodejs intelligent_manipulator_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/intelligent_manipulator)
  install(CODE "execute_process(COMMAND \"/usr/bin/python3\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/intelligent_manipulator\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/intelligent_manipulator
    DESTINATION ${genpy_INSTALL_DIR}
    # skip all init files
    PATTERN "__init__.py" EXCLUDE
    PATTERN "__init__.pyc" EXCLUDE
  )
  # install init files which are not in the root folder of the generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/intelligent_manipulator
    DESTINATION ${genpy_INSTALL_DIR}
    FILES_MATCHING
    REGEX "${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/intelligent_manipulator/.+/__init__.pyc?$"
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(intelligent_manipulator_generate_messages_py std_msgs_generate_messages_py)
endif()
if(TARGET intelligent_manipulator_generate_messages_py)
  add_dependencies(intelligent_manipulator_generate_messages_py intelligent_manipulator_generate_messages_py)
endif()
