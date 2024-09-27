;; Auto-generated. Do not edit!


(when (boundp 'intelligent_manipulator::Observation)
  (if (not (find-package "INTELLIGENT_MANIPULATOR"))
    (make-package "INTELLIGENT_MANIPULATOR"))
  (shadow 'Observation (find-package "INTELLIGENT_MANIPULATOR")))
(unless (find-package "INTELLIGENT_MANIPULATOR::OBSERVATION")
  (make-package "INTELLIGENT_MANIPULATOR::OBSERVATION"))

(in-package "ROS")
;;//! \htmlinclude Observation.msg.html


(defclass intelligent_manipulator::Observation
  :super ros::object
  :slots (_observation ))

(defmethod intelligent_manipulator::Observation
  (:init
   (&key
    ((:observation __observation) (make-array 0 :initial-element 0.0 :element-type :float))
    )
   (send-super :init)
   (setq _observation __observation)
   self)
  (:observation
   (&optional __observation)
   (if __observation (setq _observation __observation)) _observation)
  (:serialization-length
   ()
   (+
    ;; float64[] _observation
    (* 8    (length _observation)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64[] _observation
     (write-long (length _observation) s)
     (dotimes (i (length _observation))
       (sys::poke (elt _observation i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64[] _observation
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _observation (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _observation i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     ))
   ;;
   self)
  )

(setf (get intelligent_manipulator::Observation :md5sum-) "bbbad3e35ac69edda7d7576e4d0cda1c")
(setf (get intelligent_manipulator::Observation :datatype-) "intelligent_manipulator/Observation")
(setf (get intelligent_manipulator::Observation :definition-)
      "float64[] observation
")



(provide :intelligent_manipulator/Observation "bbbad3e35ac69edda7d7576e4d0cda1c")


