// P1115 最大子段和
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
int a[MAXN],sum[MAXN];
int n;
int main(){
    //freopen("in.txt","r",stdin);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        sum[i] = sum[i - 1] + a[i];
    }
    int frontmin = 0x3f3f3f3f,ans = -0x3f3f3f3f;
    for(int i = 1; i <= n; i++){
        frontmin = min(frontmin,sum[i - 1]);
        ans = max(ans,sum[i] - frontmin);
    }
    cout << ans;
    return 0;
}