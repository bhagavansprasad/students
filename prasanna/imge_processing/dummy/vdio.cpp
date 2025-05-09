/**
 * @file objectDetection2.cpp
 * @author A. Huaman ( based in the classic facedetect.cpp in samples/c )
 * @brief A simplified version of facedetect.cpp, show how to load a cascade classifier and how to find objects (Face + eyes) in a video stream - Using LBP here
 */
#include "opencv2/objdetect.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

/** Function Headers */
void detectAndDisplay( Mat frame );
/** Global variables */
String face_cascade_name = "/home/bhagavan/sources/temp/opencv/data/haarcascades/haarcascade_frontalface_alt.xml";
//String eyes_cascade_name = "/home/bhagavan/sources/temp/opencv/data/haarcascades/haarcascade_eye_tree_eyeglasses.xml";
CascadeClassifier face_cascade;
//CascadeClassifier eyes_cascade;
String window_name = "Capture - Face detection";
/**
 * @function main
 */
int main( void )
{
//	VideoCapture capture ("/home/bhagavan/sources/temp/opencv/samples/data/768x576.avi");
//	VideoCapture capture ("/home/bhagavan/students/prasanna/myvideo.avi");

	VideoCapture capture (0);

	Mat frame;

	//-- 1. Load the cascade
	if( !face_cascade.load( face_cascade_name ) ){ printf("--(!)Error loading face cascade\n"); return -1; };

	//-- 2. Read the video stream
	// capture.open( -1 );
	if ( ! capture.isOpened() ) 
	{ printf("--(!)Error opening video capture\n"); return -1; }

	while ( capture.read(frame) )
	{
		if( frame.empty() )
		{
			printf(" --(!) No captured frame -- Break!");
			break;
		}

		//-- 3. Apply the classifier to the frame
		detectAndDisplay( frame );

		imshow( window_name, frame);
		//-- bail out if escape was pressed
		int c = waitKey(10);
		if( (char)c == 27 ) 
		{ 
			break; 
		}
		
	}
	return 0;
}

/** @function detectAndDisplay */
void detectAndDisplay( Mat image )
{
	std::vector<Rect> faces;
	Mat frame_gray;
	//	int count = 0;
//	cvtColor( image, frame_gray, COLOR_BGR2GRAY );
//	equalizeHist( frame_gray, frame_gray );

	//-- Detect faces
	face_cascade.detectMultiScale( image, faces, 1.1, 3, 0 | CASCADE_SCALE_IMAGE, Size(30, 30));

	for ( size_t i = 0; i < faces.size(); i++ )
	{
		Point center( faces[i].x + faces[i].width/2, faces[i].y + faces[i].height/2 );
		ellipse( image, center, Size( faces[i].width/2, faces[i].height/2 ), 0,	0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );

	}
	//-- Show what you got
	//imshow( window_name, image );
	
}

