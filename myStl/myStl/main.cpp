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
string path = "E://数据集//pdaction//Ballfangen_catch_u_cm_np1_fr_goo_1.avi";
//保存图像帧路径
string imagePath = "E://数据集//pdrgb//Ballfangen_catch_u_cm_np1_fr_goo_1//";
//保存光流帧路径
//string flowPath = "E://数据集//pdflow//2//";
//保存光流帧x路径
string xPath = "E://数据集//pdflow//x//";
//保存光流帧y路径
string yPath = "E://数据集//pdflow//y//";


void convertFlowToImage(const Mat &flow, Mat &img_x, Mat &img_y, double lowerBound, double higherBound) 
{
//cvRound()函数，即四舍五入函数
//int x = (v) < (L) ? 0 : cvRound(255*((v) - (L))
//如果v大于L，v-L乘以255后四舍五入（取整）
//int y = (v) > (H) ? 255 : x
//如果v小于H，则取x,否则取255
//以上为v,L,H的关系
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
	Mat prev, curr, frame;
	cv::Ptr<cv::DualTVL1OpticalFlow> tvl1 = cv::DualTVL1OpticalFlow::create();

	VideoCapture  capture(path);
	if (!capture.isOpened()) {
		cout << "Read video failed" << endl;
		return -1;
	}

	capture.read(frame);
	cvtColor(frame, prev, CV_BGR2GRAY);//转二值图
	cv::imwrite(imagePath+"img_00001.jpg", frame);//
	int h = frame.rows;
	int w = frame.cols;

	clock_t begin, end;
	begin = clock();//计时
	int frameNum = 2;//取两帧用来计算光流
	//设置视频流的参数，第一个参数代表设置视频的第几个参数，
	//CAP_PROP_POS_FRAMES是设置捕获的帧的基于0的索引。设为2，即从第二帧开始读取
	capture.set(CAP_PROP_POS_FRAMES, frameNum);
	//获取视频帧数
	int count = capture.get(CAP_PROP_FRAME_COUNT);
	int fps = capture.get(5);	//CV_CAP_PROP_FPS 帧速率
	string str,strflow;
	int num = 2,flownum=1;
	while (num < count) {
		Mat d_flow;
		Mat out;

		capture >> frame;
		cvtColor(frame, curr, CV_BGR2GRAY);
		imshow("sur", frame);
		stringstream ss;
		ss << setw(5) << setfill('0') << num;
		str = ss.str();
		cv::imwrite(imagePath + "img_" + str + ".jpg", frame);//保存帧图像
		//计算光流
		tvl1->calc(prev, curr, d_flow);
		Mat img_x(h, w, CV_8UC1);
		Mat img_y(h, w, CV_8UC1);


		stringstream sflow;
		sflow << setw(5) << setfill('0') << flownum;
		strflow = sflow.str();
		convertFlowToImage(d_flow, img_x, img_y, -15, 15);
		cv::imwrite(yPath + "flow_y" + strflow + ".jpg", img_y);
		cv::imwrite(xPath + "flow_x" + strflow + ".jpg", img_x);

		prev = curr.clone();
		num++;
		flownum++;
		waitKey(30);
	}

	end = clock();
	std::cout << "total frames: " << num << endl;
	std::cout << "time used: " << (double)(end - begin) / CLOCKS_PER_SEC << endl;
	return 0;
}



//
//int main(int argc, const char* argv[])
//{
//	if (argc < 3)
//	{
//		cerr << "Usage : " << argv[0] << "<frame0> <frame1> [<output_flow>]" << endl;
//		return -1;
//	}
//
//	Mat frame0 = imread(argv[1], IMREAD_GRAYSCALE);
//	Mat frame1 = imread(argv[2], IMREAD_GRAYSCALE);
//
//	if (frame0.empty())
//	{
//		cerr << "Can't open image [" << argv[1] << "]" << endl;
//		return -1;
//	}
//	if (frame1.empty())
//	{
//		cerr << "Can't open image [" << argv[2] << "]" << endl;
//		return -1;
//	}
//
//	if (frame1.size() != frame0.size())
//	{
//		cerr << "Images should be of equal sizes" << endl;
//		return -1;
//	}
//
//	Mat_<Point2f> flow;
//	Ptr<DenseOpticalFlow> tvl1 = createOptFlow_DualTVL1();
//
//	const double start = (double)getTickCount();
//	tvl1->calc(frame0, frame1, flow);
//	const double timeSec = (getTickCount() - start) / getTickFrequency();
//	cout << "calcOpticalFlowDual_TVL1 : " << timeSec << " sec" << endl;
//
//	Mat out;
//	drawOpticalFlow(flow, out);
//
//	if (argc == 4)
//		writeOpticalFlowToFile(flow, argv[3]);
//
//	imshow("Flow", out);
//	waitKey();
//
//	return 0;
//}