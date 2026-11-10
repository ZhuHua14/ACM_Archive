// P1714 切蛋糕
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 5e5 + 5;
const int MAXLOG = 20;
int n,m,a[MAXN],presum[MAXN],st[MAXN][MAXLOG],lb[MAXN];

void getLog(){
    lb[1] = 0;
    lb[2] = 1;
    for(int i = 3; i <= MAXN; i++){
        lb[i] = lb[i / 2] + 1;
    }
}

void init(){
    getLog();
    for(int j = 1; j <= MAXLOG; j++){
        for(int i = 1; i + (1 << j) - 1 <= n; i++){
            st[i][j] = min(st[i][j - 1],st[i + (1 << (j - 1))/*i + pow(2,j - 1)*/][j - 1]);
        }
    }
}

int find_min(int l,int r){
    int id = lb[r - l + 1];
    return min(st[l][id],st[r - (1 << id) + 1][id]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    presum[0] = 0;
    int ans = -1e9;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        ans = max(ans,a[i]);
        presum[i] = presum[i - 1] + a[i];
        //cerr << presum[i] << ' ';
        st[i][0] = presum[i];
    }
    //cerr << endl;
    init();
    for(int i = 1; i <= n; i++){
        int l = max(0,i - m);
        int premin = find_min(l,i - 1);
        ans = max(ans,presum[i] - premin);
        //cerr << l << ' ' << i << ' ' << find_min(l,i) << ' ' << ans << endl;
    }
    cout << ans;
    return 0;
}