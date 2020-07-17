#include<opencv2\opencv.hpp>
#include<iostream>
#include<math.h>
#include<algorithm>
#include <vector>

using namespace std;
using namespace cv;
Mat src,dst,map_x,map_y;
const char* OUTPUT_TITLE="remap demo";
int index =0;
void update_mp();
int main(int argc,char **argv){
	
	src = imread("E:/opencv_yao/Img_opencv/lena.jpg");
	if (!src.data)
	{
		return -1;
	}
	char INPUT_TITLE[]="input image";
	namedWindow(INPUT_TITLE,CV_WINDOW_AUTOSIZE);
	namedWindow(OUTPUT_TITLE,CV_WINDOW_AUTOSIZE);
	imshow(INPUT_TITLE,src);
	//建立映射表
	map_x.create(src.size(),CV_32FC1);
	map_y.create(src.size(),CV_32FC1);

	int c = 0;
	while(true)
	{
		c = waitKey(500);
		index = c%4;
		if((char)c==27)
		{
			break;
		}
		update_mp();
		remap(src,dst,map_x,map_y,CV_INTER_LINEAR,BORDER_CONSTANT,Scalar(0,0,255));
		imshow(OUTPUT_TITLE,dst);
	}
	return 0;
}
void update_mp(){
	for (int row=0;row<src.rows;row++)
	{
		for (int col=0;col<src.cols;col++)
		{
			switch(index)
			{
			//图像行列都缩小为原图像的1/2`
			case 0:
					if(col>(src.cols*0.25) && col<(src.cols*0.75) && row>(src.rows*0.25) && row<(src.rows*0.75))
					{
						map_x.at<float>(row,col) = 2*(col - 0.25*src.cols);
						map_y.at<float>(row,col) = 2*(row - 0.25*src.rows)-0.25;
						//原图像映射到缩小部分的边界不做处理，就出现黄框
					}
					else
					{
						map_x.at<float>(row,col)=0;
						map_y.at<float>(row,col)=0;
					}
				break;
			
			//图像左右翻转
			case 1:
				  map_x.at<float>(row,col) = (src.cols - col -1);
				  map_y.at<float>(row,col) = row;
				  break;
			
			//图像上下翻转
			case 2:
				  map_x.at<float>(row,col) = col;
				  map_y.at<float>(row,col) = (src.rows - row -1);
				  break;
			
			//图像中心旋转
			case 3:
				  map_x.at<float>(row,col) = (src.cols - col -1);
				  map_y.at<float>(row,col) = (src.rows - row -1);
				  break;

			default:
				break;
			}
		}
	}
}