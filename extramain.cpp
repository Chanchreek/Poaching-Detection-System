/*
#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>
#include <iostream>

using namespace cv;
using namespace cv::dnn;
using namespace std;

int main() {
    // Load the pre-trained MobileNet-SSD model and configuration file
    String model = "F:/extract/opencv/sources/data/mobilenet_iter_73000.caffemodel";  // Path to model file
    String config = "F:/extract/opencv/sources/data/deploy.prototxt";  // Path to prototxt file

    // Load the network
    Net net = readNetFromCaffe(config, model);

    // Load an image or a video for object detection
    Mat frame = imread("F:/minor/doggo.jpg");  // Replace with your image path
    if (frame.empty()) {
        cout << "Could not open or find the image!" << endl;
        return -1;
    }

    // Prepare the input for the neural network
    Mat blob = blobFromImage(frame, 0.007843, Size(300, 300), Scalar(127.5, 127.5, 127.5), false, false);

    // Set the input blob for the network
    net.setInput(blob);

    // Forward pass: compute output of the network
    Mat detections = net.forward();

    // Detections is a 4D matrix with dimensions [1, 1, N, 7] where N is the number of detections
    for (int i = 0; i < detections.size[2]; i++) {
        float confidence = detections.ptr<float>(0)[i * 7 + 2];  // Confidence score
        if (confidence > 0.2) {  // Confidence threshold
            int objectClass = static_cast<int>(detections.ptr<float>(0)[i * 7 + 1]);  // Class ID
            int xLeftBottom = static_cast<int>(detections.ptr<float>(0)[i * 7 + 3] * frame.cols);
            int yLeftBottom = static_cast<int>(detections.ptr<float>(0)[i * 7 + 4] * frame.rows);
            int xRightTop = static_cast<int>(detections.ptr<float>(0)[i * 7 + 5] * frame.cols);
            int yRightTop = static_cast<int>(detections.ptr<float>(0)[i * 7 + 6] * frame.rows);

            // Draw a rectangle around the object
            rectangle(frame, Point(xLeftBottom, yLeftBottom), Point(xRightTop, yRightTop), Scalar(0, 255, 0), 2);
            putText(frame, to_string(objectClass), Point(xLeftBottom, yLeftBottom), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 255, 0), 2);
        }
    }

    // Display the resulting image with detection boxes
    imshow("Detected Objects", frame);
    waitKey(0);

    return 0;
}
*/

/*
#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>
#include <iostream>

using namespace cv;
using namespace cv::dnn;
using namespace std;

int main() {
    // Load the pre-trained MobileNet-SSD model and configuration file
    String model = "F:/extract/opencv/sources/data/mobilenet_iter_73000.caffemodel";  // Path to model file
    String config = "F:/extract/opencv/sources/data/deploy.prototxt";  // Path to prototxt file

    // Load the network
    Net net = readNetFromCaffe(config, model);

    // Open a connection to the webcam
    VideoCapture cap(0);  // 0 is the default ID for the built-in webcam
    if (!cap.isOpened()) {
        cout << "Error: Could not open the webcam." << endl;
        return -1;
    }

    while (true) {
        Mat frame;
        cap >> frame;  // Capture a frame from the webcam

        if (frame.empty()) {
            cout << "Error: Could not capture a frame from the webcam." << endl;
            break;
        }

        // Prepare the input blob for the neural network
        Mat blob = blobFromImage(frame, 0.007843, Size(300, 300), Scalar(127.5, 127.5, 127.5), false, false);

        // Set the input blob for the network
        net.setInput(blob);

        // Forward pass: compute output of the network
        Mat detections = net.forward();

        // Detections is a 4D matrix with dimensions [1, 1, N, 7] where N is the number of detections
        for (int i = 0; i < detections.size[2]; i++) {
            // Detections.at<float>(0, 0, i, 2) accesses the confidence score at position i
            float confidence = detections.ptr<float>(0)[i * 7 + 2];

            // Class 15 corresponds to "person" in the COCO dataset for MobileNet-SSD
            int objectClass = static_cast<int>(detections.ptr<float>(0)[i * 7 + 1]);

            // Filter out detections with confidence below the threshold and check if it's a person (class 15)
            if (objectClass == 15 && confidence > 0.5) {  // 0.5 is the confidence threshold
                // Extract the bounding box coordinates
                int xLeftBottom = static_cast<int>(detections.ptr<float>(0)[i * 7 + 3] * frame.cols);
                int yLeftBottom = static_cast<int>(detections.ptr<float>(0)[i * 7 + 4] * frame.rows);
                int xRightTop = static_cast<int>(detections.ptr<float>(0)[i * 7 + 5] * frame.cols);
                int yRightTop = static_cast<int>(detections.ptr<float>(0)[i * 7 + 6] * frame.rows);

                // Draw a rectangle around the detected person
                rectangle(frame, Point(xLeftBottom, yLeftBottom), Point(xRightTop, yRightTop), Scalar(0, 255, 0), 2);

                // Put a label "Person" on the detection
                putText(frame, "Person", Point(xLeftBottom, yLeftBottom - 10), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 255, 0), 2);
            }
        }


        // Display the resulting frame
        imshow("Human Detection", frame);

        // Break the loop if the 'q' key is pressed
        if (waitKey(30) == 'q') {
            break;
        }
    }

    // Release the webcam and destroy any OpenCV windows
    cap.release();
    destroyAllWindows();

    return 0;
}
*/


