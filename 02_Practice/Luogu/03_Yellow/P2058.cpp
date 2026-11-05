#include<bits/stdc++.h>
const int MAXK = 3e5 + 5;
const int MAXN = 1e5 + 5;
using namespace std;
struct people{
	long long t,c;
};
queue<people> q;
int ansnow,ans[MAXN],cont[MAXN];
int n;
int main(){
	cin>>n;
	int nowt,nowk;
	people nowp,nowtop;
	for(int i = 1; i <= n; i++){
		cin>>nowt>>nowk;
		while(nowt - 86400 >= q.front().t && (!q.empty())){
			nowtop = q.front();
			cont[nowtop.c]--;
			if(cont[nowtop.c] == 0){
				ansnow--;
			}
			q.pop();
		}
		for(int j = 1; j <= nowk; j++){
			cin>>nowp.c;
			if(cont[nowp.c] == 0){
				ansnow++;
			}
			cont[nowp.c]++;
			nowp.t = nowt;
			q.push(nowp);	
		}
		ans[i] = ansnow;	
	}
	for(int i = 1; i <= n; i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}