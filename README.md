# Line Following Robot with Computer Vision

```python
"""
This repository contains Python code for a line-following robot implemented using computer vision.
The robot uses OpenCV for image processing and communication with an Arduino over Bluetooth for motor control.
"""

"""
The Line Following Robot with Computer Vision project is designed to create an autonomous robot capable of following a line using computer vision techniques. The implementation involves integrating OpenCV for image processing and communication with an Arduino for motor control via Bluetooth.

## Features
- Line following using a combination of contour detection and Hough Line Transform algorithms.
- Track adjustment technique with memory to reverse the robot's previous steps when it deviates from the track.

## Demo Video
- [Watch the Line Following Robot in action (Video 1)](https://youtube.com/shorts/nUP3iwmkXG0?feature=share)
- [Watch another Line Following Robot demonstration (Video 2)](https://youtube.com/shorts/M5eX7upDQvA?feature=share)

## How it Works
- The robot processes the camera feed using OpenCV to detect lines on the track.
- The combination of contour detection and Hough Line Transform provides robust line-following capabilities.
- The track adjustment technique includes a memory mechanism to reverse the robot's path when it deviates from the track.

## Author
Ziad Abdelrehim Othman
"""

## Hardware Requirements

"""
- Arduino board
- Bluetooth module
- Camera module
"""

## Line Following Algorithms

"""
The line following in this project is achieved through a merge of two key algorithms:

### Contour Detection
- Utilizes OpenCV's contour detection to identify the edges of the track.
- Provides information about the structure and shape of objects in the camera feed.

### Hough Line Transform
- Applies the Hough Line Transform to detect straight lines within the image.
- Used to identify the linear structure of the track for precise line following.
"""
## Track Adjustment Technique

"""
The track adjustment technique employed in this project includes a memory mechanism for each step:

### Memory for Track Adjustment
- Maintains a record of the robot's previous steps.
- If the robot deviates from the track, it can reverse its previous steps to get back on course.
- Enhances the robot's ability to recover from track deviations and continue following the line effectively.
"""

