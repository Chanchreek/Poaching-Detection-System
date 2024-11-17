
# **Poaching Detection System using AI**

## **Overview**
This project focuses on developing an **AI-powered system** to detect poaching activities in real-time. The system leverages **facial recognition** to identify individuals involved in illegal hunting, using **YOLO** and **OpenCV** for object detection. The system includes a PIR sensor that when senses motion activates the Camera attached to Raspberry Pi and records a video of defined length and sends it to **AWS EC2**, where the code for object detection is stored.

The ultimate goal is to help conservation efforts by providing an **automated system** to monitor and prevent poaching in wildlife sanctuaries.

## **Features**
- **Real-Time Detection**: Uses motion sensors to detect motion in the wildlife, and checks if the movement was caused by humans or animals.
- **YOLO Integration**: Utilizes YOLO (**You Only Look Once**) for fast and efficient object detection.
- **Edge AI**: Deploys on devices like Raspberry Pi to process data locally.
- **Cloud Computing**: Stores captured video and computes the detected code on an AWS EC2 instance.

## **Motivation**
Poaching is a major threat to wildlife and has devastating effects on **biodiversity** and **ecosystems**. Current methods of poaching detection are often delayed and require manual intervention. This system aims to:
- Automate the detection process
- Provide **real-time alerts**
- Minimize response time for anti-poaching teams
- Enable long-term data storage and analysis of poaching activity

## **Hardware Requirements**
To deploy the system in the field, the following hardware components are recommended:
- **Raspberry Pi 4** as an edge device.
- **Camera Module** for capturing images in the field.
- **PIR Sensor** for detecting motion.
- Battery packs or solar power solutions for remote field deployment.

## **Software Architecture**
The system is divided into several key components:
1. **Camera Trap (Edge Device)**: Captures images in real-time and processes them locally.
2. **YOLO & OpenCV Integration**: YOLO is used for object detection, and OpenCV handles facial recognition.
3. **Image Storage**: Stores recognized faces and their metadata securely in a database.

## **Installation**

### **Clone the Repository**
```bash
git clone https://github.com/yourusername/poaching-detection-system.git
cd poaching-detection-system
```

## **Setting up the Environment**

### **1. Install Python Dependencies**
Ensure the following Python dependencies are installed by running:
```bash
pip install -r requirements.txt
```
Key dependencies include:
- `opencv-python`
- `tensorflow`
- `torch`
- `pillow`
- `numpy`

### **2. Download Pre-Trained YOLO Weights**
Download YOLOv5 weights from [this link](https://github.com/ultralytics/yolov5/releases) and place them in the `weights/` directory.

## **Setting up Raspberry Pi**
### **1. Install TensorFlow Lite and OpenCV**
Follow [this guide](https://www.tensorflow.org/lite/guide/python) to install TensorFlow Lite and OpenCV on your Raspberry Pi.

### **2. Connect PIR Sensor and Camera**
- Connect and configure the PIR sensor to detect motion and trigger the camera to start recording.
- Ensure that the camera is properly set up and connected to the Raspberry Pi.

## **Running the Application**
### **1. Run the Poaching Detection System on the Raspberry Pi**
Once the PIR sensor detects motion, the camera records a video, which is then sent to an AWS EC2 instance for further processing.
```bash
python capture_video.py
```

### **2. Process the Video on AWS EC2**
Run the object detection script on the AWS EC2 instance to process the video:
```bash
python detect_poachers.py
```

## **Configuration**
Modify the `config.json` file to set up specific parameters for camera traps, video storage paths, and detection thresholds.

## **How It Works**
1. **Motion Detection and Recording**: 
   The PIR sensor triggers the camera on the Raspberry Pi, which starts recording upon detecting motion.

2. **Video Transfer**:
   The recorded video is automatically sent to an AWS EC2 instance for object detection.

3. **YOLO Detection**:
   The YOLO model on the EC2 instance processes the video, detecting human figures and marking them as potential poachers.

4. **Facial Recognition**:
   OpenCV processes detected faces for recognition and matches them against a known database of individuals.

5. **Data Storage**:
   Processed videos and metadata are securely stored on the EC2 instance for future analysis.

6. **Alerts**:
   Real-time alerts can be configured to notify conservation teams of detected poachers for rapid response.

## **Future Enhancements**
- **Improved Model Accuracy**: Fine-tune the YOLO model with more training data specific to poaching activities.
- **Real-Time Notifications**: Integrate with AWS services for instant notifications to anti-poaching teams.
- **Predictive Analysis**: Incorporate analytics to forecast potential poaching hotspots.
- **Expanded Sensor Integration**: Integrate additional sensors to enhance environmental monitoring.

---


## **Contribution**
Contributions are welcome! Please fork the repository, make your changes, and submit a pull request.

## **License**
This project is licensed under the **MIT License**. See the `LICENSE` file for more information.

## **Contact**
For questions or suggestions, feel free to reach out at poaching-detection-system@gmail.com .

---
