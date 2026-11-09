#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 5e5 + 5;

int node[2][MAXN];
ll m,n,cnt[MAXN],ncnt = 1;
int isend[MAXN];
int nowin[MAXN];

void insert(int a[],int len){
    ll nowp = 1;
    for(int i = 1; i <= len; i++){
        cnt[nowp]++;
        if(node[a[i]][nowp] == 0){
            ncnt++;
            node[a[i]][nowp] = ncnt;
        }
        nowp = node[a[i]][nowp];
    }
    cnt[nowp]++;
    isend[nowp]++;
}

ll getans(int a[],int len){
    ll nowp = 1,ans = 0;
    for(int i = 1; i <= len; i++){
        ans += isend[nowp];
        nowp = node[a[i]][nowp];
    }
    ans += cnt[nowp];
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n;
    ll len;
    for(int i = 1; i <= m; i++){
        cin >> len;
        for(int j = 1; j <= len; j++){
            cin >> nowin[j];
        }
        insert(nowin,len);
    }
    // for(int i = 1; i <= ncnt; i++){
    //     cout << i << ' ' << node[0][i] << ' ' << node[1][i] << endl;
    // }
    // for(int i = 1; i <= ncnt; i++){
    //     cout << i << ' ' << isend[i] << ' ' << cnt[i] << endl;
    // }
    for(int i = 1; i <= n; i++){
        cin >> len;
        for(int j = 1; j <= len; j++){
            cin >> nowin[j];
        }
        cout << getans(nowin,len) << '\n';
    }
    return 0;
}