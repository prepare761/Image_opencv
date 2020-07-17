#include<opencv2\opencv.hpp>
#include<iostream>
#include<math.h>
#include<algorithm>

using namespace std;
using namespace cv;



int main()
{
	Mat src,dst_up,dst_down;
	src = imread("E:/opencv_yao/Img_opencv/box.png", 1);
	if (src.empty())
	{
		printf("cannot load!");
		return -1;
	}
	namedWindow("原图");
	imshow("原图", src);

	//上采样
	pyrUp(src, dst_up, Size(src.cols * 2, src.rows * 2));
	namedWindow("上采样");
	imshow("上采样", dst_up);

	//下采样
	pyrDown(src, dst_down, Size(src.cols / 2, src.rows / 2));
	namedWindow("下采样");
	imshow("下采样", dst_down);

	//高斯不同
	Mat g1, g2, dogImg;
	GaussianBlur(src, g1, Size(5, 5), 0, 0);
	GaussianBlur(src, g2, Size(5, 5), 11, 11);
	subtract(g1, g2, dogImg);
	//归一化显示
	normalize(dogImg, dogImg, 255, 0, NORM_MINMAX);//因为两个图像的差值肯定不大，看起来一片黑，所以需要把像素扩展到0~255的区间。
	namedWindow("高斯不同");
	imshow("高斯不同", dogImg);

	waitKey(0);
	return 0;
}