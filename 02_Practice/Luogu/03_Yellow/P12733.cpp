#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e6 + 5;

int n,q,d[MAXN];
ll dpres[MAXN],tmin[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> d[i];
    }
    sort(d + 1,d + 1 + n);
    for(int i = 1; i <= n; i++){
        dpres[i] = dpres[i - 1] + d[i];
        tmin[i] = tmin[i - 1] + dpres[i];
    }
    ll t;
    int pos;
    while(q--){
        cin >> t;
        pos = lower_bound(tmin + 1,tmin + 1 + n,t) - tmin;
        if(t == tmin[pos]) cout << pos;
        else cout << pos - 1;
        cout << '\n';
    }
    return 0;
}