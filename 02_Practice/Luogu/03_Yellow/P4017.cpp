// P4017 最大食物链计数
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e3 + 5;
const int MOD = 80112002;
int innum[MAXN],outnum[MAXN],ans[MAXN],n,m;
vector <int> v[MAXN];

int main(){
	cin>>n>>m;
	int nowf,nowt;
	for(int i = 1; i <= m; i++){
		cin>>nowf>>nowt;
		innum[nowt]++;
		outnum[nowf]++;
		v[nowf].push_back(nowt);
	}
	queue <int> q;
	for(int i = 1; i <= n; i++){
		if(innum[i] == 0){
			ans[i] = 1;
			q.push(i);
		}
	}
	int nowtop;
	while(!q.empty()){
		//cout<<"114514";
		nowtop = q.front();
		q.pop();
		for(int i = 0; i < v[nowtop].size(); i++){
			innum[v[nowtop][i]]--;
			ans[v[nowtop][i]] = (ans[v[nowtop][i]] + ans[nowtop]) % MOD;
			if(innum[v[nowtop][i]] == 0){
				q.push(v[nowtop][i]);
			}
		}
	}
	int nowans = 0;
	for(int i = 1; i <= n; i++){
		if(outnum[i] == 0){
			nowans = (nowans + ans[i]) % MOD;
		}
	}
	cout<<nowans;
	return 0;
}