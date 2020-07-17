#include<opencv2\opencv.hpp>
#include<iostream>
#include<math.h>
#include<algorithm>
#include <vector>
using namespace std;
using namespace cv;
int main(int argc,char **argv){
	Mat src,dst,gray_src;
	src = imread("E:/opencv_yao/Img_opencv/circle111.jpg");
	if (!src.data)
	{
		return -1;
	}
	char INPUT_TITLE[]="input image";
	char OUTPUT_TITLE[]="hough-circle-detection";
	namedWindow(INPUT_TITLE,CV_WINDOW_AUTOSIZE);
	namedWindow(OUTPUT_TITLE,CV_WINDOW_AUTOSIZE);
	imshow(INPUT_TITLE,src);
	
	medianBlur(src,gray_src,3);//
	cvtColor(gray_src,gray_src,CV_BGR2GRAY);
	vector<Vec3f> pcircles;
	HoughCircles(gray_src,pcircles,CV_HOUGH_GRADIENT,1,50,100,20,5,220);
	src.copyTo(dst);
	for (int i=0;i<pcircles.size();i++)
	{
		Vec3f cc = pcircles[i];
		circle(dst,Point(cc[0],cc[1]),cc[2],Scalar(0,0,255),1,CV_AA);
		circle(dst,Point(cc[0],cc[1]),1,Scalar(0,0,255),1,CV_AA);
	}
	imshow(OUTPUT_TITLE,dst);

	waitKey(0);
	return 0;
}