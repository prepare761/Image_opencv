#include<opencv2\opencv.hpp>
#include<iostream>
#include<math.h>
#include<algorithm>
#include <vector>
using namespace std;
using namespace cv;
int main(int argc,char **argv){
	Mat src,dst,gray_src;
	src = imread("E:/opencv_yao/Img_opencv/xiantiao.png");
	if (!src.data)
	{
		return -1;
	}
	char INPUT_TITLE[]="input image";
	char OUTPUT_TITLE[]="hough-line-detection";
	namedWindow(INPUT_TITLE,CV_WINDOW_AUTOSIZE);
	namedWindow(OUTPUT_TITLE,CV_WINDOW_AUTOSIZE);
	imshow(INPUT_TITLE,src);

	GaussianBlur(src,src,Size(3,3),BORDER_DEFAULT);
	cvtColor(src,gray_src,CV_BGR2GRAY);
	Canny(gray_src,gray_src,150,200,3);
	cvtColor(gray_src,dst,CV_GRAY2BGR);
	imshow("edge image",gray_src);

	vector<Vec2f> plines;
	//HoughLines(gray_src,plines,1,CV_PI / 180.0 , 10, 0, 10);
	Scalar color = Scalar(0,0,255);
	for (size_t i=0;i<plines.size();i++)
	{	
		Vec2f hline = plines[i];
		line(dst,Point(hline[0],hline[1]),Point(hline[2],hline[3]),color,3,CV_AA);
	}
	imshow(OUTPUT_TITLE,~dst);

	waitKey(0);
	return 0;
}