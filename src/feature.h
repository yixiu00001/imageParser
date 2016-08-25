
#ifndef _MAIN_H_
	#define _MAIN_H_
#include "main.h"
#endif
using namespace cv;
class FEATURE
{
	public:
		//print the image
		void PrintMat(Mat H1);
		//compute the lbp feature all three channel
		Mat Lbp3Channel(Mat srcImg);
		//compute the sift feature
		Mat SiftCompute(Mat srcImg);
		//compute the hog feature
		vector<float> HogCompute(Mat srcImg);
		//do pca train
		void PcaTrain(String imageListName,String modelName);
		void PcaTrain(vector<Mat>images,String modelName);
		//do pca compute
		Mat PcaCompute(Mat srcImg, String modelName);
		//do lda train
		Mat LdaTrain(String imageListName, String labelListName, String modelName);
		//do lda compute
		Mat LdaCompute(Mat srcImg, String modelName);
		//load pca or lda model
		void loadModel(const string& fileName, Mat* _eigenvalues, Mat* _eigenvectors);
		Mat pcaEigenvalues;
		Mat pcaEigenvectors;
		Mat ldaEigenvalues;
		Mat ldaEigenvectors;
};
