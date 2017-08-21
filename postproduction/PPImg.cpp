#pragma once

#include "PPImg.h"

// ************************************* PPImg ********************************************************************
//Essentially a wrapper around cv::Mat to allow arbitrary source/dest types, while enforcing type safety
//Constructor deep-copies source Mat, but returns pointer to internal representation on getMat()
// WIP and this is going to be pain.
PPImg::PPImg() {
	data = NULL;
	strncpy(name, "unnamed", 19);
	name[20] = NULL;
}

//construct new image with existing Mat
PPImg::PPImg(cv::Mat* img) {
	data = &(img->clone());		//This works because openCV owns it's own memory, reference counting in the background.
	strncpy(name, "unnamed", 19);
	name[20] = NULL;
}

//cleaning up after ourselves
PPImg::~PPImg() {
	if (data != NULL) {
		data->release();	//tell openCV to clear the reference
	}
}

//Sets display name of image
void PPImg::setName(char* str) {
	strncpy(name, str, 19);
}

//returns name of image
char* PPImg::getName() {
	return name;
}

//sets pointer to Mat
void PPImg::setMat(cv::Mat* img) {
	data = img;
}

//gets pointer to Mat
cv::Mat* PPImg::getMat() {
	return data;
}

//Copy constructor!
PPImg::PPImg(PPImg* img) {
	data = img->getMat();
	strncpy(name, img->getName(), 20);
}
//cv::Mat getMatAs(MatType type, Mat* mat);