/*hand not recognized?
#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>
#include <iostream>

using namespace cv;
using namespace cv::dnn;
using namespace std;

int main() {
    // Load the pre-trained MobileNet-SSD model and configuration file
    String model = "F:/extract/opencv/sources/data/mobilenet_iter_73000.caffemodel";  // Path to model file
    String config = "F:/extract/opencv/sources/data/deploy.prototxt";  // Path to prototxt file

    // Load the network
    Net net = readNetFromCaffe(config, model);

    // Open a connection to the webcam
    VideoCapture cap(0);  // 0 is the default ID for the built-in webcam
    if (!cap.isOpened()) {
        cout << "Error: Could not open the webcam." << endl;
        return -1;
    }

    while (true) {
        Mat frame;
        cap >> frame;  // Capture a frame from the webcam

        if (frame.empty()) {
            cout << "Error: Could not capture a frame from the webcam." << endl;
            break;
        }

        // Prepare the input blob for the neural network
        Mat blob = blobFromImage(frame, 1.0 / 255.0, Size(300, 300), Scalar(127.5, 127.5, 127.5), true, false);

        // Set the input blob for the network
        net.setInput(blob);

        // Forward pass: compute output of the network
        Mat detections = net.forward();

        // Store all bounding boxes and confidence scores for NMS
        vector<Rect> boxes;
        vector<float> confidences;
        vector<int> indices;

        // Detections is a 4D matrix with dimensions [1, 1, N, 7] where N is the number of detections
        for (int i = 0; i < detections.size[2]; i++) {
            // Extract the confidence score for the detection
            float confidence = detections.ptr<float>(0)[i * 7 + 2];

            // Class 15 corresponds to "person" in the COCO dataset for MobileNet-SSD
            int objectClass = static_cast<int>(detections.ptr<float>(0)[i * 7 + 1]);

            // Filter out detections with confidence below the threshold and check if it's a person (class 15)
            if (objectClass == 15 && confidence > 0.7) {  // Increased threshold to 0.7
                // Extract the bounding box coordinates
                int xLeftBottom = static_cast<int>(detections.ptr<float>(0)[i * 7 + 3] * frame.cols);
                int yLeftBottom = static_cast<int>(detections.ptr<float>(0)[i * 7 + 4] * frame.rows);
                int xRightTop = static_cast<int>(detections.ptr<float>(0)[i * 7 + 5] * frame.cols);
                int yRightTop = static_cast<int>(detections.ptr<float>(0)[i * 7 + 6] * frame.rows);

                // Save the bounding box and confidence score for NMS
                boxes.push_back(Rect(Point(xLeftBottom, yLeftBottom), Point(xRightTop, yRightTop)));
                confidences.push_back(confidence);
            }
        }

        // Apply Non-Maximum Suppression (NMS) to filter overlapping boxes
        float nmsThreshold = 0.4;  // Adjust NMS threshold
        dnn::NMSBoxes(boxes, confidences, 0.7, nmsThreshold, indices);  // Use the same confidence threshold for NMS

        // Draw the resulting boxes after NMS
        for (int idx : indices) {
            Rect box = boxes[idx];
            // Draw a rectangle around the detected person
            rectangle(frame, box, Scalar(0, 255, 0), 2);

            // Put a label "Person" on the detection
            putText(frame, "Person", Point(box.x, box.y - 10), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 255, 0), 2);
        }

        // Display the resulting frame
        imshow("Human Detection", frame);

        // Break the loop if the 'q' key is pressed
        if (waitKey(30) == 'q') {
            break;
        }
    }

    // Release the webcam and destroy any OpenCV windows
    cap.release();
    destroyAllWindows();

    return 0;
}
*/


