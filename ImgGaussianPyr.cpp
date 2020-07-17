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
	namedWindow("ԭͼ");
	imshow("ԭͼ", src);

	//�ϲ���
	pyrUp(src, dst_up, Size(src.cols * 2, src.rows * 2));
	namedWindow("�ϲ���");
	imshow("�ϲ���", dst_up);

	//�²���
	pyrDown(src, dst_down, Size(src.cols / 2, src.rows / 2));
	namedWindow("�²���");
	imshow("�²���", dst_down);

	//��˹��ͬ
	Mat g1, g2, dogImg;
	GaussianBlur(src, g1, Size(5, 5), 0, 0);
	GaussianBlur(src, g2, Size(5, 5), 11, 11);
	subtract(g1, g2, dogImg);
	//��һ����ʾ
	normalize(dogImg, dogImg, 255, 0, NORM_MINMAX);//��Ϊ����ͼ��Ĳ�ֵ�϶����󣬿�����һƬ�ڣ�������Ҫ��������չ��0~255�����䡣
	namedWindow("��˹��ͬ");
	imshow("��˹��ͬ", dogImg);

	waitKey(0);
	return 0;
}