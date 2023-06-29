#include"BasicC.h"
#include"runtime.h"

int main(int argc,char** argv,char** envp) {
	printf("Welcome to EasyScript v0.1!\nBy SunLight Studio.\n\n");
	char s[1024];
	EasyScript ES;
	while(1){
		printf("\n>>>");
		gets(s);
		ES.Eval(s);
	}
	
	return 0;
}
