#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
vector <int> v[MAXN];
int n,innum[MAXN];
bool isRead[MAXN];

int dfs(int nowfrom,int nowans){
	//cout<<114514;
	if(isRead[nowfrom]) return nowans;
	else{
		nowans++;
		isRead[nowfrom] = 1;
		for(int i = 0; i < v[nowfrom].size(); i++){
			nowans = dfs(v[nowfrom][i],nowans);
		}
		return nowans;
	}
}

int main(){
	cin>>n;
	int nowp;
	for(int i = 1; i <= n; i++){
		cin>>nowp;
		v[i].push_back(nowp);
		innum[nowp]++;
	}
	queue <int> q;
	for(int i = 1; i <= n; i++){
		if(innum[i] == 0){
			q.push(i);
		}
	}
	int nowtop;
	while(!q.empty()){
		nowtop = q.front();
		q.pop();
		for(int i = 0; i < v[nowp].size(); i++){
			innum[v[nowtop][i]]--;
			if(innum[v[nowtop][i]] == 0){
				q.push(v[nowtop][i]);
			}
		}
	}
	int ans = INT_MAX;
	for(int i = 0; i <= n; i++){
		if(innum[i] != 0 && isRead[i] == 0){
			ans = min(ans,dfs(i,0));
		}
	}
	cout<<ans;
	return 0;
}