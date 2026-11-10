// P5514 [MtOI2019] 永夜的报应
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;

vector <int> m[MAXN];
bool isRead[MAXN];

void dfs(int e){
	cout<<e<<' ';
	int maxn = m[e].size();
	for(int i = 0; i < maxn; i++){
		if(!isRead[m[e][i]]){
			isRead[m[e][i]] = 1;			
			dfs(m[e][i]);
	
		}
	}
}
int n,mm;


void bfs(){
	queue <int> q;
	int nowsize,nowf,nowtop;
	q.push(1);
	isRead[1] = 1;
	while(!q.empty()){
		nowf = q.front();
		q.pop();		
		cout<<nowf<<' ';
		nowsize = m[nowf].size();
		for(int i = 0; i < nowsize; i++){
			nowtop = m[nowf][i];
			if(!isRead[nowtop]){
				q.push(nowtop);
				isRead[nowtop] = 1;					
			}
		}
	}
}



int main(){
	std::ios::sync_with_stdio(false);
	cin>>n>>mm;
	int nownow,nownext;
	for(int i = 1; i <= mm; i++){
		cin>>nownow>>nownext;
		m[nownow].push_back(nownext);
	}
	for(int i = 0; i <= n; i++){
		sort(m[i].begin(),m[i].end());
	}
	isRead[1] = 1;
	dfs(1);
	cout<<endl;
	memset(isRead,0,sizeof(isRead));
	bfs();
	return 0;
}