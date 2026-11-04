#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 3e6 + 5;
int ans[MAXN];
stack<pair<int,int> > s;/*first = x,second = p*/

void balence(int x,int p){
    while((!s.empty()) && (s.top().first < x)){
        ans[s.top().second] = p;
        s.pop();
    }
}

void insert(int x,int p){
    balence(x,p);
    s.push(make_pair(x,p));
}

int n;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int nowin;
    for(int i = 1; i <= n; i++){
        cin >> nowin;
        insert(nowin,i);
    }
    for(int i = 1; i <= n; i++){
        cout << ans[i] << ' ';
    }
    return 0;
}