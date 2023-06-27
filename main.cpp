#include"BasicC.h"
#include"runtime.h"

int main(int argc,char** argv,char** envp) {
	printf("Welcome to EasyScript v1.0 Beta 5!\nBy SunLight Studio.\n\n");
	char s[]="print(\"Hello World\\n\");i++";
	Eval(s);
	printf(s);
	return 0;
}
