
"use strict";

let GetKinematicsPose = require('./GetKinematicsPose.js')
let SetActuatorState = require('./SetActuatorState.js')
let GetJointPosition = require('./GetJointPosition.js')
let SetKinematicsPose = require('./SetKinematicsPose.js')
let SetJointPosition = require('./SetJointPosition.js')
let SetDrawingTrajectory = require('./SetDrawingTrajectory.js')

module.exports = {
  GetKinematicsPose: GetKinematicsPose,
  SetActuatorState: SetActuatorState,
  GetJointPosition: GetJointPosition,
  SetKinematicsPose: SetKinematicsPose,
  SetJointPosition: SetJointPosition,
  SetDrawingTrajectory: SetDrawingTrajectory,
};
