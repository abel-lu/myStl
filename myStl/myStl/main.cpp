#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;


void dfs(vector<vector<int>>&temp, vector<bool>&visited, int i)
{
	visited[i] = true;
	for (int j = 0; j < temp.size(); ++j)
	{
		if (temp[i][j] == 1 && !visited[j])
		{
			dfs(temp, visited, j);
		}
	}
}

int main()
{
	auto n = 0;
	cin >> n;
	int k = n;
	vector<vector<int>>temp(n, vector<int>(n, 0));
	vector<bool>visited(n, false);
	unordered_map<string, int>bianhao;
	int m = 0;
	while (n--)
	{
		string a;
		string b;
		cin >> a;
		cin >> b;
		if (!bianhao.count(a))
		{
			bianhao[a] = m;
			m++;
		}
		if (!bianhao.count(b))
		{
			bianhao[b] = m;
			m++;
		}
		temp[bianhao[a]][bianhao[b]] = 1;
		temp[bianhao[b]][bianhao[a]] = 1;
	}

	int count = 0;
	for (int i = 0; i < k; ++i)
	{
		if (!visited[i])
		{
			count++;
			dfs(temp, visited, i);
		}
	}
	cout << count << endl;


	system("pause");
	return 0;

}

//
////读取视频路径
//string path = "E://数据集//pdaction//Ballfangen_catch_u_cm_np1_fr_goo_1.avi";
////保存图像帧路径
//string imagePath = "E://数据集//pdrgb//Ballfangen_catch_u_cm_np1_fr_goo_1//";
////保存光流帧路径
//
////保存光流帧y路径
//string yPath = "E://数据集//pdflow//y//";
//
//
//void convertFlowToImage(const Mat &flow, Mat &img_x, Mat &img_y, double lowerBound, double higherBound) 
//{
////cvRound()函数，即四舍五入函数
////int x = (v) < (L) ? 0 : cvRound(255*((v) - (L))
////如果v大于L，v-L乘以255后四舍五入（取整）
////int y = (v) > (H) ? 255 : x
////如果v小于H，则取x,否则取255
////以上为v,L,H的关系
//#define CAST(v, L, H) ((v) > (H) ? 255 : (v) < (L) ? 0 : cvRound(255*((v) - (L))/((H)-(L))))
//
//	for (int i = 0; i < img_x.rows; ++i) {
//		for (int j = 0; j < img_x.cols; ++j) {
//			img_x.at<uchar>(i, j) = CAST(flow.at<Point2f>(i, j).x, lowerBound, higherBound);
//			img_y.at<uchar>(i, j) = CAST(flow.at<Point2f>(i, j).x, lowerBound, higherBound);
//		}
//	}
//
//#undef CAST
//}
//
//
//void function1(map<string, string>)
//{
//
//}
//
//int main(int argc, char * argv[]) {
//	//unorder_map<>
//	int n;
//	cin >> n;
//	map<string, string> mstr;
//	vector<string> vstr1,vstr2;
//	while(n > 0)
//	{
//		string str;
//		getline(cin, str);
//		string str1[2];
//		istringstream is(str);
//		is >> str1[0] >> str1[1];
//		//mstr[str1[0]] = str1[1];
//		vstr1.push_back(str1[0]);
//		vstr2.push_back(str1[1]);
//		//cout << str1[0] << " " << str1[1] << endl;
//		n--;
//	}
//	
//
//	vector<int> flow;
//
//
//	function1(mstr);
//	
//
//
//	system("pause");
//	return 0;
//}



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