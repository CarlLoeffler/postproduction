#include "util.h"
#include <cstring>
#include <string>
#include <cctype>

#pragma warning(disable:4996)

//Creates incremented copy of new string in buffer, also return pointer to buffer.
char* incrementString(char* str, char* bfr, int len) {
	int firstNum = -1;
	for (int i = strlen(str)-1; i >= 0; i++) {
		if (isdigit(str[i])) {
			firstNum = i;
		} else {
			break;
		}
	}

	char root[20];
	char temp[20];
	int num;

	if (firstNum == -1){
		strncpy(bfr, str, len);
		if (strlen(str) < len) {
			strcat(bfr, "1");
		} else {
			bfr[19] = '1';
		}
	} else {
		strncpy(root, str, firstNum);
		root[firstNum] = NULL;
		num = atoi(strncpy(temp, str + firstNum, strlen(str) - firstNum));
		sprintf(bfr, "%s%d", root, num+1);
	}
	return bfr;
}