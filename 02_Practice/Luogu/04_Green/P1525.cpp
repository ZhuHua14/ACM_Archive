#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e4 + 5;
const int MAXM = 1e5 + 5;
struct Node{
	int e1,e2,c;
}llist[MAXM];

int fa[MAXN],en[MAXN];
int n,m;

bool cmp(Node x,Node y){
	return x.c > y.c;
}

void init(){
	for(int i = 1; i <= n; i++){
		fa[i] = i;
	}
	return;
}

int find(int s){
	if(fa[s] == s) return s;
	return fa[s] = find(fa[s]);	
}
void marge(int f,int s){
	int ff = find(f),fs = find(s);
	if(ff == fs){
		return;
	}
	else{
		fa[fs] = ff;
		return;
	}
}
bool check(int f,int s){
	int ff = find(f),fs = find(s);
	if(ff == fs) return 1;
	return 0;
}
void output(){
	cout<<"en:";
	for(int i = 1; i <= n; i++){
		cout<<en[i]<<' ';
	}
	cout<<endl;
}

int main(){
	cin>>n>>m;
	init();
	for(int i = 1; i <= m; i++){
		cin>>llist[i].e1>>llist[i].e2>>llist[i].c;
	}
	sort(llist + 1, llist + m + 1, cmp);
	bool flag = 1;
	for(int i = 1; i <= m; i++){
		//cout<<find(llist[i].e1)<<' '<<find(llist[i].e2)<<endl;
		if(check(llist[i].e1,llist[i].e2)){
			cout<<llist[i].c;
			flag = 0;
			break;
		}
		else{
			//output();
			if(en[llist[i].e1] != 0){
				marge(en[llist[i].e1],llist[i].e2);				
			}
			else{
				en[llist[i].e1] = llist[i].e2;
			}
			if(en[llist[i].e2] != 0){
				marge(en[llist[i].e2],llist[i].e1);	
			}
			else{
				en[llist[i].e2] = llist[i].e1;			
			}
		}
	}
	if(flag) cout<<0;
	return 0;
}