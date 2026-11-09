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
    for(int i = 1; i <= n; i++){
        tree_diff[i] = a[i] - a[i - lowbit(i)];
    }
}

void point_add(int nowp,int x){
    while(nowp <= n){        
        tree_a[nowp] += x;
        nowp += lowbit(nowp);
    }
}

void range_add(int nowl,int nowr,int x){
    while(nowl <= n){
        tree_diff[nowl] += x;
        nowl += lowbit(nowl);
    }
    nowr = nowr + 1;
    while(nowr <= n){
        tree_diff[nowr] -= x;
        nowr += lowbit(nowr);
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

int at(int nowp){
    int ans = 0;
    while(nowp > 0){
        ans += tree_diff[nowp];
        nowp -= lowbit(nowp);
    }
    return ans;
}
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    init();
    int opt,nowl,nowr,nowx;
    while(m--){
        cin >> opt;
        if(opt == 1){
            cin >> nowl >> nowr >> nowx;
            range_add(nowl,nowr,nowx);
        }
        else{
            cin >> nowx;
            cout << at(nowx) << '\n';
        }
    }
    return 0;
}