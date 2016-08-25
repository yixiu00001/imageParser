//C++ file
/***********************************************
 *
 *      Filename: feature.cpp
 *
 *        Author: yx - yixiu@inspur.com
 *   Description: ---
 *        Create: 2015-04-16 14:25:47
 * Last Modified: 2015-04-16 14:25:47
 ************************************************/
#include "ldaMine.h"
#include "feature.h"
#include "lbpMine.h"
#include "base.h"
#include<iostream>
#define DIMENTIONS  7  
#define DST_HEIGHT 50
#define DST_WIDTH 50

using namespace std;
using namespace cv;
/*
*PrintMat,print the feature of input 
*In: Mat ,the input 
*/

void FEATURE::PrintMat(Mat H1)
{
	int rows = H1.rows;
	int cols = H1.cols;
	cout<<"mat rows="<<rows<<" cols="<<cols<<endl;
	for( int i = 0; i<rows; i++ )
	{
		const uchar* inData1=H1.ptr<uchar>(i);
		for(int j=0; j<cols;j++)
		{
			cout<<*inData1++<<" ";
		}
		cout<<endl;
	}
}

/*
*compare,compute the same pixels' rate  of two images
*In: H1, the first image
*    H2, the second image
*OUT:the same rate
*/
double  compare(Mat H1, Mat H2)
{

	int num =0 ;
	int rows = H1.rows;
	int cols = H1.cols;
	int h1,h2;
	cout<<"rows="<<rows<<" "<<cols<<endl;
	for( int i = 0; i<rows; i++ )
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
	return 1-num*1.0/(H1.rows*H1.cols);
}

