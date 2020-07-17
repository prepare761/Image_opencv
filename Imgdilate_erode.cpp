#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "highgui.h"
#include <stdlib.h>
#include <stdio.h>

using namespace cv;

/// 全局变量
Mat src, erosion_dst, dilation_dst;

int erosion_elem = 0;
int erosion_size = 0;
int dilation_elem = 0;
int dilation_size = 0;
int const max_elem = 2;
int const max_kernel_size = 21;

/* Function Headers */
void Erosion( int, void* );
void Dilation( int, void* );

/* @function main */
int main( int argc, char** argv )
{
	/// Load 图像
	src = imread("E:/opencv_yao/Img_opencv/pic1.png");

	if( !src.data )
	{ return -1; }

	/// 创建显示窗口
	namedWindow( "Erosion Demo", CV_WINDOW_AUTOSIZE );
	namedWindow( "Dilation Demo", CV_WINDOW_AUTOSIZE );
	cvMoveWindow( "Dilation Demo", src.cols, 0 );

	/// 创建腐蚀 Trackbar
	createTrackbar( "Element:\n 0: Rect \n 1: Cross \n 2: Ellipse", "Erosion Demo",
		&erosion_elem, max_elem,
		Erosion );

	createTrackbar( "Kernel size:\n 2n +1", "Erosion Demo",
		&erosion_size, max_kernel_size,
		Erosion );

	/// 创建膨胀 Trackbar
	createTrackbar( "Element:\n 0: Rect \n 1: Cross \n 2: Ellipse", "Dilation Demo",
		&dilation_elem, max_elem,
		Dilation );

	createTrackbar( "Kernel size:\n 2n +1", "Dilation Demo",
		&dilation_size, max_kernel_size,
		Dilation );

	/// Default start
	Erosion( 0, 0 );
	Dilation( 0, 0 );

	waitKey(0);
	return 0;
}

/*  @function Erosion  */
void Erosion( int, void* )
{
	int erosion_type;
	if( erosion_elem == 0 ){ erosion_type = MORPH_RECT; }
	else if( erosion_elem == 1 ){ erosion_type = MORPH_CROSS; }
	else if( erosion_elem == 2) { erosion_type = MORPH_ELLIPSE; }

	Mat element = getStructuringElement( erosion_type,
		Size( 2*erosion_size + 1, 2*erosion_size+1 ),
		Point( erosion_size, erosion_size ) );

	/// 腐蚀操作
	erode( src, erosion_dst, element );
	imshow( "Erosion Demo", erosion_dst );
}

/* @function Dilation */
void Dilation( int, void* )
{
	int dilation_type;
	if( dilation_elem == 0 ){ dilation_type = MORPH_RECT; }
	else if( dilation_elem == 1 ){ dilation_type = MORPH_CROSS; }
	else if( dilation_elem == 2) { dilation_type = MORPH_ELLIPSE; }

	Mat element = getStructuringElement( dilation_type,
		Size( 2*dilation_size + 1, 2*dilation_size+1 ),
		Point( dilation_size, dilation_size ) );
	///膨胀操作
	dilate( src, dilation_dst, element );
	imshow( "Dilation Demo", dilation_dst );
}
//高级形态学转换
//#include <opencv2/opencv.hpp>
//#include <iostream>
//
//using namespace std;
//using namespace cv;
//
//int main() 
//{
//	Mat src, grayImg, binImg, dest;
//
//	src = imread("E:/opencv_yao/Img_opencv/shuipingchuizhi.png");
//	if (!src.data) 
//	{
//		cout << "图片打开失败!" << endl;
//		return -1;
//	}
//	namedWindow("原图像", CV_WINDOW_AUTOSIZE);
//	imshow("原图像", src);
//
//	cvtColor(src, grayImg, CV_RGB2GRAY);
//	namedWindow("灰度图", CV_WINDOW_AUTOSIZE);
//	imshow("灰度图", grayImg);
//
//	adaptiveThreshold(~grayImg, binImg, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 15, -2);
//	namedWindow("二值图像", CV_WINDOW_AUTOSIZE);
//	imshow("二值图像", binImg);
//
//	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3),Point(-1,-1));
//	morphologyEx(binImg, dest, MORPH_OPEN, kernel,Point(-1,-1));
//	namedWindow("最终结果", CV_WINDOW_AUTOSIZE);
//	//blur(~dest,dest,Size(3,3),Point(-1,-1));
//	imshow("最终结果", dest);
//	waitKey(0);
//	return 0;
//}