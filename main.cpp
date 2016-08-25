//C++ file
/***********************************************
 *
 *      Filename: main.cpp
 *
 *        Author: yx - yixiu@inspur.com
 *   Description: the main funtion of image parser 
 *        Create: 2015-03-18 09:53:43
 * Last Modified: 2015-03-18 09:53:43
 ************************************************/

#include<stdlib.h>
#include<iostream>
//#include "src/blur.h"
#include "src/blurCombine.h"
#include "src/feature.h"
#include "src/featureCompute.h"
#ifndef _MAIN_H_
#define _MAIN_H_
#include "main.h"
#endif

//#define DOG
//#define GAU
//#define GAMMA
//#define HE
//#define HOMO
//#define LBP
#define SIFT
//#define HOG
//#define PCA
//#define LDA
//#define FILTER
//#define LBPPCA
//#define SIFTPCA
using namespace cv;  
using namespace std;
int main(int argc, char *argv[])
{

	char filename[100];
	strcpy(filename, argv[1]);
	Mat srcImg;
	srcImg = imread(filename);
	//IplImage *pSrcImage = cvLoadImage(filename, CV_LOAD_IMAGE_UNCHANGED); 
	BLUR blur;
	FEATURE feature;
	BLURCOMBINE blurCombine;
	BASE base;
	//load pcaModel and ldaModel
#ifdef PCA
	String pcaModel = "/home/yx/fr/project/imageParser/models/pca.model";
	feature.loadModel(pcaModel, &feature.pcaEigenvalues, &feature.ldaEigenvectors);
#endif
#ifdef LDA
	String ldaModel = "/home/yx/fr/project/imageParser/models/pcaLda.model";
	feature.loadModel(ldaModel, &feature.ldaEigenvalues, &feature.ldaEigenvectors);
#endif
#ifdef FILTER
	Mat filterImg;
	filterImg = blurCombine.ImgPretreatment(srcImg);
#endif
#ifdef LBPPCA
	String imageName = "/home/yx/fr/project/imageParser/list";
	String pcaModelName = "/home/yx/fr/project/imageParser/models/lbppca2.model";
	FEATURECOMPUTE featureCompute;
	featureCompute.LbpPcaTrain(imageName, pcaModelName);
#endif
#ifdef SIFTPCA
	String imageName = "/home/yx/fr/project/imageParser/list";
	String pcaModelName = "/home/yx/fr/project/imageParser/models/siftpca.model";
	FEATURECOMPUTE featureCompute;
	featureCompute.SiftPcaTrain(imageName, pcaModelName);
#endif
#ifdef HE

	const char *SrcTitle ="Source";  
	const char *HistEqualTitle = "HistEqualization"; 
	cout<<"=====HistEqual======="<<endl;
	Mat dstImg = blur.HistEqualProcess(srcImg);
	imshow(SrcTitle, srcImg);
	imshow(HistEqualTitle, dstImg);
	//IplImage *pDstImage = blur.HistEqualProcess(pSrcImage);

	//cvShowImage(pstrWindowsSrcTitle, pSrcImage);  
	//cvShowImage(pstrWindowsHisEquaTitle, pDstImage);  
#endif
#ifdef HOMO

	cout<<"=====HomomorphicFilter======="<<endl;
	Mat outImg;
	outImg = blur.HomomorphicFilter(srcImg);
	//Mat tmpImg(pDstImage);

	Print(srcImg, "HomomorphicIN");
	Print(outImg, "Homomorphic");

#endif
#ifdef LBP

	cout<<"=====LBP======="<<endl;
	Mat lbpInImg(outImg);
	Mat lbpImg ;
	lbpImg = feature.Lbp3Channel(lbpInImg);
	Print(lbpImg, "lbp");
#endif
#ifdef SIFT
	cout<<"=====SIFT======="<<endl;
	//outImg.convertTo(outImg, CV_8U, 255);
	//Mat siftInImg(outImg);
	Mat siftImg;
	siftImg = feature.SiftCompute(srcImg);
	base.PrintMat(siftImg);
	imshow("sift", siftImg);

#endif
#ifdef HOG
	cout<<"=====HOG======="<<endl;
	vector<float> des;
	Mat hogInImg(pSrcImage);
	des = feature.HogCompute(hogInImg);
	cout <<"des.size="<<des.size()<<endl;
#endif
#ifdef PCA
	cout<<"=====PCA======="<<endl;
	Mat pcaIn(pSrcImage);
	String imageName = "/home/yx/fr/project/imageParser/list";
	String pcaModelName = "/home/yx/fr/project/imageParser/models/pca.model";
	//feature.PcaTrain(imageName, pcaModelName);
	feature.PcaCompute(pcaIn, pcaModelName);
#endif
#ifdef LDA
	cout<<"=====LDA======="<<endl;
	Mat ldaIn(pSrcImage);
	String imageName = "/home/yx/fr/project/imageParser/list";
	String labelName = "/home/yx/fr/project/imageParser/label";
	String ldaPcaModelName = "/home/yx/fr/project/imageParser/models/pcaLda.model";
	//feature.LdaTrain(imageName, labelName, ldaPcaModelName);
	feature.LdaCompute(ldaIn, ldaPcaModelName);
#endif
#ifdef GAMMA
	cout<<"=====GammaCorrection======="<<endl;
	Mat &gammaIn = srcImg;

	const char *windowNameSource = "gammaSource";
	const char *windowNameGamma1 = "gamma1.0";
	const char *windowNameGamma2 = "gamma2.2";
	const char *windowNameGamma3 = "gamma1/2.2";

	gammaIn =  blur.MyGammaCorrection(gammaIn, 1.5);
	namedWindow(windowNameSource, CV_WINDOW_AUTOSIZE);
	imshow(windowNameSource, srcImg);
	namedWindow(windowNameGamma1, CV_WINDOW_AUTOSIZE);
	imshow(windowNameGamma1, gammaIn);
	gammaIn =  blur.MyGammaCorrection(gammaIn, 2.2);
	namedWindow(windowNameGamma2, CV_WINDOW_AUTOSIZE);
	imshow(windowNameGamma2, gammaIn);
	gammaIn =  blur.MyGammaCorrection(gammaIn, 1/2.2);
	namedWindow(windowNameGamma3, CV_WINDOW_AUTOSIZE);
	imshow(windowNameGamma3, gammaIn);

#endif
#ifdef GAU
	cout<<"=====GaussianBlur======"<<endl;
	Mat HEImg(pDstImage);
	Mat GaussianImg;
	blur.GaussianBlur( HEImg, GaussianImg, Size( 3, 5 ), 0, 0 );
	const char *pstrWindowsGaussianFilterTitle = "GaussianFilter";
	namedWindow(pstrWindowsGaussianFilterTitle, CV_WINDOW_AUTOSIZE);  
	imshow(pstrWindowsGaussianFilterTitle, GaussianImg);  
#endif
#ifdef DOG
	cout<<"=====DogFIlter======="<<endl;
	Mat dogImg;
	dogImg = blur.DogFilter(pDstImage);
	const char *pstrWindowsDogFilterTitle = "DOGFilter";
	namedWindow(pstrWindowsDogFilterTitle, CV_WINDOW_AUTOSIZE);  
	imshow(pstrWindowsDogFilterTitle, dogImg);  
#endif



	cvWaitKey(0);  

	//cvDestroyWindow(pstrWindowsSrcTitle);  
	//cvReleaseImage(&pSrcImage);  
	//cvDestroyWindow(pstrWindowsHisEquaTitle);  
	//cvReleaseImage(&pDstImage);  
	//cvDestroyWindow(pstrWindowsDogFilterTitle);  
	//cvReleaseImage(&dogImg);


	return 0;  

}
