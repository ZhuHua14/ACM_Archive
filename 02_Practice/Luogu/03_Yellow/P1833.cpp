// P1833 樱花
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 15e4 + 5;
const int MAXT = 1e3 + 5;

ll val[MAXN],t[MAXN],n,t_s,cnt,f[2][MAXT];
bool isclear[MAXN];
string nowt,endt;

ll mul(string t1,string t2){
    ll h1 = (t1[2] == ':')? ((t1[0] - '0') * 10 + (t1[1] - '0')):(t1[0] - '0');
    ll h2 = (t2[2] == ':')? ((t2[0] - '0') * 10 + (t2[1] - '0')):(t2[0] - '0');
    ll m1 = (t1[2] == ':')? ((t1[3] - '0') * 10 + (t1[4] - '0')):((t1[2] - '0') * 10 + (t1[3] - '0'));
    ll m2 = (t2[2] == ':')? ((t2[3] - '0') * 10 + (t2[4] - '0')):((t2[2] - '0') * 10 + (t2[3] - '0'));
    return ((h1 - h2) * 60 + (m1 - m2));    
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> nowt >> endt >> n;
	ll ti,ci,pi;
	for(int i = 1; i <= n; i++){
		cin >> ti >> ci >> pi;
		if(pi == 0){
			isclear[++cnt] = 1;
			val[cnt] = ci;
			t[cnt] = ti;
		}
		else{
			ll j = 0,sum = 0;
            while((sum + (1 << j)) <= pi){
                val[++cnt] = ci * (1 << j);
                t[cnt] = ti * (1 << j);
                sum += (1 << j);
                j++;
            }
			if(sum < pi){
    			val[++cnt] = ci * (pi - sum);
			    t[cnt] = ti * (pi - sum);
            }
		}
	}
    t_s = mul(endt,nowt);
    for(int i = 1; i <= cnt; i++){
        for(int j = 1; j <= t_s; j++){
            if(isclear[i]){
                if(j >= t[i]) f[i % 2][j] = max(f[(i - 1)% 2][j],f[i % 2][j - t[i]] + val[i]);
                else f[i % 2][j] = f[(i - 1)% 2][j];
            }
            else{
                if(j >= t[i]) f[i % 2][j] = max(f[(i - 1)% 2][j],f[(i - 1)% 2][j - t[i]] + val[i]);
                else f[i % 2][j] = f[(i - 1)% 2][j];
            }
        }
    }
	cout << f[cnt % 2][t_s];
    return 0;
}