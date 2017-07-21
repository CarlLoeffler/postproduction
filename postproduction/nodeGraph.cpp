#pragma once

#include "nodeGraph.h"

//Nodegraph stores node editor state
NodeGraph::NodeGraph() {
	nodeList = new std::vector<Node*>;
	linkList = new std::vector<NodeLink*>;
}

//cleaning up after ourselves...
NodeGraph::~NodeGraph() {
	for (int i = 0; i < nodeList->size(); i++) {
		delete (*nodeList)[i];
	}
	for (int i = 0; i < linkList->size(); i++) {
		delete (*linkList)[i];
	}
}

//add generic node to graph
//uses sparse array implemented on vector
int NodeGraph::addNode() {
	Node* temp = new Node();
	int i = 0;
	for (i = 0; i < nodeList->size(); i++) {
		if ((*nodeList)[i] == NULL) {
			(*nodeList)[i] = temp;
			return i;
		}
	}
	nodeList->push_back(temp);
	return i;
}

//remove node from graph by index
void NodeGraph::removeNode(int num) {
	//remove node
	delete (*nodeList)[num];
	(*nodeList)[num] = NULL;

	//Remove any links to/from deleted node
	for (int i = 0; i < linkList->size(); i++) {
		if ((*linkList)[i]->getSourceNode() == num || (*linkList)[i]->getDestNode() == num) {
			delete (*linkList)[i];
			(*linkList)[i] = NULL;
		}
	}
}

//adds link between nodes to nodegraph
//argument format is [node num, port num]
int NodeGraph::addLink(int src[2], int dest[2]) {
	NodeLink* temp = new NodeLink(src, dest);
	int i = 0;
	for (i = 0; i < nodeList->size(); i++) {
		if ((*linkList)[i] == NULL) {
			(*linkList)[i] = temp;
			return i;
		}
	}
	linkList->push_back(temp);
	return i;
}

//Remove link from nodegraph.
//Note: since links represent/store images, this will remove that image from the image list.
void NodeGraph::removeLink(int num) {
	delete (*linkList)[num];
	(*linkList)[num] = NULL;
}

/*
//Return node by index in nodelist. Only way to directly access node object
Node* NodeGraph::getNode(int num) {
	return (*nodeList)[num];
}
*/

//Cleans nodes of references to links that have been removed?
//WIP: Finish.
//WIP: roll into the removeLink function + add equiv for nodes
void NodeGraph::sanitize(int num) {
	for (int i = 0; i < nodeList->size(); i++) {
		(*nodeList)[i]->sanitize(num);
	}
	for (int i = 0; i < linkList->size(); i++) {
		(*linkList)[i]->sanitize(num);
	}
}

