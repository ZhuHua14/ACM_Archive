#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[55][55],vis[55][55],f[55][55][55][55];
int maxinfour(int a,int b,int c,int d){
	return max(max(a,b),max(c,d));
}
signed main(){
//	freopen("dp.in","r",stdin);
//	freopen("dp.out","w",stdout);
	int m,n;
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=m;i++){
	for(int j=1;j<=n;j++){
	for(int k=1;k<=m;k++){
	for(int l=1;l<=n;l++){
		if(i==k&&j==l){
			f[i][j][k][l]=maxinfour(f[i-1][j][k-1][l],f[i-1][j][k][l-1],f[i][j-1][k-1][l],f[i][j-1][k][l-1])+a[i][j];
			continue;
		}
		f[i][j][k][l]=maxinfour(f[i-1][j][k-1][l],f[i-1][j][k][l-1],f[i][j-1][k-1][l],f[i][j-1][k][l-1])+a[i][j]+a[k][l];
	}
	}
	}
	}
	cout<<f[m][n][m][n];
}