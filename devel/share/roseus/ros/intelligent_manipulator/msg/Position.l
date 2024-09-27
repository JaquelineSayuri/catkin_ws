;; Auto-generated. Do not edit!


(when (boundp 'intelligent_manipulator::Position)
  (if (not (find-package "INTELLIGENT_MANIPULATOR"))
    (make-package "INTELLIGENT_MANIPULATOR"))
  (shadow 'Position (find-package "INTELLIGENT_MANIPULATOR")))
(unless (find-package "INTELLIGENT_MANIPULATOR::POSITION")
  (make-package "INTELLIGENT_MANIPULATOR::POSITION"))

(in-package "ROS")
;;//! \htmlinclude Position.msg.html


(defclass intelligent_manipulator::Position
  :super ros::object
  :slots (_position ))

(defmethod intelligent_manipulator::Position
  (:init
   (&key
    ((:position __position) (make-array 0 :initial-element 0.0 :element-type :float))
    )
   (send-super :init)
   (setq _position __position)
   self)
  (:position
   (&optional __position)
   (if __position (setq _position __position)) _position)
  (:serialization-length
   ()
   (+
    ;; float64[] _position
    (* 8    (length _position)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64[] _position
     (write-long (length _position) s)
     (dotimes (i (length _position))
       (sys::poke (elt _position i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64[] _position
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _position (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _position i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     ))
   ;;
   self)
  )

(setf (get intelligent_manipulator::Position :md5sum-) "50410efb3480c63b23b8b5fe2bea331a")
(setf (get intelligent_manipulator::Position :datatype-) "intelligent_manipulator/Position")
(setf (get intelligent_manipulator::Position :definition-)
      "float64[] position
")



(provide :intelligent_manipulator/Position "50410efb3480c63b23b8b5fe2bea331a")