/*

BEST ONE EVER - FOR LIVE FEED

#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>
#include <iostream>
#include <fstream>

using namespace cv;
using namespace cv::dnn;
using namespace std;

// Function to load class names from coco.names file
vector<string> loadClassNames(const string& path) {
    vector<string> classNames;
    ifstream ifs(path);
    string line;
    while (getline(ifs, line)) {
        classNames.push_back(line);
    }
    return classNames;
}

int main() {
    // Load the YOLO model
    String modelWeights = "F:/extract/opencv/sources/data/yolov4.weights";   // Path to the weights file
    String modelConfig = "F:/extract/opencv/sources/data/yolov4.cfg";        // Path to the configuration file
    String classesFile = "F:/extract/opencv/sources/data/coco.names";        // Path to the class names file

    Net net = readNetFromDarknet(modelConfig, modelWeights);
    net.setPreferableBackend(DNN_BACKEND_OPENCV);
    net.setPreferableTarget(DNN_TARGET_CPU);

    // Load class names
    vector<string> classNames = loadClassNames(classesFile);

    // Open a connection to the webcam
    VideoCapture cap(0);  // 0 is the default ID for the built-in webcam
    if (!cap.isOpened()) {
        cout << "Error: Could not open the webcam." << endl;
        return -1;
    }

    while (true) {
        Mat frame;
        cap >> frame;  // Capture a frame from the webcam

        if (frame.empty()) {
            cout << "Error: Could not capture a frame from the webcam." << endl;
            break;
        }

        // Prepare the input blob for the network
        Mat blob = blobFromImage(frame, 1 / 255.0, Size(416, 416), Scalar(0, 0, 0), true, false);

        // Set the input blob for the network
        net.setInput(blob);

        // Forward pass: get the output layers
        vector<Mat> outs;
        vector<string> outNames = net.getUnconnectedOutLayersNames();
        net.forward(outs, outNames);

        // Post-process the detections
        float confThreshold = 0.5;  // Confidence threshold
        float nmsThreshold = 0.4;   // Non-maximum suppression threshold
        vector<int> classIds;
        vector<float> confidences;
        vector<Rect> boxes;

        for (size_t i = 0; i < outs.size(); ++i) {
            float* data = (float*)outs[i].data;
            for (int j = 0; j < outs[i].rows; ++j, data += outs[i].cols) {
                Mat scores = outs[i].row(j).colRange(5, outs[i].cols);
                Point classIdPoint;
                double confidence;
                minMaxLoc(scores, 0, &confidence, 0, &classIdPoint);
                if (confidence > confThreshold) {
                    int centerX = (int)(data[0] * frame.cols);
                    int centerY = (int)(data[1] * frame.rows);
                    int width = (int)(data[2] * frame.cols);
                    int height = (int)(data[3] * frame.rows);
                    int left = centerX - width / 2;
                    int top = centerY - height / 2;

                    classIds.push_back(classIdPoint.x);
                    confidences.push_back((float)confidence);
                    boxes.push_back(Rect(left, top, width, height));
                }
            }
        }

        // Apply non-maximum suppression to filter out overlapping boxes
        vector<int> indices;
        dnn::NMSBoxes(boxes, confidences, confThreshold, nmsThreshold, indices);

        // Draw the results
        for (size_t i = 0; i < indices.size(); ++i) {
            int idx = indices[i];
            Rect box = boxes[idx];
            if (classNames[classIds[idx]] == "person") {
                // Draw a rectangle around the detected person
                rectangle(frame, box, Scalar(0, 255, 0), 2);
                // Put label
                putText(frame, classNames[classIds[idx]], Point(box.x, box.y - 5), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 255, 0), 2);
            }
        }

        // Display the resulting frame
        imshow("YOLO Human Detection", frame);

        // Break the loop if the 'q' key is pressed
        if (waitKey(30) == 'q') {
            break;
        }
    }

    // Release the webcam and destroy any OpenCV windows
    cap.release();
    destroyAllWindows();

    return 0;
}
*/

