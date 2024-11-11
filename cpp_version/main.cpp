/*

BEST BEST BEST FOR PHOTOS
*/
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

    // Read the image file
    String imagePath = "F:/minor/ed.jpg";  // Replace with the path to your image
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

            // Extract the scores corresponding to the predicted classes
            Mat scores = outs[i].row(j).colRange(5, outs[i].cols);

            Point classIdPoint;
            double confidence;

             // Find the class with the highest score (confidence) and its index
            minMaxLoc(scores, 0, &confidence, 0, &classIdPoint);
            
            if (confidence > confThreshold) {
                // Calculate the center, width, and height of the bounding box (normalized values from YOLO)
                int centerX = (int)(data[0] * frame.cols);   // X-coordinate of the bounding box center
                int centerY = (int)(data[1] * frame.rows);   // Y-coordinate of the bounding box center
                int width = (int)(data[2] * frame.cols);     // Width of the bounding box
                int height = (int)(data[3] * frame.rows);    // Height of the bounding box

                // Calculate the top-left corner of the bounding box
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
            putText(frame, "Potential Poacher", Point(box.x, box.y - 5), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 255, 0), 2);
        }
    }

    // Display the resulting image
    imshow("YOLO Human Detection", frame);
    waitKey(0);  // Wait for a key press

    // Destroy any OpenCV windows
    destroyAllWindows();

    return 0;
}
