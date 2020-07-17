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
//	//��ֵģ��API
//	blur(gray, dst, Size(11, 11), Point(-1, -1));
//	imshow(output_title, dst);
//
//	Mat gblur;
//	//��˹ģ��API
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


const int g_nTrackbarMaxValue = 9;     //����켣�����ֵ
int g_nTrackbarValue;                   //����켣����ʼֵ,0-9
int g_nKernelValue;                     //����kernel�ߴ�
Mat src, dst,gray;

//��ֵ�˲�
void on_kernelTrackbar(int,void *)
{
	//��������ֵ���¼���kernel�ߴ�
	g_nKernelValue = g_nTrackbarValue * 2 + 1;

	//��ֵ�˲�����
	blur(gray, dst, Size(g_nKernelValue, g_nKernelValue));

	imshow("��ֵ�˲�", dst);
}

//��˹�˲�
void on_kernelTrackbar2(int, void*)
{
	//��������ֵ���¼���kernel�ߴ�
	g_nKernelValue = g_nTrackbarValue * 2 + 1;

	//��ֵ�˲�����
	GaussianBlur(gray, dst, Size(g_nKernelValue, g_nKernelValue),11,11);

	imshow("��ֵ�˲�", dst);
}

int main()
{

	//ԭͼ
	src = imread("E:/opencv_yao/Img_opencv/lena.jpg",IMREAD_UNCHANGED);

	if (!src.data)
	{
		cout << "load error" << endl;
		return -1;
	}
	imshow("yuantu",src);
	cvtColor(src,gray,CV_BGR2GRAY);
	namedWindow("��ֵ�˲�", WINDOW_AUTOSIZE);   //�����˲���ͼ����ʾ��������
	//����켣�����ƺ����ֵ
	char kernelName[20];
	sprintf(kernelName, "kernel %d", g_nTrackbarMaxValue);

	//�����켣��
	createTrackbar(kernelName, "��ֵ�˲�", &g_nTrackbarValue, g_nTrackbarMaxValue, on_kernelTrackbar2);
	on_kernelTrackbar2(g_nTrackbarValue, 0);


	waitKey(0);
	return 0;
}