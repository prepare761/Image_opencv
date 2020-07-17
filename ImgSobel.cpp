#include "core/core.hpp"   
#include "highgui/highgui.hpp"   
#include "imgproc/imgproc.hpp"   
#include "iostream" 
#include <math.h>

using namespace cv;

int main(int argc, char *argv[])
{
	Mat src,dst,gray_src;
	src = imread("E:/opencv_yao/Img_opencv/lena.jpg");
	if (!src.data)
	{
		return -1;
	}
	char INPUT_TITLE[]="input image";
	char OUTPUT_TITLE[]="sobel demo";
	namedWindow(INPUT_TITLE,CV_WINDOW_AUTOSIZE);
	namedWindow(OUTPUT_TITLE,CV_WINDOW_AUTOSIZE);
	imshow(INPUT_TITLE,src);

	GaussianBlur(src,dst,Size(3,3),0,0);
	cvtColor(dst,gray_src,CV_BGR2GRAY);
	imshow("gray_image",gray_src);

	Mat xgrad,ygrad;
	Scharr(gray_src,xgrad,CV_16S,1,0);
	Scharr(gray_src,ygrad,CV_16S,0,1);
	/*Sobel(gray_src,xgrad,CV_16S, 1, 0, 3);
	Sobel(gray_src,ygrad,CV_16S, 0, 1, 3);*/
	convertScaleAbs(xgrad,xgrad);
	convertScaleAbs(ygrad,ygrad);
	imshow("xgrad",xgrad);
	imshow("ygrad",ygrad);

	/*Mat finalResult;
	addWeighted(xgrad,0.5,ygrad,0.5,0,finalResult);
	imshow("final",finalResult);*/

	Mat xygrad = Mat(xgrad.size(),xgrad.type());
	int rows = ygrad.rows;
	int cols = xgrad.cols;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			int x= xgrad.at<uchar>(i,j); 
			int y = ygrad.at<uchar>(i,j);
			int xy =x +y;
			xygrad.at<uchar>(i,j) = saturate_cast<uchar>(xy);
		}
	}
	imshow("final",xygrad);
	waitKey(0);
	return 0;
}