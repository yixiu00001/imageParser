//C++ file
/***********************************************
 *
 *      Filename: blurcombine.cpp
 *
 *        Author: yx - yixiu@inspur.com
 *   Description: ---
 *        Create: 2015-05-15 11:22:41
 * Last Modified: 2015-04-02 11:22:41
 ************************************************/
#include "blurCombine.h"

using namespace std;
using namespace cv;
Mat BLURCOMBINE::ImgPretreatment(Mat srcImg)
{
	BLUR blur;
	BASE base;
	Mat histOutImg;
	Mat homoOutImg;
	histOutImg= blur.HistEqualProcess(srcImg);
	homoOutImg = blur.HomomorphicFilter(histOutImg);

	//base.Print("source", srcImg);
	//base.Print("hist", histOutImg);
	//base.Print("homo", homoOutImg);

	return homoOutImg;
}
