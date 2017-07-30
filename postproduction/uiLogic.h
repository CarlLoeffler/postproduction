#ifndef UI_LOGIC_H
#define UI_LOGIC_H

#include <vector>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>

#include "node.h"
#include "NodeGraph.h"
#include "nodeLink.h"
#include "PPImg.h"
#include "NodeLogic.h"

class UIState {
	public:
		UIState();
		~UIState();
		//Track images in image list
		std::vector<PPImg*>* getImageList();
		int addImage(PPImg* img);
		void removeImage(int num);
		PPImg* getImageByName(char* query);

		//Track state of node editor
		int addNode();
		void removeNode(int num);
	private:
		std::vector<PPImg*>* imgList;
		NodeGraph* nodes;
};


#endif