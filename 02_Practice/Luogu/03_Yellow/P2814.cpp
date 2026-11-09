#include<bits/stdc++.h>
using namespace std;

map <string,string> m;

void init(string s){
	m[s] = s;
}

string find(string s){
	if(m[s] == s){
		return s;
	}
	return m[s] = find(m[s]);
}

void marge(string f,string s){
	string ff = find(f), fs = find(s);
	if(fs != ff){
		m[fs] = ff;
	}
}

char op;
string nowf,nows;
int main(){
	bool flag = 1;
	while(flag){
		cin>>op;
		switch(op){
			case '$':{
				flag = 0;
				break;
			}
			case '#':{
				cin>>nowf;
				if(m.find(nowf) == m.end()){
					init(nowf);
					break;				
				}
				nowf = find(nowf);
				break;
			}
			case '+':{
				cin>>nows;
				init(nows);
				marge(nowf,nows);
				break;
			}
			case '?':{
				cin>>nows;
				cout<<nows<<' '<<find(nows)<<endl;
				break;
			}		
		}
	}
	return 0;
}