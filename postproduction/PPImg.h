#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>

//Essentially a wrapper around cv::Mat to allow arbitrary source/dest types, while enforcing type safety
//Constructor deep-copies source Mat, but returns pointer to internal representation on getMat()
// WIP and this is going to be pain.
class PPImg {
public:
	PPImg();
	PPImg(cv::Mat* img);
	PPImg(PPImg* img);
	~PPImg();
	void setName(char* str);
	char* getName();
	cv::Mat* getMat();
	void setMat(cv::Mat* img);
private:
	cv::Mat* data;
	char name[20];
};

