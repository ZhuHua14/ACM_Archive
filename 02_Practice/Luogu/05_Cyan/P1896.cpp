#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 100;

ll n,k,f[15][1 << 11][MAXN];

ll lowbit(ll x){
    return x & (-x);
}

bool check1(ll x){
    return ((((x >> 1) & x) == 0)) && (((x << 1) & x) == 0);
}

bool check2(ll x,ll y){
    return ((((x >> 1) & y) == 0)) && (((x << 1) & y) == 0) && ((x & y) == 0);
}

ll popcount(ll x){
	ll ans = 0;
	while(x > 0){
		x -= lowbit(x);
		ans++;
	}
	return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
	f[0][0][0] = 1;
	for(int i = 0; i < (1 << n); i++){
		if(check1(i)){
			f[1][i][popcount(i)] = 1;
		}
	}
    for(int i = 2; i <= n; i++){
		for(int now = 0; now < (1 << n); now++){
				for(int pre = 0; pre < (1 << n); pre++){
					if(check1(now) && check1(pre) && check2(pre,now)){
						ll cnt = popcount(now);
						for(int j = k; j >= cnt; j--){
							f[i][now][j] += f[i - 1][pre][j - cnt];
						}
					}
				}	
		}
    }
    ll ans = 0;
    for(int i = 0; i < (1 << n); i++){
        ans += f[n][i][k];
    }
    cout << ans << endl;
    return 0;
}