#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 1e3 + 5;
const int MOD = 998244353;

int T,id,n,m,cc,cf;
int cb[MAXN][MAXN];

struct Node{
    int u,d,r;
};
Node f[MAXN][MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T >> id;
    while(T--){
        memset(cb,0,sizeof(cb));
        cin >> n >> m >> cc >> cf;
        string s;
        for(int i = 1; i <= n; i++){
            cin >> s;
            for(int j = 0; j < s.size(); j++){
                cb[i][j + 1] = s[j] - '0';
            }
        }
        for(int i = 1; i <= n; i++){
            f[i][m].r = m;
            for(int j = m - 1; j >= 1; j--){
                f[i][j].r = (cb[i][j + 1] || cb[i][j])? j:f[i][j + 1].r;
            }
        }
        for(int j = 1; j <= m; j++){
            f[1][j].u = 1;
            for(int i = 2; i <= n; i++){
                f[i][j].u = (cb[i - 1][j] || cb[i][j])? i:f[i - 1][j].u;
            }
        }
        for(int j = 1; j <= m; j++){
            f[n][j].d = n;
            for(int i = n - 1; i >= 1; i--){
                f[i][j].d = (cb[i + 1][j] || cb[i][j])? i:f[i + 1][j].d;
            }
        }
        
        /*
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                //cerr << f[i][j].r << ' ';
            }
            //cerr << '\n';
        }
        //cerr << '\n';

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                //cerr << f[i][j].d << ' ';
            }
            //cerr << '\n';
        }
        //cerr << '\n';

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                //cerr << f[i][j].u << ' ';
            }
            //cerr << '\n';
        }
        //cerr << '\n'; 
        */

        ll ccnt = 0,fcnt = 0,tmpc = 0,tmpf = 0;
        for(int j = 1; j <= m; j++){
            tmpc = 0,tmpf = 0;
            for(int i = n; i >= 1; i--){
                //cerr << i << ' ' << j << ' ' << tmpc << ' ' << tmpf << ' ' << ccnt << ' ' << fcnt << '\n';
                if(cb[i][j] == 1){
                    //cerr << "A\n";
                    //cerr << "---------\n";
                    tmpc = tmpf = 0;
                    continue;
                }
                ll len = f[i][j].r - j, h = f[i][j].d - i;
                len %= MOD, h %= MOD;
                //cerr << len << ' ' << h << '\n';
                if(i + 1 <= n && f[i + 1][j].r != j){
                    tmpc -= (f[i + 1][j].r - j), tmpc %= MOD, tmpc += MOD, tmpc %= MOD;
                    tmpf -= (f[i + 1][j].r - j) * (f[i + 1][j].d - i - 1), tmpf %= MOD;
                    tmpf += MOD, tmpf %= MOD;
                    //cerr << "B:" << tmpc << ' ' << tmpf << '\n';
                }
                ccnt += (tmpc % MOD) * (len % MOD) % MOD, ccnt %= MOD;
                fcnt += (tmpf % MOD) * (len % MOD) % MOD, fcnt %= MOD;
                tmpc += len % MOD, tmpc % MOD;
                tmpf += (len % MOD) * (h % MOD) % MOD, tmpf %= MOD;
                //cerr << ccnt << ' ' << fcnt << ' ' << tmpc << ' ' << tmpf << '\n';
                if(i + 1 <= n && f[i + 1][j].r != j){
                    tmpc += (f[i + 1][j].r - j), tmpc %= MOD, tmpc += MOD, tmpc %= MOD;
                    tmpf += (f[i + 1][j].r - j) * (f[i + 1][j].d - i - 1), tmpf %= MOD;
                    tmpf += MOD, tmpf %= MOD;
                    //cerr << "B:" << tmpc << ' ' << tmpf << '\n';
                }
                //cerr << "----------\n";
            }
        }
        cout << ((ccnt % MOD) * (cc % MOD)) % MOD << ' ' << ((fcnt % MOD) * (cf % MOD)) % MOD << '\n';
    }
    return 0;
}