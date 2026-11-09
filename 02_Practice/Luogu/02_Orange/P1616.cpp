#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXM = 1e4 + 5;
const int MAXT = 1e7 + 5;

struct Med{
    int val,time;
};
Med med[MAXM];

int t,m,f[MAXT];

signed main(){
    cin >> t >> m;
    for(int i = 1; i <= m; i++){
        cin >> med[i].time >> med[i].val;
    }
    for(int i = 1; i <= m; i++){
        for(int j = med[i].time; j <= t; j++){
            f[j] = max(f[j],f[j - med[i].time] + med[i].val);
        }
    }
    cout << f[t];
    return 0;
}