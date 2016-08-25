//C++ file
/***********************************************
 *
 *      Filename: featureCompute.cpp
 *
 *        Author: yx - yixiu@inspur.com
 *   Description: ---
 *        Create: 2015-05-18 8:25:47
 * Last Modified: 2015-05-18 8:25:47
 ************************************************/
#include "featureCompute.h"
#include "feature.h"
#include "blurCombine.h"
#include<iostream>
using namespace std;
using namespace cv;

/* --------------------------------------------------------------------------*/
/**
* @Name:  LbpPcaTrain
*
* @Param: imageListName, the image list input to train the model
* @Param: modelName , the name to save the model
*/
/* ----------------------------------------------------------------------------*/
void FEATURECOMPUTE::LbpPcaTrain(String imageListName, String modelName)
{
	FEATURE feature;
	BASE base;
	BLURCOMBINE blurCombine;
	vector<Mat> images;
	vector<Mat> imagesDeal;
	base.read_imgList(imageListName, images);

	size_t num = images.size();
	for(unsigned int i=0; i<num; i++)
	{
		Mat tmpImg = images[i];
		Mat tmp = blurCombine.ImgPretreatment(tmpImg);
		Mat lbp = feature.Lbp3Channel(tmp);
		//base.PrintMat(lbp);
		imagesDeal.push_back(lbp);
	}
	feature.PcaTrain(imagesDeal, modelName);
	cout<<"lbppca end!"<<endl;
}

/* --------------------------------------------------------------------------*/
/**
* @Name:  SiftPcaTrain
*
* @Param: imageListName, the image list input to train the model
* @Param: modelName, the name to save the model
*/
/* ----------------------------------------------------------------------------*/
void FEATURECOMPUTE::SiftPcaTrain(String imageListName, String modelName)
{
	FEATURE feature;
	BASE base;
	BLURCOMBINE blurCombine;
	vector<Mat> images;
	vector<Mat> imagesDeal;
	base.read_imgList(imageListName, images);

	size_t num = images.size();
	for(unsigned int i=0; i<num; i++)
	{
		Mat tmpImg = images[i];
		Mat tmp = blurCombine.ImgPretreatment(tmpImg);
		//base.PrintMat(tmp);
		Mat sift = feature.SiftCompute(tmp);
		imagesDeal.push_back(sift);
	}
	feature.PcaTrain(imagesDeal, modelName);
	cout<<"siftpca end!"<<endl;
}

