#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    //VideoCapture cap("/home/bhagavan/sources/temp/opencv/samples/data/768x576.avi"); // open the video camera no. 0

//    VideoCapture cap("/home/bhagavan/students/prasanna/sixth.flv"); // 
    
    VideoCapture cap(0); // 
	
	if (!cap.isOpened())  // if not success, exit program
    {
        cout << "ERROR: Cannot open the video file" << endl;
        return -1;
    }

 namedWindow("MyVideo",CV_WINDOW_AUTOSIZE); //create a window called "MyVideo"

   double dWidth = cap.get(CV_CAP_PROP_FRAME_WIDTH); //get the width of frames of the video
   double dHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT); //get the height of frames of the video

   cout << "Frame Size = " << dWidth << "x" << dHeight << endl;

   Size frameSize(static_cast<int>(dWidth), static_cast<int>(dHeight));

 //VideoWriter oVideoWriter("/home/bhagavan/students/prasanna/myvideo.avi", CV_FOURCC('P', 'I', 'M', '1'), 20, frameSize, true); //initialize the VideoWriter object 


 VideoWriter oVideoWriter("myvideo.avi", CV_FOURCC('P', 'I', 'M', '1'), 20, frameSize, true); //initialize the VideoWriter object 
	
	if ( !oVideoWriter.isOpened() ) //if not initialize the VideoWriter successfully, exit the program
   {
cout << "ERROR: Failed to write the video" << endl;
return -1;
   }

    while (1)
    {

        Mat frame;

        bool bSuccess = cap.read(frame); // read a new frame from video

        if (!bSuccess) //if not success, break loop
{
             cout << "ERROR: Cannot read a frame from video file" << endl;
             break;
        }

oVideoWriter.write(frame); //writer the frame into the file

        imshow("MyVideo", frame); //show the frame in "MyVideo" window

        if (waitKey(10) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
       {
            cout << "esc key is pressed by user" << endl;
            break; 
       }
    }

    return 0;

}
