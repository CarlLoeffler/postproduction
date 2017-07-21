#pragma once

#include "node.h"

Node::Node() {
	logic = NULL;
	stale = true;
}

Node::~Node() {
}

//Num is index of relevant link object
//Note that there's no bound checking on this. Safety? Who needs it.
void Node::setInput(int num) {
	(*input)[num] = num;
	stale = true;
}


//Num is index of relevant link object
int Node::getInput(int num) {
	return (*input)[num];
}

//Num is index of relevant link object
void Node::setOutput(int num) {
	(*output)[num] = num;
	stale = true;
}

//You should probably use isStale to make sure this is meaningful
int Node::getOutput(int num) {
	return (*output)[num];
}

//Provides actual functionality! Node is kinda useless without it
void Node::setLogic(NodeLogic* newLogic) {
	logic = newLogic;
	stale = true;
}

//Removes references to link at index num
void Node::sanitize(int num) {
	for (int i = 0; i < input->size(); i++) {
		(*input)[i] = (*input)[i] != num ? (*input)[i] : stale = true, NULL;
	}
	for (int i = 0; i < output->size(); i++) {
		(*output)[i] = (*output)[i] != num ? (*output)[i] : stale = true, NULL;
	}
}