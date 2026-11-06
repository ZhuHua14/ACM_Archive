#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;

int n,d[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> d[i];
    }
    int ans = d[1];
    for(int i = 2; i <= n; i++){
        if(d[i - 1] < d[i]) ans += d[i] - d[i - 1];
    }
    cout << ans;
    return 0;
}