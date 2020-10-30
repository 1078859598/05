#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	VideoCapture cap(0);

	double scale = 0.5;

	double i_minH = 0;
	double i_maxH = 20;

	double i_minS = 43;
	double i_maxS = 255;

	double i_minV = 55;
	double i_maxV = 255;

	while (1)
	{
		Mat frame;
		Mat hsvMat;
		Mat detectMat;
		Mat zhongzhi;
		Mat junzhi;
		Mat gaosi;
		Mat bianyuan;

		cap >> frame;
		Size ResImgSiz = Size(frame.cols*scale, frame.rows*scale);
		Mat rFrame = Mat(ResImgSiz, frame.type());
		resize(frame, rFrame, ResImgSiz, INTER_LINEAR);

		cvtColor(rFrame, hsvMat, COLOR_BGR2HSV);

		rFrame.copyTo(detectMat);



		medianBlur(detectMat, zhongzhi, 3);

		blur(detectMat, junzhi, Size(3, 3), Point(-1, -1), BORDER_DEFAULT);

		GaussianBlur(detectMat, gaosi, Size(3, 3), 0, 0, BORDER_DEFAULT);


		Sobel(detectMat, bianyuan, CV_8UC1, 0, 1, 3, 1, 0, BORDER_DEFAULT);

		imshow("ZHONGZHI", zhongzhi);
		imshow("JUNZHI", junzhi);
		imshow("GAOSI", gaosi);
		imshow("BIANYUAN", bianyuan);
		imshow("frame", rFrame);

		waitKey(30);
	}

}