// P2580 于是他错误的点名开始了
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 5e5 + 5;

int node[26][MAXN],ncnt = 1;
ll n,m;
bool isend[MAXN];
map<string,bool> isread;

void insert(string s){
    ll len = s.size() - 1,nowp = 1;
    for(int i = 0; i <= len; i++){
        if(node[s[i] - 'a'][nowp] == 0){
            ncnt++;
            node[s[i] - 'a'][nowp] = ncnt;
        }
        nowp = node[s[i] - 'a'][nowp];
    }
    isend[nowp] = 1;
}

int find(string s){
    if(isread[s] == 1) return 2;
    ll len = s.size() - 1,nowp = 1;
    for(int i = 0; i <= len; i++){
        if(node[s[i] - 'a'][nowp] == 0) return 0;
        nowp = node[s[i] - 'a'][nowp];
    }
    if(isend[nowp] == 1){
        isread[s] = 1;
        return 1;
    }
    else return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    string nowin;
    for(int i = 1; i <= n; i++){
        cin >> nowin;
        insert(nowin);
    }
    cin >> m;
    for(int i = 1; i <= m; i++){
        cin >> nowin;
        int op = find(nowin);
        if(op == 0) cout << "WRONG" << '\n';
        else if(op == 1) cout << "OK" << '\n';
        else cout << "REPEAT" << '\n';
    }
    return 0;
}