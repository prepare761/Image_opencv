#include<opencv2\opencv.hpp>
#include<iostream>
#include<math.h>
#include<algorithm>
#include <vector>
using namespace std;
using namespace cv;
char* INPUT_TITLE="input image";
char* OUTPUT_TITLE="result image";
char* match_t = "template match demo";
Mat src, dst, temp;
int match_method = CV_TM_SQDIFF;
int max_track =5;
void Match_Demo(int ,void*);
int main(int argc,char **argv){
	src = imread("E:/opencv_yao/Img_opencv/box_in_scene.png");
	temp = imread("E:/opencv_yao/Img_opencv/match.png");
	if (!src.data||!temp.data)
	{
		return -1;
	}
	
	namedWindow(INPUT_TITLE,CV_WINDOW_AUTOSIZE);
	namedWindow(OUTPUT_TITLE,CV_WINDOW_AUTOSIZE);
	namedWindow(match_t,CV_WINDOW_AUTOSIZE);
	imshow(INPUT_TITLE,src);
	
	const char* track_titile = "Match Algo Type";
	createTrackbar(track_titile,OUTPUT_TITLE,&match_method,max_track,Match_Demo);
	Match_Demo(0,0);

	waitKey(0);
	return 0;
}
void Match_Demo(int,void*)
{
	int width = src.cols - temp.cols +1;
	int height = src.rows -temp.rows +1;
	Mat result(width, height, CV_32FC1);

	matchTemplate(src,temp,result,match_method);
	normalize(result,result,0,1,NORM_MINMAX,-1,Mat());

	Point minLoc;
	Point  maxLoc;
	double min,max;
	src.copyTo(dst);
	Point temLoc;

	minMaxLoc(result,&min,&max,&minLoc,&maxLoc,Mat());
	if(match_method == CV_TM_SQDIFF || match_method == CV_TM_SQDIFF_NORMED)
	{
		temLoc = minLoc;
	}
	else
	{
		temLoc = maxLoc;
	}

	//»æÖÆ¾ØÐÎ
	rectangle(dst,Rect(temLoc.x,temLoc.y,temp.cols,temp.rows),Scalar(0,0,255),2,8);
	rectangle(result,Rect(temLoc.x,temLoc.y,temp.cols,temp.rows),Scalar(0,0,255),2,8);

	imshow(OUTPUT_TITLE,result);
	imshow(match_t,dst);
}