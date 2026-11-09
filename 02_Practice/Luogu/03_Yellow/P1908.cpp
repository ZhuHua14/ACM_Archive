#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 5e5 + 5;
int n,a[MAXN],temp[MAXN],tree[MAXN];

int lowbit(int x){
    return x & -x;
}

int pre_sum(int nowp){
    int ans = 0;
    while(nowp > 0){
        ans += tree[nowp];
        nowp -= lowbit(nowp);
    }
    return ans;
}

void add(int nowp,int x){
    while(nowp <= n){
        tree[nowp] += x;
        nowp += lowbit(nowp);
    }
}

void init(){
    sort(temp + 1,temp + 1 + n);
    int len = unique(temp + 1,temp + 1 + n) - temp;
    for(int i = 1; i <= n; i++){
        a[i] = lower_bound(temp + 1,temp + 1 + len,a[i]) - temp;
    }
}

signed main(){
    //freopen("in.txt","r",stdin);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        temp[i] = a[i];
    }
    init();
    int ans = 0;
    for(int i = n; i > 0; i--){
        ans += pre_sum(a[i] - 1);
        add(a[i],1);
    }
    cout << ans;
    return 0;
}