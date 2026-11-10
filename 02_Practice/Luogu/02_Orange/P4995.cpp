// P4995 跳跳！
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 305;
int n;
int h[MAXN];
signed main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> h[i];
    }
    sort(h + 1,h + n + 1,greater<int>());
    /*for(int i = 1; i <= n; i++){
        cout << h[i] << " ";
    }*/
    //cout << "\n";
    int l = 1,r = n,ans = 0,i = 0;
    while(l <= r){
        //cout << ans << ' ' << l << ' ' << r << ' ' << i <<'\n'; 
        if(i == 0){
            ans += (h[i] - h[l]) * (h[i] - h[l]);
            i = l;
        }
        else if(i == l){
            ans += (h[i] - h[r]) * (h[i] - h[r]);
            i = r;
            l++;
        }
        else if(i == r){
            ans += (h[i] - h[l]) * (h[i] - h[l]);
            i = l;
            r--;
        }
    }
    cout << ans;
    return 0;
}