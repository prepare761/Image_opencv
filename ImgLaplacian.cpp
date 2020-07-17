#include<opencv2\opencv.hpp>
#include<iostream>
#include<math.h>
#include<algorithm>

using namespace cv;
int main(int argc,char **argv){
	Mat src,dst,gray_src,edge_image;
	src = imread("E:/opencv_yao/Img_opencv/lena.jpg");
	if (!src.data)
	{
		return -1;
	}
	char INPUT_TITLE[]="input image";
	char OUTPUT_TITLE[]="Laplace demo";
	namedWindow(INPUT_TITLE,CV_WINDOW_AUTOSIZE);
	namedWindow(OUTPUT_TITLE,CV_WINDOW_AUTOSIZE);
	imshow(INPUT_TITLE,src);

	GaussianBlur(src,dst,Size(3,3),0,0);
	cvtColor(dst,gray_src,CV_BGR2GRAY);

	Laplacian(gray_src,edge_image,CV_16S,3);
	convertScaleAbs(edge_image,edge_image);


	threshold(edge_image,edge_image,0,255,THRESH_OTSU | THRESH_BINARY);
	imshow(OUTPUT_TITLE,edge_image);

	waitKey(0);
	return 0;
}