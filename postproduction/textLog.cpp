#include "textLog.h"
#include <stdarg.h>
#include <cstdio>

void logPrintf(char* formatString, ...) {
	va_list args;
	va_start(formatString, args);
	char* logString;
	vsnprintf(logString, 20, formatString, args);
	va_end(args);
}