/*
*Lbp3Channel, compute lbp fearute in three channel,and then merge them
*In: srcImg, the input image
*OUT: the lbp feature
*/
//lbp function
Mat FEATURE::Lbp3Channel(Mat srcImg)
{
	Mat grayImg;	
	int radius = 1;
	int neighbors = 8;
	vector<Mat> channels;  
	//first change to gray
	cvtColor(srcImg,  grayImg, CV_RGB2GRAY );
	Mat lbpImgGray = Mat(grayImg.rows-2*radius, grayImg.cols-2*radius,CV_8UC1, Scalar(0));
	LBPMINE::elbpCircle(grayImg,lbpImgGray , radius,neighbors);
	//imshow("graylbpCicle", lbpImgGray);

	//imshow("10", grayImg);
	split(srcImg,channels);
	grayImg = channels.at(0);
	Mat lbpImg = Mat(grayImg.rows-2*radius, grayImg.cols-2*radius,CV_8UC1, Scalar(0));
	LBPMINE::elbpCircle(grayImg,lbpImg , radius,neighbors);
	lbpImg.copyTo(channels.at(0));
	//imshow("bluelbpCircle", lbpImg);


	grayImg = channels.at(1);
	Mat lbpImgG = Mat(grayImg.rows-2*radius, grayImg.cols-2*radius,CV_8UC1, Scalar(0));
	LBPMINE::elbpCircle(grayImg,lbpImgG , radius,neighbors);
	lbpImgG.copyTo(channels.at(1));
	//imshow("greenlbpCircle", lbpImgG);

	grayImg = channels.at(2);
	Mat lbpImgR = Mat(grayImg.rows-2*radius, grayImg.cols-2*radius,CV_8UC1, Scalar(0));
	LBPMINE::elbpCircle(grayImg,lbpImgR , radius,neighbors);
	lbpImgR.copyTo(channels.at(2));
	//imshow("redlbpCircle", lbpImgR);
	double sim;
	/*
	   sim = compare(lbpImg, lbpImg);
	   cout<<"b vs b="<<sim<<endl;
	   sim = compare(lbpImg, lbpImgG);
	   cout<<"b vs g="<<sim<<endl;
	   sim = compare(lbpImg, lbpImgR);
	   cout<<"b vs r="<<sim<<endl;
	   sim = compare(lbpImgG, lbpImgR);
	   cout<<"g vs r="<<sim<<endl;
	 */
	merge(channels,lbpImg); 
	/*
	sim = compare(srcImg, lbpImg);
	cout<<"s vs lbp="<<sim<<endl;
	sim = compare(lbpImg, lbpImgGray);
	cout<<"s vs lbpGray="<<sim<<endl;
	*/
	return lbpImg;
}
/*
*SiftCompute, compute the sift feature
*In: the input image
*OUT:the sift feature of sift
*/
//Mat SiftComputeTest(Mat srcImg)
Mat FEATURE::SiftCompute(Mat srcImg)
{
	srcImg.convertTo(srcImg, CV_8U, 255);
	//cvtColor(srcImg,  srcImg, CV_RGB2GRAY );
	//srcImg.convertTo(srcImg, CV_8U);
	SiftFeatureDetector detector;  
	vector<KeyPoint> keypoints;  
	detector.detect(srcImg, keypoints);

	SiftDescriptorExtractor extractor;
	Mat descriptors;
	extractor.compute(srcImg, keypoints, descriptors);  
	//cout<<"图像特征描述矩阵大小："<<descriptors.size()  <<"，特征向量个数："<<descriptors.rows<<"，维数："<<descriptors.cols<<endl;
				      // show the keypoints on an image  
	Mat output;  
	drawKeypoints(srcImg, keypoints, output);
	//imshow("siftout", output);
	return descriptors;
}
Mat SiftComputeTest(Mat srcImg)
//Mat FEATURE::SiftCompute(Mat srcImg)
{
	
	cvtColor(srcImg,  srcImg, CV_RGB2GRAY );
	srcImg.convertTo(srcImg, CV_8U);
	imshow("src", srcImg);
	//vector<Mat> channels;  
	//split(srcImg,channels);
	//grayImg = channels.at(0);
	//grayImg.convertTo(grayImg,CV_8U);
	//特征点检测
	//SiftFeatureDetector detector;
	initModule_nonfree();//初始化模块，使用SIFT或SURF时用到  
	Ptr<FeatureDetector> detector = FeatureDetector::create( "SIFT" );//创建SIFT特征检测器  
	Ptr<DescriptorExtractor> descriptor_extractor = DescriptorExtractor::create( "SIFT" );//创建特征向量生成器 
	if( detector.empty() || descriptor_extractor.empty() )  
		cout<<"fail to create detector!"<<endl; 
	std::vector<cv::KeyPoint> keypoints;
	detector->detect(srcImg, keypoints);


	//根据特征点计算特征描述子矩阵，即特征向量矩阵  
	Mat descriptors;
	descriptor_extractor->compute( srcImg, keypoints, descriptors ); 
	cout<<"图像特征描述矩阵大小："<<descriptors.size()  <<"，特征向量个数："<<descriptors.rows<<"，维数："<<descriptors.cols<<endl;
	//imshow("dec", descriptors);

	// Add results to image and save.
	Mat dstImg;
	drawKeypoints(srcImg, keypoints, dstImg);
	//imshow("sift draw", dstImg);
	/*
	cout<<"sift rows="<<dstImg.rows<<" cols="<<dstImg.cols<<endl;
	double sim = compare(srcImg, dstImg);
	cout<<"s vs sift="<<sim<<endl;
	*/


	return descriptors;
}
/*
*HogCOmpute, compute the hog feature
*In: srcImg, the input image
*OUT:the hog feature
*/
vector<float> FEATURE::HogCompute(Mat srcImg)
{
	CvSize winSize = cvSize(60,60); 
	CvSize blockSize = cvSize(20,20);
	CvSize strideSize = cvSize(10,10); 
	CvSize cellSize = cvSize(5,5);
	int bins = 9;
	HOGDescriptor *hog= new  HOGDescriptor(winSize, blockSize, strideSize, cellSize, bins);
	vector< float >descriptors;//HOG描述向量
	CvSize winShiftSize = cvSize(10,10);//搜尋框移動位置
	CvSize paddingSize = cvSize(0,0);//補滿邊界位置
	hog->compute(srcImg, descriptors, winShiftSize, paddingSize);//調用計算函數  
	return descriptors;

}
//将给出的图像回归为值域在0~255之间的正常图像
Mat norm_0_255(const Mat& src) {
	// 构建返回图像矩阵
	Mat dst;
	switch(src.channels()) {
		case 1://根据图像通道情况选择不同的回归函数
			cv::normalize(src, dst, 0, 255, NORM_MINMAX, CV_8UC1);
			break;
		case 3:
			cv::normalize(src, dst, 0, 255, NORM_MINMAX, CV_8UC3);
			break;
		default:
			src.copyTo(dst);
			break;
	}
	return dst;
}

