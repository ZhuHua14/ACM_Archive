#include<bits/stdc++.h>
using namespace std;
const int MAXN = 105;
int f1[MAXN * 2][MAXN * 2],f2[MAXN * 2][MAXN * 2],a[MAXN * 2],n,sum[MAXN];

int main(){
	cin >> n;
	//memset(f1,-0x3f,sizeof(f1));
	memset(f2,0x3f,sizeof(f2));
	sum[0] = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		a[i + n] = a[i];
		f2[i][i] = f2[i + n][i + n] = 0;
	}
	for(int i = 1; i <= n * 2; i++){
		sum[i] = sum[i - 1] + a[i];
	}
	for(int len = 2; len <= n; len++){
		for(int l = 1; l + len - 1 <= n * 2; l++){
			int r = l + len - 1;
			for(int k = l; k < r; k++){
				f1[l][r] = max(f1[l][r],f1[l][k] + f1[k + 1][r] + (sum[r] - sum[l - 1]));
				f2[l][r] = min(f2[l][r],f2[l][k] + f2[k + 1][r] + (sum[r] - sum[l - 1]));
			}
		}
	}
	int ans1 = -1e9,ans2 = 1e9;
	for(int i = 1; i <= n; i++){
		ans1 = max(f1[i][i + n - 1],ans1);
		ans2 = min(f2[i][i + n - 1],ans2);
	}
	cout << ans2 << endl << ans1;
	return 0;
}