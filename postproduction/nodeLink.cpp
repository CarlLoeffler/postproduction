#pragma once

#include "nodeLink.h"

//construct link in the graph with default name
//If the link exists only to store represent an ouput and has no destination, pass -1 in dest array
NodeLink::NodeLink(int src[2], int dest[2]) {
	sourceNode = src[0];
	destNode = dest[0];
	sourcePort = src[1];
	destPort = dest[1];
	strcpy(name, "unnamed");
	name[20] = NULL;
}

//construct link in the graph
//If the link exists only to store represent an ouput and has no destination, pass -1 as dest
NodeLink::NodeLink(char* newName, int src[2], int dest[2]) {
	sourceNode = src[0];
	destNode = dest[0];
	sourcePort = src[1];
	destPort = dest[1];
	strncpy(name, newName, 19);
	name[20] = NULL;
	stale = true;
}

//I'm not sure why this would even get called.
NodeLink::~NodeLink() {
	sourceNode = -1;
	destNode = -1;
	sourcePort = -1;
	destPort = -1;
	strcpy(name, "unnamed");
	name[20] = NULL;
	stale = true;
}

//returns index of source node
int NodeLink::getSourceNode() {
	return sourceNode;
	stale = true;
}

//returns index of dest node
int NodeLink::getDestNode() {
	return destNode;
}

//set source node + port. src{nodeNum, portNum}
void NodeLink::setSource(int src[2]) {
	sourceNode = src[0];
	sourcePort = src[1];
	stale = true;
}

//set destination node + port. dest{nodeNum, portNum}
void NodeLink::setDest(int dest[2]) {
	destNode = dest[0];
	destPort = dest[1];
	stale = true;
}

//set display name of link + associated image
void NodeLink::setName(char* newName) {
	strncpy(name, newName, 19);
}

//get display name of link + associated image
char* NodeLink::getName() {
	return name;
}

//Sets internal mat to reference to argument. Memory safe through openCV magic?
//Clears stale flag
//You can put things that aren't the correct image in here but that would break everything so don't.
void NodeLink::setData(PPImg newData) {
	data = newData;
	stale = false;
}

//returns refernce to internal Mat
//Probably check to make sure the data isn't stale?
PPImg NodeLink::getData() {
	return data;
}

bool NodeLink::isStale() {
	return stale;
}

void NodeLink::sanitize(int num) {
	sourceNode = sourceNode == num ? NULL : stale = true, sourceNode;
	destNode = destNode == num ? NULL : stale = true, destNode;
}
