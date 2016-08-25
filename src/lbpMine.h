#ifndef _MAIN_H_
	#define _MAIN_H_
#include "main.h"
#endif
using namespace cv;
class LBPMINE
{

	public :
		static void elbpCircle(Mat& src, Mat &dst, int radius, int neighbors);
		static void elbpRectangle(Mat& src, Mat &dst) ;
};
