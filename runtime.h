#ifndef SLS_ES_RUNTIME_HEADER
#define SLS_ES_RUNTIME_HEADER

#define Eval_Z if(code[i]=='\\')i+=2

map<string,vars> var;
const char opr_chr[]="+-*/%&|!><=,@()[]{}^~";
const char str_chr[]="\"\'`";
const char otr_chr[]=";\n";

int64 StrType(int c){
	for(int i=0;i<sizeof(opr_chr);i++){
		if(c==opr_chr[i]){
			return 1;
		}
	}
	for(int i=0;i<sizeof(otr_chr);i++){
		if(c==otr_chr[i]){
			return 2;
		}
	}
	if(isspace(c))return 3;
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
bool AllOpr(char* code,int64 s,int64 e){
	for(int i=s;i<e;i++){
		for(int j=0;j<sizeof(opr_chr);j++){
			if(code[i]!=opr_chr[j]){
				return 0;
			}
		}
	}
	return 1;
}
bool AllNum(char* code,int64 s,int64 e){
	for(int i=s;i<e;i++){
		if(!(code[i]<='9'&&code[i]>='0')){
			return 0;
		}
	}
	return 1;
}


class EasyScript{
	

	vector<int64> start;
	vector<int64> end;
	vector<RTC> rtc;
	int64 size;
	char* code;
	
	int64 word=0,p=0;
	bool ErrFlag=1;
	
	string SubStr(){
		string ret="";
		for(int64 i=start[p];i<end[p];i++){
			ret+=code[i];
		}
		return ret;
		
	}
	/* 
	bool CatchErr(string c){
		ErrFlag=0;
		printf("[ES]%s\n",c.c_str());
	}
	
	bool GetOprNum(string o){
		static int64 basic_ret;
		switch(o){
			case "(":
				basic_ret++;
				p++;
				return GetOprNum() 
			default:
				CatchErr("No operator <"+o+">");
		}
	}
	*/
	int64 EvalLine(){
		string tmp=SubStr();
		
		/*RTC r;
		for(;SubStr(Str,start[p],end[p])!=';'&&ErrFlag;p+=2){
			if()
			r.n=GetOprNum(SubStr(Str,start[p],end[p]));
			r.o=SubStr(Str,start[p],end[p]);
			r.v=SubStr(Str,start[p+1],end[p+1]);
		}*/
		if(tmp=="print"){
			p++;
			printf("%s\n",SubStr().c_str());
		}else if(tmp=="command"){
			p++;
			system(SubStr().c_str());
		}else{
			printf("Err %s",SubStr().c_str());
		}
		p++;
	}
	public :
	int64 Eval(char* str){
		code=str;
		int64 i=0,t=0;
		word=0,p=0;
		size=strlen(code);
		start.clear();
		end.clear();
		//�����Ԥ�����ָ��¼ÿ���� 
		//Ŀǰ���⣺û�ж���ע�ļ��ݡ������ķ�б�ܼ���ĸ�ᱻ���� 
		while(i<size){
			//�ո� 
			while(isspace(code[i])&&i<size)i++;
			if(StrIs(code[i])){
				//�ַ��� 
				start.push_back(i);
				t=i;
				for(i++;code[i]!=code[t]&&i<size;i++);
				end.push_back(i+1);
				word++;
			}else if(code[i]=='\\'){
				//ת��� 
				i+=2;
			}else{
				//���� 
				start.push_back(i);
				for(;StrType(code[i])==StrType(code[i+1])&&i<size;i++);
				end.push_back(i+1);
				word++;
				//continue;
			}
			t=0;
			i++;
		}
		while(p<word)EvalLine();
	}
};
#endif
