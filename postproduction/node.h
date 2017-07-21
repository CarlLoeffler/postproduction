#pragma once

#include "NodeLogic.h"

//Generic node, contains NodeLogic object to specialize
class Node {
public:
	Node();
	~Node();

	void setInput(int num);
	int getInput(int num);
	void setOutput(int num);
	int getOutput(int num);
	void setLogic(NodeLogic* newLogic);
	bool isStale() { return stale; };
	void clearStale() { stale = false; };
	void sanitize(int num);

protected:
	bool stale;
	int numInputs;
	int numOutputs;
	std::vector<int>* input;
	std::vector<int>* output;
	NodeLogic* logic;
};
