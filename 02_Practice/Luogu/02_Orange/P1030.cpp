#include<bits/stdc++.h>
using namespace std;

string medium,back;

void dfs(int bl,int br,int ml,int mr){
	int cnt;
	for(int i = ml; i <= mr; i++){
		//cout<<i<<"    "<<bl<<'-'<<br<<' '<<ml<<'-'<<mr<<' '<<back[br]<<endl;
		if(back[br] == medium[i]){
			cout<<back[br];
			dfs(bl,bl + i - ml - 1,ml,i - 1);
			dfs(bl + i - ml, br - 1,i + 1,mr);
		//	cout<<endl;
			return;
		}
	}
}

int main(){
	cin>>medium>>back;
	dfs(0,back.size() - 1,0,medium.size() - 1);
	return 0;
}