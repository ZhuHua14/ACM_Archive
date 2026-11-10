// P1063 [NOIP 2006 提高组] 能量项链
#include<bits/stdc++.h>
using namespace std;
struct ball{
	int top,bottom;
}bot[210];
int f[210][210];
//f[l][r]=max(f[l][r],f[l][k]+f[k+1][r]+bot[l].top*bot[k].bottom*bot[r].bottom)
int main(){
	int N;
	cin >> N;
	for(int i=1;i<=N;i++){
		cin >> bot[i].top;
	}
	for(int i=1;i<=N;i++){
		bot[i-1].bottom = bot[i].top;
	}
	bot[N].bottom=bot[1].top;
	for(int i=1;i<=N;i++){
		bot[i+N].top = bot[i].top;
		bot[i+N].bottom = bot[i].bottom;
	}
	for(int len=1;len<=N;len++){
		for(int l=1;l<=2*N-len-1;l++){
			int r=l+len;
			for(int k=l;k<r;k++){
				f[l][r]=max(f[l][r],f[l][k]+f[k+1][r]+bot[l].top*bot[k].bottom*bot[r].bottom);
			}
		}
	}
	int ans=-100;
	for(int i=1;i<=N;i++){
		ans = max(ans,f[i][i+N-1]);		
	}
	cout << ans ;
	return 0;
}