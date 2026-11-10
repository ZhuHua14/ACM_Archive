// P2024 [NOI 2001] 食物链
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5e4 + 5;

int n;
int fa[3 * MAXN];

int find(int s){
	return (fa[s] == s)? s:(fa[s] = find(fa[s]));
}

void init(){
	for(int i = 1; i <= 3 * n; i++){
		fa[i] = i;
	}
}
void marge(int f, int s){
	int ff = find(f), fs = find(s);
	if(ff != fs){
		fa[fs] = ff;
	}
}

bool check(int op,int x,int y){
	bool flag = 1;
	if(find(x) == x && find(y) == y) flag = 0;
	if(x > n || y > n){
		return 0;
	}	
	else if(op == 2 && ((x == y) || (find(x) == find(y)) || (find(y) == find(x + 2 * n)))){
		return 0;
	}
	else if(op == 1 && (find(x) == find(y + 2 * n)) || find(x) == find(y + n)){
		return 0;
	}
	return 1;
}

int k,nowop,nowx,nowy,ans;
int main(){
	cin>>n>>k;
	init();
	for(int i = 1 ; i <= k; i++){
		cin>>nowop>>nowx>>nowy;
		//cout<<check(nowop,nowx,nowy)<<endl;
		if(!check(nowop,nowx,nowy)){
			ans++;
			continue;
		}
		else{
			switch(nowop){
				case 1:{
					marge(nowx,nowy);
					marge(nowx + n,nowy + n);
					marge(nowx + 2 * n,nowy + 2 * n);
					break;
				}
				case 2:{
					marge(nowx,nowy + 2 *n);
					marge(nowx + n,nowy);
					marge(nowx + 2 * n,nowy + n);					
					break;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}