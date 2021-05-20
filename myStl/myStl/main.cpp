#include<iostream>
#include<vector>
#include <numeric>
#include <algorithm>
#include<iostream>
#include<vector>
#include<opencv2/opencv.hpp>
#include<opencv2/video/tracking.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<time.h>
using namespace cv;
using namespace std;
using namespace cv::cuda;


//读取视频路径
string path1 = "E://素材//12//T202009031102862681.bmp";
//保存图像帧路径
string path2 = "E://素材//12//T202009031102862562.bmp";
//保存光流帧路径
//string flowPath = "E://数据集//pdflow//2//";
//保存光流帧x路径
string path3 = "E://素材//12//T202009031102862442.bmp";
//保存光流帧y路径
string path4 = "E://素材//12//T202009031102862316.bmp";



int main(int argc, char * argv[]) {

	Mat image1 = cv::imread(path1);
	Mat image2 = cv::imread(path2);
	Mat image3 = cv::imread(path3);
	Mat image4 = cv::imread(path4);
	Mat res1, res2, res3, res4;
	//Mat image1 = cv::imread(path1);
	Mat element = getStructuringElement(MORPH_RECT, Size(11, 11));
	dilate(image1, res1, element);
	dilate(image2, res2, element);
	dilate(image3, res3, element);
	dilate(image4, res4, element);

	Mat hou1, hou2, hou3, hou4;

	cvtColor(res1, hou1, CV_BGR2GRAY);//转二值图
	cvtColor(res2, hou2, CV_BGR2GRAY);//转二值图
	cvtColor(res3, hou3, CV_BGR2GRAY);//转二值图
	cvtColor(res4, hou4, CV_BGR2GRAY);//转二值图



	Mat line1, line2, line3, line4;

	cv::HoughLinesP(hou1, line1, 1, CV_PI / 180, 80, 50, 10);
	cv::HoughLinesP(hou2, line2, 1, CV_PI / 180, 80, 50, 10);
	cv::HoughLinesP(hou3, line3, 1, CV_PI / 180, 80, 50, 10);
	cv::HoughLinesP(hou4, line4, 1, CV_PI / 180, 80, 50, 10);

	int x1, y1, x2, y2;
	//cvtColor(frame, prev, CV_BGR2GRAY);//转二值图
	//cv::imwrite(imagePath+"img_00001.jpg", frame);//
	for (int i = 0; i < line1.rows; i++)
	{
		x1 = line1.at<Vec4i>(i, 0)[0];
		y1 = line1.at<Vec4i>(i, 0)[1];
		x2 = line1.at<Vec4i>(i, 0)[2];
		y2 = line1.at<Vec4i>(i, 0)[3];
		cv::line(res1, Point(x1, y1), Point(x2, y2), Scalar(0, 255, 255), 2);
	}
	for (int i = 0; i < line4.rows; i++)
	{
		x1 = line4.at<Vec4i>(i, 0)[0];
		y1 = line4.at<Vec4i>(i, 0)[1];
		x2 = line4.at<Vec4i>(i, 0)[2];
		y2 = line4.at<Vec4i>(i, 0)[3];
		cv::line(res4, Point(x1, y1), Point(x2, y2), Scalar(0, 255, 255), 2);
	}
	for (int i = 0; i < line2.rows; i++)
	{
		x1 = line2.at<Vec4i>(i, 0)[0];
		y1 = line2.at<Vec4i>(i, 0)[1];
		x2 = line2.at<Vec4i>(i, 0)[2];
		y2 = line2.at<Vec4i>(i, 0)[3];
		cv::line(res2, Point(x1, y1), Point(x2, y2), Scalar(0, 255, 255), 2);
	}
	for (int i = 0; i < line3.rows; i++)
	{
		x1 = line3.at<Vec4i>(i, 0)[0];
		y1 = line3.at<Vec4i>(i, 0)[1];
		x2 = line3.at<Vec4i>(i, 0)[2];
		y2 = line3.at<Vec4i>(i, 0)[3];
		cv::line(res3, Point(x1, y1), Point(x2, y2), Scalar(0, 255, 255), 2);
	}

	cv::imwrite("E://素材//12//res1.jpg", res1);
	cv::imwrite("E://素材//12//res2.jpg", res3);
	cv::imwrite("E://素材//12//res3.jpg", res2);
	cv::imwrite("E://素材//12//res4.jpg", res4);
	
	return 0;
}

