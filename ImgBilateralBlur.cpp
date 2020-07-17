#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>
using namespace cv;
using namespace std;

Mat src, dst;

int main()
{

	//原图
	src = imread("E:/opencv_yao/Img_opencv/lena.jpg",IMREAD_UNCHANGED);

	if (!src.data)
	{
		cout << "load error" << endl;
		return -1;
	}

	namedWindow("input image", CV_WINDOW_AUTOSIZE);
	imshow("input image", src);

	//中值模糊,7为卷积核大小
	//medianBlur(src, dst, 7);

	//双边模糊
	//15为计算的半径
	//150:值域上的方差  这个参数的值越大，
	//就表明该像素邻域内有更宽广的颜色会被混合到一起，产生较大的半相等颜色区域。
	//3:空间域的方差   他的数值越大，意味着越远的像素会相互影响，从而使更大的区域足够相似的颜色获取相同的颜色。
	bilateralFilter(src, dst, 10, 150, 3);

	//imshow("中值滤波",dst);
	imshow("双边滤波", dst);

	//边缘锐化
	Mat resultImg;
	Mat kernel = (Mat_<int>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
	filter2D(dst, resultImg, -1, kernel, Point(-1, -1), 0);
	imshow("Final", resultImg);
	waitKey(0);
	return 0;
}