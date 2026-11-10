// P5761 [NOI1997] 最佳游览
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e4 + 5;
int way[MAXN],sum[MAXN];
int n,m;
int main(){
    cin >> n >> m;
    int nowin;
    memset(way,-0x3f,sizeof(way));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j < m; j++){
            cin >> nowin;
            way[j] = max(nowin,way[j]);
        }
    }
    for(int i = 1; i <= m; i++){
        sum[i] = sum[i - 1] + way[i];
    }
    int frontmin = sum[1],ans = -0x3f3f3f3f;
    for(int i = 1; i <= m; i++){
        frontmin = min(frontmin,sum[i - 1]);
        ans = max(ans,sum[i] - frontmin);
    }
    cout << ans;
    return 0;
}