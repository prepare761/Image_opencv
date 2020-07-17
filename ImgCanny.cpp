#include<opencv2\opencv.hpp>
#include<iostream>
#include<math.h>
#include<algorithm>

using namespace cv;

Mat src,dst,gray_src;
int t1_value =50;
int max_value = 255;
const char* OUTPUT_TITLE="Canny emo";
void Canny_Demo(int ,void*);
int main(int argc, char **argv){
	src = imread("E:/opencv_yao/Img_opencv/lena.jpg");
	if (!src.data)
	{
		return -1;
	}
	char INPUT_TITLE[]="input image";
	namedWindow(INPUT_TITLE,CV_WINDOW_AUTOSIZE);
	namedWindow(OUTPUT_TITLE,CV_WINDOW_AUTOSIZE);
	imshow(INPUT_TITLE,src);

	createTrackbar("Threshold",OUTPUT_TITLE,&t1_value,max_value,Canny_Demo);
	Canny_Demo(0,0);
	waitKey(0);
	return 0;
}
void Canny_Demo(int ,void*){
	Mat edge_output;
	GaussianBlur(gray_src,gray_src,Size(3,3),BORDER_DEFAULT);
	cvtColor(src,gray_src,CV_BGR2GRAY);
	Canny(gray_src,edge_output,t1_value,t1_value*2,3);

	dst.create(src.size(),src.type());
	src.copyTo(dst,edge_output);
	imshow(OUTPUT_TITLE,~dst);
}