// P1048 [NOIP 2005 普及组] 采药
#include<bits/stdc++.h>
using namespace std;

int t,m,Ttime[1005],value[1005],f[1005][1005];
int main(){
	cin >> t >> m;
	for (int i = 1;i <= m;i++){
		cin >> Ttime[i] >> value[i];
	}
	for (int i = 1;i <= m;i++){
		for (int j = 1;j <= t;j++){
			if(j < Ttime[i]){
				f[i][j] = f[i-1][j];
				continue;
			}
			f[i][j] = max(f[i-1][j],f[i-1][j-Ttime[i]]+value[i]);
		}
	}
	cout << f[m][t];
	return 0;
}