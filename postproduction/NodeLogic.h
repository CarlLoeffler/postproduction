#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>

//NodeLogic struct. Actual implementation elsewhere.
//Fuck, ok. Calling convention is:
//	First argument is number of arguments total, by type
//	format is {	number of input Mats,
//				number of output Mats,
//				number of integer parameters,
//				number of float parameters }
//	Argument arrays are the way you'd think
//	All name and tooltip string arrays must be static
//	Also, struct should itself be static.
struct NodeLogic {
	void(*logic)(int argNums[4], cv::Mat matArgs[], int intArgs[], double floatArgs[]);
	int numInputs;
	int numOutputs;
	int numIntParams;
	int numFloatParams;
	char** inputNames;
	char** outputNames;
	char** intParamNames;
	char** floatParamNames;
	char** inputToolTips;
	char** outputToolTips;
	char** intParamToolTips;
	char** floatParamToolTips;
};
