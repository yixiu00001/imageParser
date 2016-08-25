#ifndef _MAIN_H_
	#define _MAIN_H_
#include "main.h"
#endif
using namespace cv;

class BASE
{
	public:	
		//print the image in pixal
		void PrintMat(Mat src);
		//show the image in window
		void Print(const char* name, Mat srcImg);
		//compare the same pixal rates of the two inputs
		float CompareMat(Mat H1, Mat H2);
		//read the image 
		void read_imgList(const string& filename, vector<Mat>& images);
		//read the label
		void read_labelList(const string& filename, vector<int> &labels);
};
