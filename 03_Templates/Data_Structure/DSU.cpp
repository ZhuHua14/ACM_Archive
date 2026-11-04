#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
int fa[MAXN];
void init(){
    for(int i = 0; i < MAXN; i++){
        fa[i] = i;
    }
}

int find(int x){
    return x == fa[x]? x : (fa[x] = find(fa[x]));
}

bool marge(int f,int s){
    int faf = find(f),fas = find(s);
    if(faf == fas) return 0;
    else{
        fa[fas] = faf;
        return 1;
    }
}

int n,m;
int nowf,nows;
int main(){
    init();
    cin >> n >> m;
    int opt,nowf,nows;
    for(int i = 1; i <= m; i++){
        cin >> opt >> nowf >> nows;
        if(opt == 1) marge(nowf,nows);
        else cout << ((find(nowf) == find(nows))? 'Y':'N') << '\n';
    }
    return 0;
}