/* very good but takes chimps as humans
#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>
#include <iostream>
#include <fstream>

using namespace cv;
using namespace cv::dnn;
using namespace std;

// Function to load class names from coco.names file
vector<string> loadClassNames(const string& path) {
    vector<string> classNames;
    ifstream ifs(path);
    string line;
    while (getline(ifs, line)) {
        classNames.push_back(line);
    }
    return classNames;
}

int main() {
    // Load the YOLO model
    String modelWeights = "F:/extract/opencv/sources/data/yolov3.weights";   // Path to the weights file
    String modelConfig = "F:/extract/opencv/sources/data/yolov3.cfg";        // Path to the configuration file
    String classesFile = "F:/extract/opencv/sources/data/coco.names";        // Path to the class names file

    Net net = readNetFromDarknet(modelConfig, modelWeights);
    net.setPreferableBackend(DNN_BACKEND_OPENCV);
    net.setPreferableTarget(DNN_TARGET_CPU);

    // Load class names
    vector<string> classNames = loadClassNames(classesFile);

    // Read the image file
    String imagePath = "F:/minor/chimp.jpg";  // Replace with the path to your image
    Mat frame = imread(imagePath);

    if (frame.empty()) {
        cout << "Error: Could not open or find the image!" << endl;
        return -1;
    }

    // Prepare the input blob for the network
    Mat blob = blobFromImage(frame, 1 / 255.0, Size(416, 416), Scalar(0, 0, 0), true, false);

    // Set the input blob for the network
    net.setInput(blob);

    // Forward pass: get the output layers
    vector<Mat> outs;
    vector<string> outNames = net.getUnconnectedOutLayersNames();
    net.forward(outs, outNames);

    // Post-process the detections
    float confThreshold = 0.5;  // Confidence threshold
    float nmsThreshold = 0.4;   // Non-maximum suppression threshold
    vector<int> classIds;
    vector<float> confidences;
    vector<Rect> boxes;

    for (size_t i = 0; i < outs.size(); ++i) {
        float* data = (float*)outs[i].data;
        for (int j = 0; j < outs[i].rows; ++j, data += outs[i].cols) {
            Mat scores = outs[i].row(j).colRange(5, outs[i].cols);
            Point classIdPoint;
            double confidence;
            minMaxLoc(scores, 0, &confidence, 0, &classIdPoint);
            if (confidence > confThreshold) {
                int centerX = (int)(data[0] * frame.cols);
                int centerY = (int)(data[1] * frame.rows);
                int width = (int)(data[2] * frame.cols);
                int height = (int)(data[3] * frame.rows);
                int left = centerX - width / 2;
                int top = centerY - height / 2;

                classIds.push_back(classIdPoint.x);
                confidences.push_back((float)confidence);
                boxes.push_back(Rect(left, top, width, height));
            }
        }
    }

    // Apply non-maximum suppression to filter out overlapping boxes
    vector<int> indices;
    dnn::NMSBoxes(boxes, confidences, confThreshold, nmsThreshold, indices);

    // Draw the results
    for (size_t i = 0; i < indices.size(); ++i) {
        int idx = indices[i];
        Rect box = boxes[idx];
        if (classNames[classIds[idx]] == "person") {
            // Draw a rectangle around the detected person
            rectangle(frame, box, Scalar(0, 255, 0), 2);
            // Put label
            putText(frame, classNames[classIds[idx]], Point(box.x, box.y - 5), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 255, 0), 2);
        }
    }

    // Display the resulting image
    imshow("YOLO Human Detection", frame);
    waitKey(0);  // Wait for a key press

    // Destroy any OpenCV windows
    destroyAllWindows();

    return 0;
}
*/


