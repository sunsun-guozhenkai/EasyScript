#ifndef SLS_ES_RUNTIME_HEADER
#define SLS_ES_RUNTIME_HEADER

#define Eval_Z if(code[i]=='\\')i+=2

map<string,varst> var;
const char opr_chr[]="+-*/%&|!><=.,@()[]{}^~";
const char str_chr[]="\"\'`";

int64 StrType(int c){
	for(int i=0;i<sizeof(opr_chr);i++){
		if(c==opr_chr[i]){
			return 1;
		}
	}
	if(isspace(c))return 2;
	return 0;
}
int64 StrIs(int c){
	for(int i=0;i<sizeof(str_chr);i++){
		if(c==str_chr[i]){
			return 1;
		}
	}
	return 0;
}

int64 Eval(char* code){
	int64 size=strlen(code);
	int64 word=0;
	int64 i=0,t=0;
	vector<int64> start;
	vector<int64> end;
	bool istart=false;
	bool isnum=false;
	//这段是预处理，分割并记录每个词 
	//目前问题：没有对批注的兼容、单独的反斜杠加字母会被忽略 
	while(i<size){
		//空格 
		while(isspace(code[i])&&i<size)i++;
		if(StrIs(code[i])){
			printf("a\n");
			//字符串 
			start.push_back(i);
			t=i;
			for(i++;code[i]!=code[t]/*&&i<size*/;i++)
			end.push_back(i+1);
			word++;
		}else if(code[i]=='\\'){
			//转义符 
			i+=2;
		}else{
			printf("b\n");
			//其他 
			start.push_back(i);
			for(;StrType(code[i])==StrType(code[i+1])&&i<size;i++);
			end.push_back(i+1);
			word++;
			//continue;
		}
		t=0;
		i++;
	}
	for(int i=0;i<word;i++){
		printf("#%d  -->  %d\n>>>",start[i],end[i]);
		for(int j=start[i];j<end[i];j++){
			printf("%c",code[j]);
		}
		printf("\n");
	}
}

#endif
