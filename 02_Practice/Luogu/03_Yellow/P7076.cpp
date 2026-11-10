// P7076 [CSP-S 2020] 动物园
#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int MAXN = 1e6 + 5;
struct Node{
    int p,q;
};

ull n,m,c,k,q[MAXN];
ull a[MAXN];
Node node[MAXN];
bool flag[MAXN],cnt;
ull point[MAXN];

int popcount(ull x){
    int ans = 0;
    while(x != 0){
        if(x & 1){
            ans++;
        }
        x >>= 1;
    }
    return ans;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> c >> k;
    ull totle = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        totle |= a[i];
    }
    sort(a + 1,a + 1 + n);
    n = unique(a + 1,a + 1 + n) - a - 1;

    for(int i = 1; i <= m; i++){
        cin >> node[i].p >> node[i].q;
        q[i] = node[i].q; 
    }

    sort(q + 1,q + 1 + m);
    int cnt = unique(q + 1,q + 1 + m) - q - 1;
    //cerr << '\n';
    for(int i = 1; i <= m; i++){
        //cerr << node[i].q << ' ';
        node[i].q = lower_bound(q + 1,q + 1 + cnt,node[i].q) - q;
        //cerr << node[i].q << '\n';
    }
    //cerr << endl;
    for(int i = 1; i <= m; i++){
        point[node[i].q] |= (1ull << node[i].p);
    }
    //cerr << endl;
    for(int i = 1; i <= m; i++){
        if((totle >> node[i].p) & 1){
            flag[node[i].q] = 1;
        }
    }

    ull diff = 0;
    for(int i = 1; i <= cnt; i++){
        if(flag[i] == 0){
            diff |= point[i];
        }
    }
    /*加这一位有影响当且仅当这一位被其他的q占了*/
    /*只要包含这些位，就会对答案有影响*/
    if(k == 64 && n == 0){
        cout << "18446744073709551616";
        return 0;
    }
    else if(k - popcount(diff) == 64){
        cout << ull(-n);
        return 0;
    }
    //cerr << k - popcount(diff);
    ull ans = 1ull << (k - popcount(diff));
    ans -= n;
    cout << ans;
    return 0;
}