/*

#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <atomic>
#include <string>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

using namespace cv;
using namespace cv::dnn;
using namespace std;

// Function to load class names from coco.names file
vector<string> loadClassNames(const string& path) {
    vector<string> classNames;
    ifstream ifs(path);
    string line;
    while (getline(ifs, line)) {
        classNames.push_back(line);
    }
    return classNames;
}

// Function to convert a standard string to a wide string
wstring toWideString(const string& str) {
    return wstring(str.begin(), str.end());
}

// Function to play sound
void playSound(const string& soundFile) {
    wstring wideSoundFile = toWideString(soundFile);
    PlaySoundW(wideSoundFile.c_str(), NULL, SND_FILENAME | SND_ASYNC);
}

// Function to capture screenshots
void captureScreenshots(int count, const Mat& frame) {
    for (int i = 0; i < count; ++i) {
        string filename = "screenshot_" + to_string(i) + ".jpg";
        imwrite(filename, frame);
        this_thread::sleep_for(chrono::milliseconds(500));  // Adjust delay as needed
    }
}

int main() {
    // Load the YOLO model
    String modelWeights = "F:/extract/opencv/sources/data/yolov4.weights";   // Path to the weights file
    String modelConfig = "F:/extract/opencv/sources/data/yolov4.cfg";        // Path to the configuration file
    String classesFile = "F:/extract/opencv/sources/data/coco.names";        // Path to the class names file

    Net net = readNetFromDarknet(modelConfig, modelWeights);
    net.setPreferableBackend(DNN_BACKEND_OPENCV);
    net.setPreferableTarget(DNN_TARGET_CPU);

    // Load class names
    vector<string> classNames = loadClassNames(classesFile);

    // Load face detection model
    CascadeClassifier faceCascade;
    if (!faceCascade.load("C:/Users/CJ/Downloads/haarcascade_frontalface_default.xml")) {  // Path to the Haar cascade file
        cout << "Error loading face cascade" << endl;
        return -1;
    }

    // Open a connection to the webcam
    VideoCapture cap(0);  // 0 is the default ID for the built-in webcam
    if (!cap.isOpened()) {
        cout << "Error: Could not open the webcam." << endl;
        return -1;
    }

    bool soundPlayed = false;

    while (true) {
        Mat frame;
        cap >> frame;  // Capture a frame from the webcam

        if (frame.empty()) {
            cout << "Error: Could not capture a frame from the webcam." << endl;
            break;
        }

        // Prepare the input blob for the network
        Mat blob = blobFromImage(frame, 1 / 255.0, Size(416, 416), Scalar(0, 0, 0), true, false);

        // Set the input blob for the network
        net.setInput(blob);

        // Forward pass: get the output layers
        vector<Mat> outs;
        vector<string> outNames = net.getUnconnectedOutLayersNames();
        net.forward(outs, outNames);

        // Post-process the detections
        float confThreshold = 0.5;  // Confidence threshold
        float nmsThreshold = 0.4;   // Non-maximum suppression threshold
        vector<int> classIds;
        vector<float> confidences;
        vector<Rect> boxes;

        for (size_t i = 0; i < outs.size(); ++i) {
            float* data = (float*)outs[i].data;
            for (int j = 0; j < outs[i].rows; ++j, data += outs[i].cols) {
                Mat scores = outs[i].row(j).colRange(5, outs[i].cols);
                Point classIdPoint;
                double confidence;
                minMaxLoc(scores, 0, &confidence, 0, &classIdPoint);
                if (confidence > confThreshold) {
                    int centerX = (int)(data[0] * frame.cols);
                    int centerY = (int)(data[1] * frame.rows);
                    int width = (int)(data[2] * frame.cols);
                    int height = (int)(data[3] * frame.rows);
                    int left = centerX - width / 2;
                    int top = centerY - height / 2;

                    classIds.push_back(classIdPoint.x);
                    confidences.push_back((float)confidence);
                    boxes.push_back(Rect(left, top, width, height));
                }
            }
        }

        // Apply non-maximum suppression to filter out overlapping boxes
        vector<int> indices;
        dnn::NMSBoxes(boxes, confidences, confThreshold, nmsThreshold, indices);

        // Draw the results
        for (size_t i = 0; i < indices.size(); ++i) {
            int idx = indices[i];
            Rect box = boxes[idx];
            if (classNames[classIds[idx]] == "person") {
                // Draw a rectangle around the detected person
                rectangle(frame, box, Scalar(0, 255, 0), 2);
                // Put label
                putText(frame, classNames[classIds[idx]], Point(box.x, box.y - 5), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 255, 0), 2);

                // Face detection within the detected person
                Rect roiRect = box;  // ROI rectangle
                if (roiRect.x < 0) roiRect.x = 0;
                if (roiRect.y < 0) roiRect.y = 0;
                if (roiRect.x + roiRect.width > frame.cols) roiRect.width = frame.cols - roiRect.x;
                if (roiRect.y + roiRect.height > frame.rows) roiRect.height = frame.rows - roiRect.y;

                Mat roi = frame(roiRect);
                vector<Rect> faces;
                faceCascade.detectMultiScale(roi, faces);

                if (!soundPlayed) {
                    // Play sound once for this detection
                    playSound("alert.wav");  // Path to the sound file
                    soundPlayed = true;
                }

                if (!faces.empty()) {
                    // Capture 5 screenshots
                    captureScreenshots(5, frame);
                }
            }
        }

        // Reset soundPlayed flag if no person detected
        if (soundPlayed && all_of(classIds.begin(), classIds.end(), [&](int id) { return classNames[id] != "person"; })) {
            soundPlayed = false;
        }

        // Display the resulting frame
        imshow("YOLO Human Detection", frame);

        // Break the loop if the 'q' key is pressed
        if (waitKey(30) == 'q') {
            break;
        }
    }

    // Release the webcam and destroy any OpenCV windows
    cap.release();
    destroyAllWindows();

    return 0;
}
*/

