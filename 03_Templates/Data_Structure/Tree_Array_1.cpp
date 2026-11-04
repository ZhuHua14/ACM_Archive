#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
int lowbit(int x){
    return x & -x;
}

int n,a[MAXN],tree_a[MAXN],diff[MAXN],tree_diff[MAXN],m;

void init(){
    int nowf;
    for(int i = 1; i <= n; i++){
        tree_a[i] += a[i];
        nowf = i + lowbit(i);
        if(nowf <= n) tree_a[nowf] += tree_a[i];
    }
}

void point_add(int nowp,int x){
    while(nowp <= n){        
        tree_a[nowp] += x;
        nowp += lowbit(nowp);
    }
}

int pre_sum(int nowp){
    int ans = 0;
    while(nowp > 0){
        ans += tree_a[nowp];
        nowp -= lowbit(nowp);
    }
    return ans;
}

int sum(int nowl,int nowr){
    return pre_sum(nowr) - pre_sum(nowl - 1); 
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    init();
    int opt,nowx,nowk;
    while(m--){
        cin >> opt >> nowx >> nowk;
        if(opt == 1) point_add(nowx,nowk);
        else cout << sum(nowx,nowk) << '\n';
    }
    return 0;
}