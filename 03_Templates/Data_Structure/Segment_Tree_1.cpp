#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;

ll n,m,tree[MAXN * 4],lazy[MAXN * 4],a[MAXN];

int ls(int p){
    return p * 2;
}

int rs(int p){
    return p * 2 + 1;
}

int len(int l,int r){
    return r - l + 1;
}

void push_up(int p){
    tree[p] = tree[ls(p)] + tree[rs(p)];
}

void push_down(int l,int r,int p){
    int nls = ls(p),nrs = rs(p),mid = l + ((r - l) / 2);
    tree[nls] += len(l,mid) * lazy[p];
    tree[nrs] += len(mid + 1,r) * lazy[p];    
    lazy[nls] += lazy[p];
    lazy[nrs] += lazy[p];
    lazy[p] = 0;  
}

bool incl(int l,int r,int l1,int r1){
    return l <= l1 && r >= r1;
}/*[l1,r1] 是否包含于 [l,r]*/

void build(int l,int r,int id){
    lazy[id] = 0;
    if(l == r){
        tree[id] = a[l];
        return;
    }
    int mid = l + ((r - l) / 2);
    build(l,mid,ls(id));
    build(mid + 1,r,rs(id));
    push_up(id);
}

ll find_sum(int l,int r,int l1,int r1,int id){
    if(incl(l,r,l1,r1)){
        return tree[id];
    }
    int mid = l1 + ((r1 - l1) / 2);
    ll sum = 0;
    push_down(l1,r1,id);
    if(l <= mid) sum += find_sum(l,r,l1,mid,ls(id));
    if(r > mid) sum += find_sum(l,r,mid + 1,r1,rs(id));
    push_up(id);
    return sum;
}

void add(int l,int r,ll x,int l1,int r1,int id){
    if(incl(l,r,l1,r1)){
        tree[id] += len(l1,r1) * x;
        lazy[id] += x;
        return;
    }
    int mid = l1 + ((r1 - l1) / 2);
    push_down(l1,r1,id);
    if(l <= mid) add(l,r,x,l1,mid,ls(id));
    if(r > mid) add(l,r,x,mid + 1,r1,rs(id));
    push_up(id);   
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n ; i++) cin >> a[i];
    build(1,n,1);
    int op,x,y;
    ll k;
    while(m--){
        cin >> op;
        if(op == 1){
            cin >> x >> y >> k;
            add(x,y,k,1,n,1);
        }
        else if(op == 2){
            cin >> x >> y;
            cout << find_sum(x,y,1,n,1) << '\n';
        }
    }
   return 0;
}