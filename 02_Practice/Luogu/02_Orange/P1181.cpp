// P1181 数列分段 Section I
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
int n,m;
int a[MAXN];
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int ans = 1,nowsum = 0;
    for(int i = 1; i <= n; i++){
        if(nowsum + a[i] > m){
            ans++;
            nowsum = 0;
        }
        nowsum += a[i];
    }
    cout << ans;
    return 0;
}