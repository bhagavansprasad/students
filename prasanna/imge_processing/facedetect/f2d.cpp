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
String face_cascade_name ="/home/bhagavan/sources/temp/opencv/data/haarcascades/haarcascade_frontalface_alt.xml";
String smile_cascade_name ="/home/bhagavan/sources/temp/opencv/data/haarcascades/haarcascade_smile.xml";
//String eyes_cascade_name ="/home/bhagavan/sources/temp/opencv/data/haarcascades/haarcascade_eye_tree_eyeglasses.xml";
CascadeClassifier face_cascade;
//CascadeClassifier eyes_cascade;
CascadeClassifier smile_cascade;
String window_name = "Capture - Face detection";

/** @function main */
int main( void )
{
  //  VideoCapture capture;
    Mat image;
//	string imageName("/home/bhagavan/sources/temp/opencv/samples/data/lena.jpg"); // by default				
	string imageName("/home/bhagavan/images/images1.jpeg"); // by default
    //-- 1. Load the cascades
    if( !face_cascade.load( face_cascade_name ) ){ printf("--(!)Error loading face cascade\n"); return -1; };
 //   if( !eyes_cascade.load( eyes_cascade_name ) ){ printf("--(!)Error loading eyes cascade\n"); return -1; };
	if( !smile_cascade.load( smile_cascade_name ) ){ printf("--(!)Error loading smile cascade\n"); return -1; };

    //-- 2. Read the video stream
	 image = imread(imageName.c_str(), IMREAD_COLOR);
 //   capture.open( -1 );
 //   if ( ! capture.isOpened() ) { printf("--(!)Error opening video capture\n"); return -1; }

   // while ( capture.read(frame) )
    {
        if( image.empty() )
        {
            printf(" --(!) No captured frame -- Break!");
         //   break;
        }

        //-- 3. Apply the classifier to the frame
        detectAndDisplay( image );
//	 imshow( "Display window", image ); 
	waitKey(0); // Wait for a keystroke in the window

    }
    return 0;
}

/** @function detectAndDisplay */
void detectAndDisplay( Mat image )
{
    std::vector<Rect> faces;
    Mat frame_gray;
	int count = 0;
    cvtColor( image, frame_gray, COLOR_BGR2GRAY );
    equalizeHist( frame_gray, frame_gray );

    //-- Detect faces
    face_cascade.detectMultiScale( frame_gray, faces, 1.1, 2, 0|CASCADE_SCALE_IMAGE, Size(0, 0) );

    for ( size_t i = 0; i < faces.size(); i++ )
    {
        Point center( faces[i].x + faces[i].width/2, faces[i].y + faces[i].height/2 );
        ellipse( image, center, Size( faces[i].width/2, faces[i].height/2 ), 0,	0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );

#if 1
		Mat face1ROI = frame_gray( faces[i] );
        std::vector<Rect> smiles;
        
		smile_cascade.detectMultiScale( face1ROI, smiles, 1.1, 2, 0|CASCADE_SCALE_IMAGE, Size(40, 40) );

		for ( size_t j = 0; j < smiles.size(); j++)
        {
            Point smile_center( faces[i].x + smiles[j].x + smiles[j].width/2, faces[i].y + smiles[j].y + smiles[j].height /2 );
            int radius = cvRound( (smiles[j].width + smiles[j].height)*0.25 );
            circle( image, smile_center, radius, Scalar( 255, 0, 0 ), 4, 8, 0 );
			 
        }
#endif
#if 0 	
		Mat faceROI = frame_gray( faces[i] );
        std::vector<Rect> eyes;
		
        //-- In each face, detect eyes
        eyes_cascade.detectMultiScale( faceROI, eyes, 1.1, 2, 0 |CASCADE_SCALE_IMAGE, Size(0, 0) );

        for ( size_t j = 0; j < eyes.size(); j++ )
        {
            Point eye_center( faces[i].x + eyes[j].x + eyes[j].width/2, faces[i].y + eyes[j].y + eyes[j].height/2 );
            int radius = cvRound( (eyes[j].width + eyes[j].height)*0.25 );
            circle( image, eye_center, radius, Scalar( 255, 0, 0 ), 4, 8, 0 );
			 
        }
#endif
		count++;
    }
	printf("Number of Faces in image----> %d\n",count);
    //-- Show what you got
    imshow( window_name, image );
}

