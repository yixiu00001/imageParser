//C++ file
/***********************************************
 *
 *      Filename: blur.cpp
 *
 *        Author: yx - yixiu@inspur.com
 *   Description: ---
 *        Create: 2015-04-02 16:32:41
 * Last Modified: 2015-04-02 16:32:41
 ************************************************/
#include "blur.h"
#include <cmath>
#include <vector>
#include <cstdlib> 
#include <string>
#include "../clcnst/clcnst.h"
using namespace std;
using namespace cv;
/* --------------------------------------------------------------------------*/
/**
* @Name:  Hist Equal ,first split the channel,then compter each channel,last,merge the three channel
*
* @Param: src input image
*
* @Returns:  the image after hist equal  
*/
/* ----------------------------------------------------------------------------*/
Mat BLUR::HistEqualProcess(IplImage * src)
{
	IplImage *pEquaImage = cvCreateImage(cvGetSize(src), src->depth, 3);  

	const int MAX_CHANNEL = 4;  
	IplImage *pImageChannel[MAX_CHANNEL] = {NULL};  

	int i;  
	for (i = 0; i < src->nChannels; i++)  
		pImageChannel[i] = cvCreateImage(cvGetSize(src), src->depth, 1);  
	//split the channels
	cvSplit(src, pImageChannel[0], pImageChannel[1], pImageChannel[2], pImageChannel[3]);  

	//compute each channel
	for (i = 0; i < src->nChannels; i++)  
		cvEqualizeHist(pImageChannel[i], pImageChannel[i]);  
	//merge the three channel
	cvMerge(pImageChannel[0], pImageChannel[1], pImageChannel[2], pImageChannel[3], pEquaImage);  

	for (i = 0; i < src->nChannels; i++)  
		cvReleaseImage(&pImageChannel[i]);  
	Mat dstImg(pEquaImage);

	return dstImg; 
}
/* --------------------------------------------------------------------------*/
/**
* @Name:  HistEqualProcess, do hist equal
*
* @Param: srcImg , type Mat input
*
* @Returns:   type Mat image after hist equal
*/
/* ----------------------------------------------------------------------------*/
Mat BLUR::HistEqualProcess(Mat srcImg)
{
	//store the three channel image
	vector<Mat> bgr;
	split(srcImg, bgr);

	for(int i=0; i<srcImg.channels(); i++)
	{
		//cal the hist
		equalizeHist(bgr[i], bgr[i]);  
	}
	Mat dstImg;
	merge(bgr, dstImg);
	return dstImg;
}
/* --------------------------------------------------------------------------*/
/**
* @Name:  DogFilter , difference of Gaussian
*
* @Param: srcImg ,input image type Mat
*
* @Returns:   the result after compute dogFilter
*/
/* ----------------------------------------------------------------------------*/
Mat  BLUR::DogFilter(Mat srcImg )
{
	//IplImage *grayEImg;
	Mat grayImg;
	cvtColor(srcImg ,grayImg,CV_BGR2GRAY);
	//imshow("gray", grayImg);
	Mat dstImg, dstImg2, dogImg;
	GaussianBlur(grayImg,dstImg,Size(5, 11),0);
	GaussianBlur(dstImg,dstImg2,Size(5, 11),0);
	subtract(dstImg, dstImg2, dogImg);
	//dogImg = dstImg - dstImg2;
	normalize(dogImg,dogImg,255,0,CV_MINMAX);
	//cvWaitKey(0);  

	return dogImg;
}
//gamma correction
/* --------------------------------------------------------------------------*/
/**
* @Name:  MyGammaCorrection
*
* @Param: src , input image type Mat
* @Param: fGamma ,correction variable
*
* @Returns:   the image after gamma correction
*/
/* ----------------------------------------------------------------------------*/
Mat& BLUR::MyGammaCorrection(Mat& src, float fGamma)    
{    
	CV_Assert(src.data);   

	// accept only char type matrices    
	CV_Assert(src.depth() != sizeof(uchar));    
	// build look up table    
	unsigned char lut[256];    
	for( int i = 0; i < 256; i++ )    
	{    
		lut[i] = pow((float)(i/255.0), fGamma) * 255.0;    
	}    
	//先归一化，i/255,然后进行预补偿(i/255)^fGamma,最后进行反归一化(i/255)^fGamma*255  
	const int channels = src.channels();    
	switch(channels)    
	{    
		case 1:    
			{    
				//运用迭代器访问矩阵元素  
				MatIterator_<uchar> it, end;    
				for( it = src.begin<uchar>(), end = src.end<uchar>(); it != end; it++ )    
					//*it = pow((float)(((*it))/255.0), fGamma) * 255.0;    
					*it = lut[(*it)];    
				break;    
			}    
		case 3:     
			{    
				MatIterator_<Vec3b> it, end;   

				for( it = src.begin<Vec3b>(), end = src.end<Vec3b>(); it != end; it++ )    
				{    
					//(*it)[0] = pow((float)(((*it)[0])/255.0), fGamma) * 255.0;    
					//(*it)[1] = pow((float)(((*it)[1])/255.0), fGamma) * 255.0;    
					//(*it)[2] = pow((float)(((*it)[2])/255.0), fGamma) * 255.0;    
					(*it)[0] = lut[((*it)[0])];    
					(*it)[1] = lut[((*it)[1])];    
					(*it)[2] = lut[((*it)[2])];    
				}    
				break;    
			}    
	}    
	return src;       
}    

/* --------------------------------------------------------------------------*/
/**
* @Name: HomomorphicFilter 
*
* @Param: src ,input image type Mat
*
* @Returns:   the result image after homomorphic filter
*/
/* ----------------------------------------------------------------------------*/
Mat  BLUR::HomomorphicFilter (Mat src)
{
	int width, height, channel;
	width = src.cols;
	height = src.rows;
	channel = src.channels();
	//normalize
	src.convertTo(src, CV_32FC3, 1.0/255.0);

	float lower, upper, threshold;
	lower = 0.5f;
	upper = 1.5f;
	//upper = 2.0f;
	threshold = 7.5f;

	vector<cv::Mat> chs, spc(channel, cv::Mat(height, width, CV_32FC1));
	split(src, chs);
	//compute the color image, computer three channels
	for(int c=0; c<channel; c++)
	{
		dct(chs[c], spc[c]);
		clcnst::hef(spc[c], spc[c], lower, upper, threshold);
		idct(spc[c], chs[c]);
	}

	Mat out;
	//merge the three channel into one image
	merge(chs, out);

	return out;
}
