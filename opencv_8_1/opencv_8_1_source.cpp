#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <stdlib.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <ctime>

using namespace std;

void colorReduce(cv::Mat& image, const int div = 64) {
	int nl = image.rows;
	int nc = image.cols * image.channels();

	for (int i = 0; i < nl; i++)
	{
		uchar* data = image.ptr<uchar>(i);

		for (int j = 0; j < nc; j++)
		{
			data[j] = data[j] / div * div + div / 2;
		}
	}
}

void colorReduce1(cv::Mat_<cv::Vec3b>& image, const int div = 64) {
	for (int i = 0; i < image.rows; i++)
	{
		for (int j = 0; j < image.cols; j++)
		{
			image(i, j)[0] = image(i, j)[0] / div * div + div / 2;
			image(i, j)[1] = image(i, j)[1] / div * div + div / 2;
			image(i, j)[2] = image(i, j)[2] / div * div + div / 2;
		}
	}
}
int main() {

	cv::Mat image = cv::imread("1.png");
	clock_t start = clock();
	colorReduce(image, 20);
	cout << "pointer takes: " << clock() - start << "ms" << endl;

	cv::Mat_<cv::Vec3b> image1 = image.clone();
	clock_t start1 = clock();
	colorReduce1(image1, 20);
	cout << "for takes: " << clock() - start1 << "ms" << endl;

	//cv::waitKey(0);

	return 0;
}


