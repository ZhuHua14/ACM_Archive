#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e3 + 5;
int n,m,p;

int fa[MAXN];
void init(){
	for(int i = 1; i <= n; i++){
		fa[i] = i;
	}
	return;
}

int find(int x){
	if(x == fa[x]) return x;
	else{
		return fa[x] = find(fa[x]);
	}
}

void marge(int f,int s){
	int ff = find(fa[f]), fs = find(fa[s]);
	fa[fs] = ff;
}

int main(){
	cin>>n>>m>>p;
	init();
	int nowf,nows;
	for(int i = 1; i <= m; i++){
		cin>>nowf>>nows;
		marge(nowf,nows);
	}
	for(int i = 1; i <= p; i++){
		cin>>nowf>>nows;
		if(find(nowf) == find(nows)){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}
	}
	return 0;
}