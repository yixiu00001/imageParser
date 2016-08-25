//C++ file
/***********************************************
 *
 *      Filename: base.cpp
 *
 *        Author: yx - yixiu@inspur.com
 *   Description: ---
 *        Create: 2015-04-22 16:32:41
 * Last Modified: 2015-04-22 16:32:41
 ************************************************/
#include "blur.h"
#include "base.h"
#include<fstream>
#include<sstream>
using namespace std;
using namespace cv;
/* --------------------------------------------------------------------------*/
/**
* @Name:  PrintMat
*
* @Param: src, the input image that to print its pixal
*/
/* ----------------------------------------------------------------------------*/
void BASE::PrintMat(Mat src)
{
	int rows,cols;
	rows = src.rows;
	cols = src.cols;
	cout<<"mat rows="<<rows<<" cols="<<cols<<endl;
	for( int i = 0; i<rows; i++ )
	{
		const uchar* inData1=src.ptr<uchar>(i);
		for(int j=0; j<cols;j++)
		{
			cout<<float(*inData1++)<<" ";
		}
		cout<<endl;
	}

}

/* --------------------------------------------------------------------------*/
/**
* @Name:  Print ,show the image in window
*
* @Param: name, the window name
* @Param: srcImg, the image that to show
*/
/* ----------------------------------------------------------------------------*/
void BASE::Print(const char* name, Mat srcImg)
{
	namedWindow(name, CV_WINDOW_AUTOSIZE);
	imshow(name, srcImg);
}

/* --------------------------------------------------------------------------*/
/**
* @Name:  CompareMat
*
* @Param: H1 ,the variable 1
* @Param: H2 ,the variable 2
*
* @Returns:   the similar of two inputs
*/
/* ----------------------------------------------------------------------------*/
float BASE::CompareMat(Mat H1, Mat H2)
{
	int num, rows, cols, h1, h2;
	num = 0;
	rows = H1.rows;
	cols = H1.cols;

	cout<<"rows="<<rows<<" cols="<<cols<<endl;
	for(int i=0; i<rows;i++)
	{
		const uchar* inData1=H1.ptr<uchar>(i);
		const uchar* inData2=H2.ptr<uchar>(i);
		for(int j=0; j<cols;j++)
		{
			h1 = *inData1++;
			h2 = *inData2++;
			if(h1!=h2)
				num++;
		}
	}
	return 1-num*1.0/(rows*cols);
}


/*
*read_imgList, read the image list ,and put the image into a vector
*In: filename, the imageList name
*    images, the vector to store the Mat image
*/
void BASE::read_imgList(const string& filename, vector<Mat>& images) {
    std::ifstream file(filename.c_str(), ifstream::in);
    if (!file) {
        string error_message = "No valid input file was given, please check the given filename.";
        CV_Error(CV_StsBadArg, error_message);
    }
    string line;
    while (getline(file, line)) {
		Mat data = imread(line);
		//Mat dst_img_rsize(DST_WIDTH,DST_HEIGHT,data.type());
		//resize(data,dst_img_rsize,dst_img_rsize.size(),0,0,INTER_LINEAR);
        images.push_back(data);
    }
}
/*
*read_labelList, read the list of label,who used in lda train
*In: filename, the name of labelList
*    labels, the vector to store the label
*/
void BASE::read_labelList(const string& filename, vector<int> &labels)
{
    std::ifstream file(filename.c_str(), ifstream::in);
    if (!file) {
        string error_message = "No valid input file was given, please check the given filename.";
        CV_Error(CV_StsBadArg, error_message);
    }
    string line;
    while (getline(file, line)) {
		labels.push_back(atoi(line.c_str()));
	//	cout<<"label="<<atoi(line.c_str())<<endl;
	}
	
}
