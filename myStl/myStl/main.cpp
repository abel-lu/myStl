
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



void convertFlowToImage(const Mat &flow, Mat &img_x, Mat &img_y,
	double lowerBound, double higherBound) {
#define CAST(v, L, H) ((v) > (H) ? 255 : (v) < (L) ? 0 : cvRound(255*((v) - (L))/((H)-(L))))
	for (int i = 0; i < img_x.rows; ++i) {
		for (int j = 0; j < img_x.cols; ++j) {
			img_x.at<uchar>(i, j) = CAST(flow.at<Point2f>(i, j).x, lowerBound, higherBound);
			img_y.at<uchar>(i, j) = CAST(flow.at<Point2f>(i, j).x, lowerBound, higherBound);
		}
	}
#undef CAST
}
int main(int argc, char * argv[]) {
	vector<Mat> flow;
	//记得改文件路径
	const char* path = "path_to_video";
	Mat prev, curr, frame;
	cv::Ptr<cv::optflow::DualTVL1OpticalFlow> alg_tvl1 = cv::optflow::DualTVL1OpticalFlow::create();
	VideoCapture  capture(path);
	capture.read(frame);
	cvtColor(frame, prev, CV_BGR2GRAY);
	int h = frame.rows;
	int w = frame.cols;
	if (!capture.isOpened()) {
		cout << "Read video failed" << endl;
		return -1;
	}
	clock_t begin, end;
	begin = clock();
	int frameNum = 2;
	capture.set(CAP_PROP_POS_FRAMES, frameNum);
	int num = 0;
	while (capture.read(frame)) {
		Mat d_flow;
		cvtColor(frame, curr, CV_BGR2GRAY);
		alg_tvl1->calc(prev, curr, d_flow);
		flow.push_back(d_flow);
		frameNum += 2; //每隔一帧计算光流
		capture.set(CAP_PROP_POS_FRAMES, frameNum);
		prev = curr.clone();
		num++;
	}
	//记得改路径
	char* save_dir = "save_path_for_flow";
	int save_dir_len = strlen(save_dir);
	for (int i = 0; i < flow.size(); i++) {
		Mat img_x(h, w, CV_8UC1);
		Mat img_y(h, w, CV_8UC1);
		convertFlowToImage(flow[i], img_x, img_y, -15, 15);
		char y_path[save_dir_len + 1 + 19];
		sprintf(y_path, "%s%s%s%06d%s", save_dir, "/", "y_frame_", i, ".jpg");
		char x_path[save_dir_len + 1 + 19];
		sprintf(x_path, "%s%s%s%06d%s", save_dir, "/", "x_frame_", i, ".jpg");
		imwrite(y_path, img_y);
		imwrite(x_path, img_x);
	}
	end = clock();
	cout << "total frames: " << num << endl;
	cout << "time used: " << (double)(end - begin) / CLOCKS_PER_SEC << endl;
	return 0;
}

