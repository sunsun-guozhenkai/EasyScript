#ifndef SLS_ES_BASICC_HEADER
#define SLS_ES_BASICC_HEADER

#include <string>
#include <cstring>
#include <stdlib.h>
#include <ctype.h>
#include <map>
#include <vector>

using namespace std;

#ifdef _WIN32
#include<windows.h>
#endif

#define byte char
#define int64 long long
#define uf unsigned
#define unllptr 0

struct vars{
	byte type;
	void* point;
};

struct RTC{
	string o;
	string v;
	int64 n;
};

#endif
