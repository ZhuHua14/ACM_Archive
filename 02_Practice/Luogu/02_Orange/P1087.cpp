// P1087 [NOIP 2004 普及组] FBI 树
#include<bits/stdc++.h>
using namespace std;
int pow2[12] = {1,2,4,8,16,32,64,128,256,512,1024,2048};
const int MAXN = 2200;
char tree[MAXN];
int n;
void build(int nown){
	int l,r;
	while(nown > 0){
		l = pow2[nown] , r = pow2[nown + 1] - 1;
		for(int i = l; i <= r; i += 2){
			tree[(i + 1) / 2 ] = (tree[i] == tree[i + 1])? tree[i] : 'F';
		}
		nown--;
	}
}

void back(int nowp){
	int lim = pow2[n + 1],ls = nowp * 2,rs = nowp * 2 + 1;
	if(ls < lim) back(ls);
	if(rs < lim) back(rs);
	cout<<tree[nowp];
}

int main(){
	cin>>n;
	string nowin;
	cin>>nowin;
	for(int j = 0,i = pow2[n]; i <= pow2[n + 1] - 1; i++ , j++){
		if(nowin[j] == '0') tree[i] = 'B';
		else tree[i] = 'I';
	}
	build(n);
	back(1);
	return 0;
}