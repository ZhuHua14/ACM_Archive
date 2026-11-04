#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e4 + 5;
int fa[MAXN],dist[MAXN],soncnt[MAXN];
void init(){
    for(int i = 0; i < MAXN; i++){
        fa[i] = i;
        dist[i] = 0;
        soncnt[i] = 1;
    }
}

int find(int x){
    if(fa[x] == x){
        return x;
    }
    else{
        int nowfa = find(fa[x]);
        dist[x] += dist[fa[x]];
        return fa[x] = nowfa;
    }
}

void marge(int f,int s){
    int ff = find(f),fs = find(s);
    if(ff == fs) return;
    else{
        dist[fs] += soncnt[ff];
        fa[fs] = ff;
        soncnt[ff] += soncnt[fs];
        soncnt[fs] = 0;
    }
}

int t;
int main(){
    ios::sync_with_stdio(false);
    cin >> t;
    init();
    char opt;
    int nowf,nowt;
    for(int i = 1; i <= t; i++){
        cin >> opt >> nowf >> nowt;
        if(opt == 'M'){
            marge(nowt,nowf);
        }
        else if(opt == 'C'){
            if(find(nowf) != find(nowt)) cout << -1 << '\n';
            else cout << abs(dist[nowf] - dist[nowt]) - 1<< '\n';
        }
    }
    return 0;
}