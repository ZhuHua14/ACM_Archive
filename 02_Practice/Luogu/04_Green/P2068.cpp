#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 5e5 + 5;
int lowbit(int x){
    return x & -x;
}

int n,a[MAXN],tree_a[MAXN],diff[MAXN],tree_diff[MAXN],w;

void init(){/*初始化*/
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

void point_add(int nowp,int x){/*单点修改*/
    while(nowp <= n){        
        tree_a[nowp] += x;
        nowp += lowbit(nowp);
    }
}

void range_add(int nowl,int nowr,int x){/*区间修改*/
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

int pre_sum(int nowp){/*前缀查询*/
    int ans = 0;
    while(nowp > 0){
        ans += tree_a[nowp];
        nowp -= lowbit(nowp);
    }
    return ans;
}

int sum(int nowl,int nowr){/*区间查询*/
    return pre_sum(nowr) - pre_sum(nowl - 1); 
}

int at(int nowp){/*单点查询*/
    int ans = 0;
    while(nowp > 0){
        ans += tree_diff[nowp];
        nowp -= lowbit(nowp);
    }
    return ans;
}

signed main(){
    cin >> n >> w;
    //init();
    char opt;
    int nowl,nowr,nowx;
    while(w--){
        cin >> opt;
        if(opt == 'x'){
            cin >> nowl >> nowr;
            point_add(nowl,nowr);
        }
        else{
            cin >> nowl >> nowr;
            cout << sum(nowl,nowr) << '\n';
        }
    }
    return 0;
}