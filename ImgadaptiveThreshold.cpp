#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

Mat src, dst, bilary_gray, output;

int main(int argc, char** argv) {
	src = imread("E:/opencv_yao/Img_opencv/shuiping.png");
	if (!src.data) {
		cout << "Could not load image......\n" << endl;
		return -1;
	}
	imshow("src", src);

	cvtColor(src, dst, CV_BGR2GRAY);
	imshow("dst", dst);
	adaptiveThreshold(~dst, bilary_gray, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 15, -2);
	//double maxValue,��ֵͼ�����ֵ
	//int adaptiveMethod,����Ӧ������ֻ������֮һ - ADAPTIVE_THRESH_MEAN_C �� ADAPTIVE_THRESH_GAUSSIAN_C
	//int thresholdType,��ֵ����
	//int blockSize,���С
	//double C, ����C ������������0������
	imshow("bilary_gray", bilary_gray);
	//Mat kernel1 = getStructuringElement(MORPH_RECT, Size(dst.cols/16, 1), Point(-1, -1));//ˮƽ��
	Mat kernel2 = getStructuringElement(MORPH_RECT, Size(1, dst.rows/16), Point(-1, -1));//��ֱ��
	erode(bilary_gray, dst, kernel2);
	dilate(dst, output, kernel2);
	bitwise_not(output, output);
	imshow("output", output);

	waitKey(0);
	return 0;
}