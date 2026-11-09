#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e4 + 5;
int w,n,p[MAXN];
int main(){
    cin >> w >> n;
    for(int i = 1; i <= n; i++){
        cin >> p[i];
    }
    sort(p + 1,p + n + 1);
    int l = 1,r = n,ans = 0;
    while(l <= r){
        if(p[l] + p[r] <= w){
            l++;
        }
        r--;
        ans++;
    }
    cout << ans;
    return 0;
}