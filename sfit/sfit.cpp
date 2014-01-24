// sfit.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//#include <opencv2/opencv.hpp>

#include "highgui.h"

#include "nonfree/features2d.hpp"
#include "legacy/legacy.hpp"
#include <iostream>
using namespace std;
using namespace cv;


int main(int argc, char* argv[])

{

	Mat input1=imread("left01.jpg",1);
	Mat input2=imread("left02.jpg",1);
	SiftFeatureDetector detector;
	vector<KeyPoint> keypoint1,keypoint2;
	detector.detect(input1,keypoint1);

	Mat output1;
	drawKeypoints(input1,keypoint1,output1);
	imshow("sift_result1.jpg",output1);
	imwrite("sift_result1.jpg",output1);

	Mat output2;
	SiftDescriptorExtractor extractor;
	Mat descriptor1,descriptor2;
	BruteForceMatcher<L2<float>> matcher;

	vector<DMatch> matches;
	Mat img_matches;
	detector.detect(input2,keypoint2);
	drawKeypoints(input2,keypoint2,output2);

	imshow("sift_result2.jpg",output2);
	imwrite("sift_result2.jpg",output2);

	extractor.compute(input1,keypoint1,descriptor1);
	extractor.compute(input2,keypoint2,descriptor2);

	matcher.match(descriptor1,descriptor2,matches);

	drawMatches(input1,keypoint1,input2,keypoint2,matches,img_matches);
	imshow("matches",img_matches);
	imwrite("matches.jpg",img_matches);

	waitKey();

	return 0;

}


void test()
{

	//const char* imagename = "lena.jpg";

	////从文件中读入图像

	//Mat img = imread(imagename);

	////如果读入图像失败

	//if(img.empty())

	//{

	//	fprintf(stderr, "Can not load image %s\n", imagename);

	//	return -1;

	//}

	////显示图像

	//imshow("image", img);

	////此函数等待按键，按键盘任意键就返回

	//waitKey();
}
