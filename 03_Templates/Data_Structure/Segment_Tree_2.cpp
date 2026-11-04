#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1e5 + 5;
const int MOD = 571373;

int lefts(int root){
    return root * 2;
}

int rights(int root){
    return root * 2 + 1;
}

int sizeofrange(int l,int r){
    return r - l + 1;
}

int tree[MAXN * 4],lazy1[MAXN * 4/*add*/],lazy2[MAXN * 4/*mul*/],a[MAXN];

void push_down(int nowp,int nowl,int nowr){
    int mid = (nowl + nowr) / 2;
  /*tree[lefts(root)]=(tree[lefts(root)]*lazy2[root]+lazy1[root]*(m-l+1))%MOD;
    tree[rights(root)]=(tree[rights(root)]*lazy2[root]+lazy1[root]*(r-m))%MOD;*/
    tree[lefts(nowp)] = (tree[lefts(nowp)] * lazy2[nowp]) % MOD;
    tree[lefts(nowp)] = (tree[lefts(nowp)] + (sizeofrange(nowl,mid) * lazy1[nowp])) % MOD;
    //if(sizeofrange(nowl,mid) > 1) {
        lazy2[lefts(nowp)] = (lazy2[lefts(nowp)] * lazy2[nowp]) % MOD; 
        lazy1[lefts(nowp)] = (lazy1[lefts(nowp)] * lazy2[nowp]) % MOD;   
        lazy1[lefts(nowp)] = (lazy1[lefts(nowp)] + lazy1[nowp]) % MOD;
    //}
    tree[rights(nowp)] = (tree[rights(nowp)] * lazy2[nowp]) % MOD;
    tree[rights(nowp)] = (tree[rights(nowp)] + (sizeofrange(mid + 1,nowr) * lazy1[nowp]) % MOD) % MOD;
    //if(sizeofrange(mid + 1,nowr) > 1) {
        lazy2[rights(nowp)] = (lazy2[rights(nowp)] * lazy2[nowp]) % MOD; 
        lazy1[rights(nowp)] = (lazy1[rights(nowp)] * lazy2[nowp]) % MOD;   
        lazy1[rights(nowp)] = (lazy1[rights(nowp)] + lazy1[nowp]) % MOD;
    //}
    lazy1[nowp] = 0;
    lazy2[nowp] = 1;
}

/*void push_down(int root, int l, int r){
    int m=(l+r)/2;
//根据我们规定的优先度，儿子的值=此刻儿子的值*爸爸的乘法lazytag+儿子的区间长度*爸爸的加法lazytag
    tree[lefts(root)]=(tree[lefts(root)]*lazy2[root]+lazy1[root]*(m-l+1))%MOD;
    tree[rights(root)]=(tree[rights(root)]*lazy2[root]+lazy1[root]*(r-m))%MOD;
//很好维护的lazytag
    lazy2[lefts(root)]=(lazy2[lefts(root)]*lazy2[root])%MOD;
    lazy2[rights(root)]=(lazy2[rights(root)]*lazy2[root])%MOD;
    lazy1[lefts(root)]=(lazy1[lefts(root)]*lazy2[root]+lazy1[root])%MOD;
    lazy1[rights(root)]=(lazy1[rights(root)]*lazy2[root]+lazy1[root])%MOD;
//把父节点的值初始化
    lazy2[root]=1;
    lazy1[root]=0;
    return ;
}*/

void push_up(int nowp){
    tree[nowp] = (tree[lefts(nowp)] + tree[rights(nowp)]) % MOD;
}

void build(int l,int r,int nowp){
    lazy1[nowp] = 0;
    lazy2[nowp] = 1;
    if(l == r){
        tree[nowp] = a[l] % MOD;
        return;
    }
    int mid = (l + r) / 2;
    build(l,mid,lefts(nowp));
    build(mid + 1,r,rights(nowp));
    push_up(nowp);
}

int range_sum(int l,int r,int nowl,int nowr,int nowp){
    if(l <= nowl && r >= nowr){
        return tree[nowp];
    }
    if(lazy1[nowp] != 0 || lazy2[nowp] != 1){
        push_down(nowp,nowl,nowr);
    }
    int mid = (nowl + nowr) / 2;
    int res = 0;
    if(l <= mid) res = (res + range_sum(l,r,nowl,mid,lefts(nowp))) % MOD;
    if(r > mid) res += (range_sum(l,r,mid + 1,nowr,rights(nowp))) % MOD;
    res %= MOD;
    push_up(nowp);
    return res;
}

void add(int l,int r,int dx,int nowl,int nowr,int nowp){
    if(l <= nowl && r >= nowr){
        tree[nowp] = (tree[nowp] + ((sizeofrange(nowl,nowr) * dx) % MOD)) % MOD;
        lazy1[nowp] = (lazy1[nowp] + dx) % MOD;
        return;
    }
    if(lazy1[nowp] != 0 || lazy2[nowp] != 1){
        push_down(nowp,nowl,nowr);
    }
    int mid = (nowl + nowr) / 2;
    if(l <= mid) add(l,r,dx,nowl,mid,lefts(nowp));
    if(r > mid) add(l,r,dx,mid + 1,nowr,rights(nowp));
    push_up(nowp);
}

void mul(int l,int r,int dx,int nowl,int nowr,int nowp){
    if(l <= nowl && r >= nowr){
        tree[nowp] = (tree[nowp] * dx) % MOD;
        lazy2[nowp] = (lazy2[nowp] * dx) % MOD;
        lazy1[nowp] = (lazy1[nowp] * dx) % MOD;
        return;
    }
    if(lazy1[nowp] != 0 || lazy2[nowp] != 1){
        push_down(nowp,nowl,nowr);
    }
    int mid = (nowl + nowr) / 2;
    if(l <= mid) mul(l,r,dx,nowl,mid,lefts(nowp));
    if(r > mid) mul(l,r,dx,mid + 1,nowr,rights(nowp));
    push_up(nowp);
}

int n,m,mod;

signed main(){
    //freopen("in.in","r",stdin);
    //freopen("out.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> mod;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    build(1,n,1);
    int op,nowl,nowr,dx;
    while(m--){
        cin >> op;
        if(op == 1){
            cin >> nowl >> nowr >> dx;
            mul(nowl,nowr,dx,1,n,1);
        }
        else if(op == 2){
            cin >> nowl >> nowr >> dx;
            add(nowl,nowr,dx,1,n,1);
        }
        else if(op == 3){
            cin >> nowl >> nowr;
            cout << range_sum(nowl,nowr,1,n,1) % MOD << endl;
        }
    }
    return 0;
}