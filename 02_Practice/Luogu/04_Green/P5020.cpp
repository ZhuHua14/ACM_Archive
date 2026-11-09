#include<bits/stdc++.h>
using namespace std;
const int MAXN = 105;
const int MAXA = 2.5e4 + 5;
int t,n,a[MAXN],f[MAXA];

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        sort(a + 1,a + n + 1);
        int ans = 0;
        for(int nowp = 1; nowp <= n; nowp++){
            memset(f,-0x3f,sizeof(f));
            f[0] = 0;
            for(int i = 1; i <= nowp; i++){
                for(int j = 1; j <= a[nowp]; j++){
                    if(j >= a[i]){
                        f[j] = max(f[j],f[j - a[i]] + 1);    
                    }
                }
            }
            if(f[a[nowp]] == 1) ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}