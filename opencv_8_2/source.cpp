#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

int main() {
	Mat image = imread("1.jpg");
	namedWindow("imageShow");
	imshow("imageShow", image);
	waitKey(0);

	return 0;
}