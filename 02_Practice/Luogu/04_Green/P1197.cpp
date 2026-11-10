// P1197 [JSOI2008] 星球大战
#include<bits/stdc++.h>
using namespace std;
const int MAXM = 2e5 + 5;
const int MAXN = 2 * MAXM;
int n,tempn,m,k,nowans;
vector<int> v[MAXN];

int fa[MAXN],kkill[MAXN];
bool iskill[MAXN];
int ans[MAXN];

void init(){
    for(int i = 0; i <= n; i++){
        fa[i] = i;
    }
}

int find(int x){
    return (fa[x] == x)? x : (fa[x] = find(fa[x]));
}

void marge(int f,int s){
    int ff = find(f),fs = find(s);
    if(ff == fs) return;
    else{
        nowans--;
        fa[fs] = ff; 
    }
}

int main(){
    cin >> n >> m;
    tempn = n;
    init();
    int nowfrom,nowto;
    for(int i = 1; i <= m; i++){
        cin >> nowfrom >> nowto;
        v[nowfrom].push_back(nowto);
        v[nowto].push_back(nowfrom);
    }
    cin >> k;
    for(int i = k; i >= 1; i--){
        cin >> kkill[i];
        iskill[kkill[i]] = 1;  
    }
    nowans = n - k;
    for(int i = 0; i < n; i++){
        if(iskill[i] == 0){
            for(int j = 0; j < v[i].size(); j++){
                if(iskill[v[i][j]] == 0){
                    marge(i,v[i][j]);
                }
            }
        }
    }
    int ans[MAXN];
    ans[0] = nowans;
    for(int i = 1; i <= k; i++){
        nowans++;
        iskill[kkill[i]] = 0;
        for(int j = 0; j < v[kkill[i]].size(); j++){
            if(iskill[v[kkill[i]][j]] == 0){
                marge(kkill[i],v[kkill[i]][j]);
            }
        }
        ans[i] = nowans;
    }
    for(int i = k; i >= 0; i--){
        cout << ans[i] << '\n';
    }
    return 0;
}