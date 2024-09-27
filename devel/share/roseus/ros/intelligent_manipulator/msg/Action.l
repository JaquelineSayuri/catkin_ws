;; Auto-generated. Do not edit!


(when (boundp 'intelligent_manipulator::Action)
  (if (not (find-package "INTELLIGENT_MANIPULATOR"))
    (make-package "INTELLIGENT_MANIPULATOR"))
  (shadow 'Action (find-package "INTELLIGENT_MANIPULATOR")))
(unless (find-package "INTELLIGENT_MANIPULATOR::ACTION")
  (make-package "INTELLIGENT_MANIPULATOR::ACTION"))

(in-package "ROS")
;;//! \htmlinclude Action.msg.html


(defclass intelligent_manipulator::Action
  :super ros::object
  :slots (_action ))

(defmethod intelligent_manipulator::Action
  (:init
   (&key
    ((:action __action) (make-array 0 :initial-element 0.0 :element-type :float))
    )
   (send-super :init)
   (setq _action __action)
   self)
  (:action
   (&optional __action)
   (if __action (setq _action __action)) _action)
  (:serialization-length
   ()
   (+
    ;; float64[] _action
    (* 8    (length _action)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64[] _action
     (write-long (length _action) s)
     (dotimes (i (length _action))
       (sys::poke (elt _action i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64[] _action
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _action (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _action i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     ))
   ;;
   self)
  )

(setf (get intelligent_manipulator::Action :md5sum-) "79f44d272f2ebe04451185b0dea57684")
(setf (get intelligent_manipulator::Action :datatype-) "intelligent_manipulator/Action")
(setf (get intelligent_manipulator::Action :definition-)
      "float64[] action
")



(provide :intelligent_manipulator/Action "79f44d272f2ebe04451185b0dea57684")


