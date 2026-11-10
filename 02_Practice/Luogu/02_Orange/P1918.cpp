// P1918 保龄球
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;

map <int,int> st;

int n,q;

pair <int,int> Create(int f,int s){
	pair <int,int> ans;
	ans.first = f;
	ans.second = s;
	return ans;
}
int main(){
	int n;
	cin>>n;
	int nowball;
	for(int i = 1; i <= n; i++){
		cin>>nowball;
		st.insert(Create(nowball,i));
	}
	cin>>q;
	for(int i = 1; i <= q; i++){
		cin>>nowball;
		cout<<st[nowball]<<endl;
	}
	return 0;
}