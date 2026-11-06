#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 5e3 + 5;

ll n,m,a[MAXN][MAXN],diff[MAXN][MAXN];


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    int x,y,p,q;
    while(m--){
    	cin >> x >> y >> p >> q;
    	diff[x][y]++;
    	diff[p + 1][y]--;
    	diff[x][q + 1]--;
    	diff[p + 1][q + 1]++;
    }
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= n; j++){
    		a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + diff[i][j];
    	}
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= n; j++){
    		ans += (i + j) ^ a[i][j];
    	}
    }
    cout << ans << '\n';
    return 0;
}