// P1113 [USACO02FEB] 杂物
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;

int n,value[MAXN],ans[MAXN];
bool isRead[MAXN];
vector <int> v[MAXN];

int dfs(int nowp){
	if(isRead[nowp] == 1){
		return ans[nowp];
	}
	for(int i = 0; i < v[nowp].size(); i++){
		ans[nowp] = max(ans[nowp],dfs(v[nowp][i]));
	}
	ans[nowp] += value[nowp];
	isRead[nowp] = 1;
	return ans[nowp];
}
int main(){
	cin>>n;
	int nowp,nowval,nowfrom;
	for(int i = 1; i <= n; i++){
		cin>>nowp>>nowval;
		value[nowp] = nowval;
		while(1){
			cin>>nowfrom;
			if(nowfrom == 0){
				break;
			}
			v[nowp].push_back(nowfrom);
		}
	}
	int nowans = 0;
	for(int i = 1; i <= n; i++){
		nowans = max(dfs(i),nowans);
	}
	cout<<nowans;
	return 0;
}