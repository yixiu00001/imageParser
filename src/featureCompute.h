#ifndef _MAIN_H_
	#define _MAIN_H_
#include "main.h"
#endif
using namespace cv;
class FEATURECOMPUTE
{
	public:
		void LbpPcaTrain(String imageListName, String modelName);
		Mat LbpPcaCompute(Mat srcImg);
		void SiftPcaTrain(String imageListName, String modelName);
		Mat SiftPcaCompute(Mat srcImg);
		Mat combineFeature(Mat H1, Mat H2);
};
