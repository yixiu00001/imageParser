#ifndef _MAIN_H_
	#define _MAIN_H_
#include "main.h"
#endif
using namespace cv;

class BLUR
{
	public:
		//do hist equal
		Mat HistEqualProcess(IplImage * src);
		Mat HistEqualProcess(Mat src);
		//do difference of gaussian filter
		Mat  DogFilter(Mat srcImg )  ;
		//do gamma correnction
		Mat& MyGammaCorrection(Mat& srcImg, float fGamma);    
		//do homomorphic filter
		Mat  HomomorphicFilter (Mat srcImg);
		//compute the lbp feature in three channels
		Mat Lbp3Channel(Mat srcImg);
};
