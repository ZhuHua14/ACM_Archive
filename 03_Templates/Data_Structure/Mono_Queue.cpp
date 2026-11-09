#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN  = 1e6 + 5;

int ans1[MAXN],ans2[MAXN],sz;
deque<pair<int,int> > dq1,dq2;/*1 = max,2 = min*/

void balence(int x,int p){
    while((!dq1.empty()) && p - dq1.front().second >= sz){
        dq1.pop_front();
    }
    while((!dq1.empty()) && dq1.back().first < x){
        dq1.pop_back();
    }
    while((!dq2.empty()) && p - dq2.front().second >= sz){
        dq2.pop_front();
    }
    while((!dq2.empty()) && dq2.back().first > x){
        dq2.pop_back();
    }
}

void insert(int x,int p){
    balence(x,p);
    dq1.push_back(make_pair(x,p));
    dq2.push_back(make_pair(x,p));    
}

int n;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> sz;
    int nowin;
    for(int i = 1; i <= n; i++){
        cin >> nowin;
        insert(nowin,i);
        ans1[i] = dq1.front().first;
        ans2[i] = dq2.front().first;
    }
    for(int i = sz; i <= n; i++){
        cout << ans2[i] << ' ';
    }
    cout << endl;
    for(int i = sz; i <= n; i++){
        cout << ans1[i] << ' ';
    }
    return 0;
}