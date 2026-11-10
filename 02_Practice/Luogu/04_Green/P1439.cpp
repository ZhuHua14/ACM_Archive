// P1439 两个排列的最长公共子序列
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 2e5 + 5;
ll pos[MAXN],b[MAXN],pos_b[MAXN],f[MAXN],tree[MAXN],n;
ll lowbit(ll x){
    return x & (-x);
}

void change(ll x,ll p){
    tree[p] = max(tree[p],x);
    for(int i = p; i <= n; i += lowbit(i)){
        tree[i] = max(tree[i],x);
    }
}

ll find(ll p){
    ll ans = -1;
    for(int i = p; i > 0; i -= lowbit(i)){
        ans = max(ans,tree[i]);
    }
    return ans;
}

int main(){
    //freopen("in.in","r",stdin);
    //freopen("error.err","w",stderr);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ll nowin;
    for(int i = 1; i <= n; i++){
        cin >> nowin;
        pos[nowin] = i;/*nowin对应a的位置*/
    }
    for(int i = 1; i <= n; i++){
        cin >> b[i];
        pos_b[i] = pos[b[i]]/*b[i]在a中的位置*/;
    }
    /*for(int i = 1; i <= n; i++) cout << pos_b[i] << ' ';
    cout << endl;*/
    ll finalans = -1;
    f[1] = 1;
    change(f[1],pos_b[1]);
    for(int i = 2; i <= n; i++){
        int maxf = find(pos_b[i] - 1);
        f[i] = maxf + 1;
        change(f[i],pos_b[i]);
    }
    for(int i = 1; i <= n; i++) finalans = max(finalans,f[i]);
    //for(int i = 1; i <= n; i++) cerr << f[i] << ' ';
    cout << finalans;
    return 0;
}