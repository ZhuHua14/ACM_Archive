#include<bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
struct Node{
	int data;
	int lefts = INF,rights = INF;
};
Node tree[36];
int n;
int toint(char c){
	if(c == '*') return INF;
	else{
		return c - 'a';
	}
}
char tochar(int i){
	if(i == INF) return '*';
	else{
		return 'a' + i;
	}
}
Node Create(int d,int l,int r){
	Node ans;
	ans.data = d;
	ans.lefts = l;
	ans.rights = r;
	return ans;
}
void dfs(int nowp){
	cout<<tochar(tree[nowp].data);
	if(tree[nowp].lefts != INF)	dfs(tree[nowp].lefts);
	if(tree[nowp].rights != INF) dfs(tree[nowp].rights);
	return;
}
int main(){
	cin>>n;
	string nownode;
	int root = INF;
	for(int i = 1; i <= n; i++){
		cin>>nownode;
		if(i == 1){
			root = toint(nownode[0]);
		}
		tree[toint(nownode[0])] = Create(toint(nownode[0]),toint(nownode[1]),toint(nownode[2]));
	}
	dfs(root);
	return 0;
}