#pragma once

#include "PPImg.h"

class NodeLink {
public:
	NodeLink(int src[2], int dest[2]);
	NodeLink(char* name, int src[2], int dest[2]);
	~NodeLink();
	int getSourceNode();
	int getDestNode();
	void setSource(int src[2]);
	void setDest(int dest[2]);
	void setName(char* name);
	char* getName();
	void setData(PPImg newData);
	PPImg getData();
	void sanitize(int num);
	bool isStale();

private:
	//NodeLink does not store its constituent nodes, all node access is mediated through NodeList.
	PPImg data;
	bool stale;
	char name[20];
	int sourceNode;
	int sourcePort;
	int destNode;
	int destPort;
};