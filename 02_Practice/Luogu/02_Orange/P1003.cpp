// P1003 [NOIP 2011 提高组] 铺地毯
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
struct CARPET{
	int right,left,up,down,num;
};
CARPET inp,nowtop;
CARPET st[MAXN];
int n,inl,ind,ing,cnt,ink,ansx,ansy;
bool Onit(CARPET now,int pointx,int pointy){
	return (pointx >= now.left) && (pointx <= now.right) && (pointy >= now.down) && (pointy <= now.up);	
}
bool cmp(CARPET x1,CARPET x2){
	return x1.num > x2.num;
}
int main(){
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>inl>>ind>>ing>>ink;
		inp.left = inl;
		inp.down = ind;
		inp.right = inl + ing;
		inp.up = ind + ink;
		inp.num = i;
		st[++cnt] = inp;
	}
	sort(st + 1,st + 1 + cnt,cmp);
	cin>>ansx>>ansy;
	for(int i = 1; i <= cnt; i++){
		nowtop = st[i];
		if(Onit(nowtop,ansx,ansy)){
			cout<<nowtop.num;
			return 0;
		}
	}
	cout<<-1;
	return 0;
}