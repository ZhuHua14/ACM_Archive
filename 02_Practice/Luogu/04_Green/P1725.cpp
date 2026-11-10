// P1725 琪露诺
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 2e5 + 5;

deque<pair<int,int> > dq;
int a[2 * MAXN],n,l,r,f[2 * MAXN];

void balence(int x,int p){
    while((!dq.empty()) && p - dq.front().second >= (r - l + 1)){
        dq.pop_front();
    }
    while((!dq.empty()) && dq.back().first <= x){
        dq.pop_back();
    }
}

void insert(int x,int p){
    balence(x,p);
    dq.push_back(make_pair(x,p));
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(f,-0x3f,sizeof(f));
    cin >> n >> l >> r;
    for(int i = 0; i <= n; i++){
        cin >> a[i];
    }
    f[0] = 0;
    int ans = -0x3f3f3f3f3f3f3f3f;
    insert(f[0],0);
    int cnt = 0;
    for(int i = l; i <= n + r; i++){
        f[i] = max(f[i],dq.front().first + a[i]);
        insert(f[++cnt],cnt);
		if(i > n) ans = max(ans,f[i]);
    }
    cout << ans;
}