// 将一副图像的数据转换为Row Matrix中的一行；这样做是为了跟opencv给出的PCA类的接口对应
//Mat asRowMatrix(const Mat src, int rtype, double alpha = 1, double beta = 0)
static Mat asRowMatrix(InputArrayOfArrays src, int rtype, double alpha=1, double beta=0) 
{
    // number of samples
    size_t n = src.total();
    // return empty matrix if no matrices given
    if(n == 0)
        return Mat();
    // dimensionality of (reshaped) samples
    size_t d = src.getMat(0).total();
    // create data matrix
    Mat data((int)n, (int)d, rtype);
	BASE base;
    for(unsigned int i = 0; i < n; i++) {
        // get a hold of the current row
        Mat xi = data.row(i);
		Mat in = src.getMat(i);
		in = norm_0_255(in);
		switch(src.channels()) {
			case 3:
				cvtColor(in,  in, CV_RGB2GRAY );
				break;
			default:
				in.copyTo(in);
			break;
		}
        in.clone().reshape(1, 1).convertTo(xi, rtype, 1/255.);
		//base.PrintMat(in);
		//cout<<"channels="<<in.channels()<<" rows="<<in.rows<<" cols="<<in.cols<<endl;

        // make reshape happy by cloning for non-continuous matrices
        //src.getMat(i).reshape(1, 1).convertTo(xi, rtype, 1/255.);
		/*	
		if(out.isContinuous()) {
            out.reshape(1, 1).convertTo(xi, rtype, alpha, beta);
        } else {
            out.clone().reshape(1, 1).convertTo(xi, rtype, alpha, beta);
        }
		*/
		
	}

	return data;
}
/*
*saveModel, save the pca or lda model
*In: fileName, the model name who saved the pca or lda model
*    _eigenvalues, feature vectors
*	_eigenvectors, feature values
*/
void saveModel(const string& fileName, Mat _eigenvalues, Mat _eigenvectors )
{
	FileStorage fs(fileName, FileStorage::WRITE);
	if(!fs.isOpened())
	{
        CV_Error(CV_StsError, "File can't be opened for writing!");
	}
	fs<<"eigenvalues"<<_eigenvalues;
	fs<<"eigenvectors"<<_eigenvectors;
}
/*
*loadModel, load the model of pca or lda
*In: fileName, the model name who saved the pca or lda model
*    _eigenvalues, feature vectors
*	_eigenvectors, feature values
*/
void FEATURE::loadModel(const string& fileName, Mat* _eigenvalues, Mat* _eigenvectors)
{
    FileStorage fs(fileName, FileStorage::READ);
    if (!fs.isOpened())
       CV_Error(CV_StsError, "File can't be opened for writing!");
	fs["eigenvalues"]>>*_eigenvalues;
	fs["eigenvectors"]>>*_eigenvectors;
	
}
void FEATURE::PcaTrain(vector<Mat> images, String modelName)
{
	//the change the input image go format the Pca Input format
	Mat pcaIn = asRowMatrix(images, CV_8U);
	//Mat pcaIn = asRowMatrix(images, CV_32FC1);
	PCA pca(pcaIn, Mat(), CV_PCA_DATA_AS_ROW, 0.95);
	Mat pcaEigenvectors = pca.eigenvectors.clone();
	Mat pcaEigenvalues = pca.eigenvalues.clone();
	saveModel(modelName, pcaEigenvalues, pcaEigenvectors);
	
}
/*
*PcaTrain,train the module of pca
*In: imageListName, the list name of train images
*    modelName, the name of modelName to save the model
*/
void FEATURE::PcaTrain(String imageListName,String modelName)
{
	vector<Mat> images;
	BASE base;
	base.read_imgList(imageListName, images);
	PcaTrain(images, modelName);
}
/*
*PcaCompute,compute a set of values of linearly uncorrelated variables by principal component analysis
*In: srcImg, the image that go to compute pca
*    modelName, the name of modelName to load the model
*/
Mat FEATURE::PcaCompute(Mat srcImg, String modelName)
{
	Mat pcaEigenvalues;
	Mat pcaEigenvectors;
	//loadModel(modelName, &pcaEigenvalues, &pcaEigenvectors);

	Mat testIn,pcaIn;
	//chage the image to gray
	cvtColor(srcImg,  srcImg, CV_RGB2GRAY );
	pcaIn = norm_0_255(srcImg);
	pcaIn.reshape(1, 1).convertTo(testIn, CV_32FC1, 1/255.);

	Mat pcaRes;
	//gemm(testIn, pcaEigenvectors.reshape(0, pcaEigenvectors.cols), 1,  Mat(), 0, pcaRes);
	gemm(testIn, pcaEigenvectors.reshape(0, pcaEigenvectors.cols), 1,  Mat(), 0, pcaRes);
	cout<<"pcaRes rows="<< pcaRes.rows<<" cols="<<pcaRes.cols<<endl<<pcaRes<<endl;

	return pcaRes;
	
}
/*
*LdaTrain,train the module of lda
*In: imageListName, the list name of train images
     labelListName, the list name of train labels
*    modelName, the name of modelName to save the model
*/
Mat FEATURE::LdaTrain(String imageListName, String labelListName, String modelName)
{
	//train pca
	vector<Mat>images;
	vector<int>labels;
	BASE base;
	base.read_imgList(imageListName, images);
	Mat pcaIn = asRowMatrix(images, CV_32FC1);
	PCA pca(pcaIn, Mat(), CV_PCA_DATA_AS_ROW, 0.95); // trackbar is initially set here, also this is a common value for retainedVariance
	Mat point = pca.project(pcaIn);
	Mat pcaEigenvectors = pca.eigenvectors.clone();
	Mat pcaEigenvalues = pca.eigenvalues.clone();
	saveModel("models/pca.res", pcaEigenvalues, pcaEigenvectors);
	
	//train lda
	
	base.read_labelList(labelListName, labels);
	LDAMine lda = LDAMine(point, labels);
	Mat ldaEigenvectors = lda.eigenvectors().clone();
	Mat ldaEigenvalues = lda.eigenvalues().clone();
	saveModel("models/lda.res", ldaEigenvalues, ldaEigenvectors);

	//get pca*lda
	Mat pcaldaVec;
	Mat ldaVecTrans ;
	ldaEigenvectors.convertTo(ldaVecTrans, CV_32FC1);
	gemm(pcaEigenvectors.reshape(0,pcaEigenvectors.cols), ldaVecTrans,1,Mat(), 0, pcaldaVec);
	saveModel(modelName, Mat(), pcaldaVec);

	return point;
}
/* --------------------------------------------------------------------------*/
/**
* @Name:  LdaCompute,compute a set of values of linearly uncorrelated variables by Linear discriminant analysis
*
* @Param: srcImg ,the image that go to compute lda
* @Param: modelName, the name of modelName to load the model
*
* @Returns:   the result of the lda feature
*/
/* ----------------------------------------------------------------------------*/
Mat FEATURE::LdaCompute(Mat srcImg, String modelName)
{
	Mat pcaLdaEigenvalues;
	Mat pcaLdaEigenvectors;
	//loadModel(modelName, &pcaLdaEigenvalues, &pcaLdaEigenvectors);

	Mat testIn,pcaIn;
	cvtColor(srcImg,  srcImg, CV_RGB2GRAY );
	pcaIn = norm_0_255(srcImg);
	pcaIn.reshape(1, 1).convertTo(testIn, CV_32FC1, 1/255.);

	Mat ldaRes;
	gemm(testIn, ldaEigenvectors, 1,  Mat(), 0, ldaRes);
	cout<<"pcaLdaRes rows="<< ldaRes.rows<<" cols="<<ldaRes.cols<<endl<<ldaRes<<endl;

	return ldaRes;
}
	
