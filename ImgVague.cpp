//#include <opencv2/opencv.hpp> 
//#include <iostream> 
//using namespace cv;
//
//int main(int argc, char** argv) {
//	Mat src, dst, gray;
//	src = imread("E:/opencv_yao/Img_opencv/lena.jpg");
//	if (!src.data) {
//		printf("could not load image...\n");
//		return -1;
//	}
//	char inputgray_title[] = "input image";
//	char output_title[] = "blur image";
//	cvtColor(src,gray,CV_RGB2GRAY);
//	namedWindow(inputgray_title, CV_WINDOW_AUTOSIZE);
//	namedWindow(output_title, CV_WINDOW_AUTOSIZE);
//	imshow("yuantu",src);
//	imshow(inputgray_title, gray);
//
//	//均值模糊API
//	blur(gray, dst, Size(11, 11), Point(-1, -1));
//	imshow(output_title, dst);
//
//	Mat gblur;
//	//高斯模糊API
//	GaussianBlur(gray, gblur, Size(11, 11), 4, 4);
//	imshow("gaussian blur", gblur);
//
//
//	waitKey(0);
//	return 0;
//}
#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>
using namespace cv;
using namespace std;


const int g_nTrackbarMaxValue = 9;     //定义轨迹条最大值
int g_nTrackbarValue;                   //定义轨迹条初始值,0-9
int g_nKernelValue;                     //定义kernel尺寸
Mat src, dst,gray;

//均值滤波
void on_kernelTrackbar(int,void *)
{
	//根据输入值重新计算kernel尺寸
	g_nKernelValue = g_nTrackbarValue * 2 + 1;

	//均值滤波函数
	blur(gray, dst, Size(g_nKernelValue, g_nKernelValue));

	imshow("均值滤波", dst);
}

//高斯滤波
void on_kernelTrackbar2(int, void*)
{
	//根据输入值重新计算kernel尺寸
	g_nKernelValue = g_nTrackbarValue * 2 + 1;

	//均值滤波函数
	GaussianBlur(gray, dst, Size(g_nKernelValue, g_nKernelValue),11,11);

	imshow("均值滤波", dst);
}

int main()
{

	//原图
	src = imread("E:/opencv_yao/Img_opencv/lena.jpg",IMREAD_UNCHANGED);

	if (!src.data)
	{
		cout << "load error" << endl;
		return -1;
	}
	imshow("yuantu",src);
	cvtColor(src,gray,CV_BGR2GRAY);
	namedWindow("均值滤波", WINDOW_AUTOSIZE);   //定义滤波后图像显示窗口属性
	//定义轨迹条名称和最大值
	char kernelName[20];
	sprintf(kernelName, "kernel %d", g_nTrackbarMaxValue);

	//创建轨迹条
	createTrackbar(kernelName, "均值滤波", &g_nTrackbarValue, g_nTrackbarMaxValue, on_kernelTrackbar2);
	on_kernelTrackbar2(g_nTrackbarValue, 0);


	waitKey(0);
	return 0;
}