#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>
using namespace cv;
using namespace std;

Mat src, dst;

int main()
{

	//ԭͼ
	src = imread("E:/opencv_yao/Img_opencv/lena.jpg",IMREAD_UNCHANGED);

	if (!src.data)
	{
		cout << "load error" << endl;
		return -1;
	}

	namedWindow("input image", CV_WINDOW_AUTOSIZE);
	imshow("input image", src);

	//��ֵģ��,7Ϊ����˴�С
	//medianBlur(src, dst, 7);

	//˫��ģ��
	//15Ϊ����İ뾶
	//150:ֵ���ϵķ���  ���������ֵԽ��
	//�ͱ����������������и�������ɫ�ᱻ��ϵ�һ�𣬲����ϴ�İ������ɫ����
	//3:�ռ���ķ���   ������ֵԽ����ζ��ԽԶ�����ػ��໥Ӱ�죬�Ӷ�ʹ����������㹻���Ƶ���ɫ��ȡ��ͬ����ɫ��
	bilateralFilter(src, dst, 10, 150, 3);

	//imshow("��ֵ�˲�",dst);
	imshow("˫���˲�", dst);

	//��Ե��
	Mat resultImg;
	Mat kernel = (Mat_<int>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
	filter2D(dst, resultImg, -1, kernel, Point(-1, -1), 0);
	imshow("Final", resultImg);
	waitKey(0);
	return 0;
}