#include<bits/stdc++.h>
#include<fstream>
#include<string.h>

using namespace std;

class date{public:
	int d, m, y;
};

int StrCmp(string a, string b){
	if(a.length()!=b.length())
		return 0;
	else{
		for(int i=0;i<b.length();i++){
			if(toupper(a[i])!=toupper(b[i]))
				return 0;
		}
	}
	return 1;
}
int Search(char a[], char b[]){
//	if(strlen(a)!=strlen(b))
//		return 1;
//	else{
		for(int i=0;i<strlen(b);i++){
			if(toupper(a[i])!=toupper(b[i]))
				return 1;
		}
//	}
	return 0;
}
