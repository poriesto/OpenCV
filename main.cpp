/*OpenCV write video from camera to file
 * main.cpp
 *
 *  Created on: Mar 19, 2014
 *      Author: poriesto
 */
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;

void VideoFromCameraToFile()
    {
        cvNamedWindow("capture");
        CvCapture *capture = cvCreateCameraCapture(CV_CAP_ANY);
        assert(capture != 0);
        const char *filename = "1.avi";
        double fps = 15;
        CvSize size = cvSize(640, 480);
        CvVideoWriter *writer = cvCreateVideoWriter(
                    filename,
                    CV_FOURCC('M', 'P', '4', '2' ),
                    fps,
                    size);
        assert(writer != 0);
        IplImage *frame = 0;
        while(true)
        {
            frame = cvQueryFrame(capture);
            cvWriteFrame(writer, frame);
            cvShowImage("capture", frame);
            char c = cvWaitKey(1);
                            if (c == 27) 
                            	{ // если нажата ESC - выходим
                                    break;
                            	}
        }
        cvReleaseCapture( &capture );
        cvReleaseVideoWriter(&writer);
        cvDestroyWindow("capture");
    }
void VideoFromCamera()
    {
	cvNamedWindow("capture");
	CvCapture *capture = cvCreateCameraCapture(CV_CAP_ANY);
	assert(capture != 0);
        IplImage *frame = 0;
	while(true){
	    frame = cvQueryFrame(capture);
	    cvShowImage("capture", frame);
	    char c = cvWaitKey(1);
		if(c == 27) break;
	}
	cvReleaseCapture(&capture);
	cvDestroyWindow("capture");
    }


int main()
    {
		int choice;
		cout << "Chose action(1 - picture from camera, 2 - picture from camera with writing to file)";
		cin >> choice;
		if(choice == 1) VideoFromCamera();
		else if(choice == 2) VideoFromCameraToFile();
		return 0;
    }
