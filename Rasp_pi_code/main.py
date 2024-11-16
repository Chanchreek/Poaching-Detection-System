from picamera2 import Picamera2
from picamera2.encoders import H264Encoder
from picamera2.outputs import FfmpegOutput
from gpiozero import MotionSensor
import time

def main():
    pir = MotionSensor(4)  # Set up the PIR sensor on GPIO pin 4

    picam2 = Picamera2()
    picam2.configure(picam2.create_video_configuration())  # Configure for video recording
    encoder = H264Encoder(10000000)
    video_output = FfmpegOutput("/add/the/output/path/poacher.mp4") #Add the Video path here 
    picam2.start()

    start_time = time.time()  # Start the timer
    total_duration = 30  # Total duration in seconds

    try:
        while time.time() - start_time < total_duration:  # Loop until 1 minute
            print("Waiting for motion...")
            pir.wait_for_motion()  # Blocks until motion is detected
            print("Motion detected! Starting video recording.")
            
            picam2.start_recording(encoder, output=video_output)
            time.sleep(total_duration)  # Recording duration in seconds
            picam2.stop_recording()
            print("Recording finished.")
            
            # Optional: Delay before checking for the next motion
            # time.sleep(5)

    except KeyboardInterrupt:
        print("Program interrupted. Cleaning up...")
    finally:
        picam2.stop()

if __name__ == '__main__':
    main()
