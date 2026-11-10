// P1803 凌乱的yyy / 线段覆盖
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 6;
pair<int,int> f[MAXN];/*f = l,s = r*/
bool cmp(pair<int,int> x,pair<int,int> y){
    if(x.second == y.second){
        return x.first < y.first;
    }
    return x.second < y.second;
}
int n;
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> f[i].first >> f[i].second;
    }
    sort(f + 1,f + 1 + n,cmp);
    int ans = 1,left = f[1].first,right = f[1].second;
    for(int i = 1; i <= n; i++){
        if(f[i].first >= right){
            ans++;
            right = f[i].second;
        }
    }
    cout<<ans;
    return 0;
}