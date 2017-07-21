#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>

#include "node.h"
#include "nodeLink.h"
#include "PPImg.h"

class NodeGraph {
public:
	NodeGraph();
	~NodeGraph();
	
	int addNode();
	void removeNode(int num);
	//argument format is [node num, port num]
	int addLink(int src[2], int dest[2]);
	//Node* getNode(int num);
	void sanitize(int num);
	void removeLink(int num);

private:
	std::vector<Node*>* nodeList;
	std::vector<NodeLink*>* linkList;
};
