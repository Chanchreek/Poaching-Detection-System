import ultralytics
from ultralytics import YOLO
model = YOLO('yolo11n.pt')
file_path = "poacher.mp4"
import cv2
cap = cv2.VideoCapture(file_path)
if not cap.isOpened():
    print("Error: Could not open the video file!")
else:
    print("Video opened successfully.")
cap = cv2.VideoCapture(file_path)

# Check if the video opened successfully
if not cap.isOpened():
    print("Error: Could not open the video.")
    exit()

# Get the video properties
frame_width = int(cap.get(cv2.CAP_PROP_FRAME_WIDTH))
frame_height = int(cap.get(cv2.CAP_PROP_FRAME_HEIGHT))
frame_rate = cap.get(cv2.CAP_PROP_FPS)  # Use the original frame rate

# Define the output video codec and file
output_video_path = '/Users/parz/Desktop/MLProjs/minor/Poaching-Detection-System/pd_detected.mp4'
fourcc = cv2.VideoWriter_fourcc(*'mp4v')
out = cv2.VideoWriter(output_video_path, fourcc, frame_rate, (frame_width, frame_height))

# Process each frame of the video
while True:
    ret, frame = cap.read()

    if not ret:
        break  # End of video

    # Perform object detection on the frame
    results = model(frame)

    # Iterate over each result in the list
    for result in results:
        boxes = result.boxes.xyxy  # Get bounding box coordinates (x_min, y_min, x_max, y_max)
        confidences = result.boxes.conf  # Confidence scores
        class_ids = result.boxes.cls  # Detected class IDs

        # Draw bounding boxes and labels for detected 'person' class (class_id == 0)
        for i in range(len(boxes)):
            if class_ids[i] == 0:  # Check for 'person' class (class_id == 0)
                # Get the bounding box coordinates
                x_min, y_min, x_max, y_max = boxes[i].int().tolist()  # Convert to integers

                # Draw rectangle and label on the frame
                cv2.rectangle(frame, (x_min, y_min), (x_max, y_max), (0, 255, 0), 2)
                cv2.putText(frame, "Potential Poacher", (x_min, y_min - 5), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)

    # Write the frame with detections to the output video
    out.write(frame)

# Release resources
cap.release()
out.release()
cv2.destroyAllWindows()

print(f"Processed video saved to {output_video_path}")