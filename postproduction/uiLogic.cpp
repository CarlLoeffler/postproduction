#pragma once

#include "uiLogic.h"

// ************************************* UIState *************************************************************

UIState::UIState() {
	nodes = new NodeGraph();
	//This needs to be a vector of pointers, because we need to be able to NULL elements.
	//We also can't do the "first element is a pointer to rest of data structure for NULLing purposes" trick because I'm lazy.
	imgList = new std::vector<PPImg*>();
}

UIState::~UIState() {
	//Instead we just manually clear on delete. Worse things have happened.
	for (int i = 0; i < imgList->size(); i++) {
		delete (*imgList)[i];
	}
}

//Get direct access to vector of images for efficiency - DO NOT MODIFY THIS DIRECTLY.
//THIS IS NOT THREAD SAFE IN ANY WAY. ANY INVOCATION OF GETTER OR SETTER FUNCTIONS MAY INVALIDATE RETURN VALUE.
std::vector<PPImg*>* UIState::getImageList() {
	return imgList;
}

//Adds image to image list. Adds deep copy of passed image to list.
//Returns index of image in list, or -1 on failure.
int UIState::addImage(PPImg* img) {
	//We're using a vector exclusively for the dynamic resizing, and rolling our own addition and deletion
	//This is because we value absolute position over order, which no standard c++ container seems to do.
	int i = 0;
	for (i = 0; i < imgList->size(); i++) {
		if ((*imgList)[i] == NULL) {
			(*imgList)[i] = new PPImg(img);
			return i;
		}
	}
	imgList->push_back(new PPImg(img));
	return i;
}

//Removes image from list by position in list
void UIState::removeImage(int num) {
	delete (*imgList)[num];
	(*imgList)[num] = NULL;
	nodes->sanitize(num);
}

//Add generic node to node editor. Returns number of node, or -1 on failure.
int UIState::addNode() {
	return nodes->addNode();
}

//Removes node from node editor by index in node list.
void UIState::removeNode(int num) {
	nodes->removeNode(num);
}


