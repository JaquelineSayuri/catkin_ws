// Auto-generated. Do not edit!

// (in-package intelligent_manipulator.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class Observation {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.observation = null;
    }
    else {
      if (initObj.hasOwnProperty('observation')) {
        this.observation = initObj.observation
      }
      else {
        this.observation = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Observation
    // Serialize message field [observation]
    bufferOffset = _arraySerializer.float64(obj.observation, buffer, bufferOffset, null);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Observation
    let len;
    let data = new Observation(null);
    // Deserialize message field [observation]
    data.observation = _arrayDeserializer.float64(buffer, bufferOffset, null)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += 8 * object.observation.length;
    return length + 4;
  }

  static datatype() {
    // Returns string type for a message object
    return 'intelligent_manipulator/Observation';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'bbbad3e35ac69edda7d7576e4d0cda1c';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float64[] observation
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new Observation(null);
    if (msg.observation !== undefined) {
      resolved.observation = msg.observation;
    }
    else {
      resolved.observation = []
    }

    return resolved;
    }
};

module.exports = Observation;
