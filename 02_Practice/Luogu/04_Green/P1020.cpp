// P1020 [NOIP 1999 提高组] 导弹拦截
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const int MAXH = 5e4 + 5;
int n,a[MAXN],f[MAXN],tree[MAXH * 4];
/*
int lowbit(int x){
    return x & -x;
}

int find(int nowp){
    int res = -1e9;
    for(int i = nowp; i > 0; i -= lowbit(i)){
        res = max(res,tree[i]);
    }
    return res;
}

void change(int nowp,int x){
    tree[nowp] = x;
    for(int i = nowp; i <= n; i += lowbit(i)){
        tree[nowp] = max(x,tree[nowp]);
    }

}
*/

int ls(int root){
    return root * 2;
}

int rs(int root){
    return root * 2 + 1;
}

void push_up(int root){
    tree[root] = max(tree[ls(root)],tree[rs(root)]);
}

void build(int nowp,int l,int r){
    if(l == r){
        tree[nowp] = 0;
        return;
    }
    int mid = (l + r) / 2;
    build(ls(nowp),l,mid);
    build(rs(nowp),mid + 1,r);
    push_up(nowp);
}

void change(int pos,int dx,int l,int r,int nowp){
    if(l > pos || r < pos){
        return;
    }
    if(l == r){
        tree[nowp] = dx;
        //if(l == 71) cout << tree[nowp];
        return;
    }
    int mid = (l + r) / 2;
    /*if(pos <= mid)*/ change(pos,dx,l,mid,ls(nowp));
    /*if(pos > mid)*/ change(pos,dx,mid + 1,r,rs(nowp));
    push_up(nowp);
}

int find(int l,int r,int nowl,int nowr,int nowp){
    //cout << nowl << ' ' << nowr << ' ' << nowp << ' ' << endl;
    if(l > nowr || r < nowl){
        return 0;
    }
    if(l <= nowl && nowr <= r){
        return tree[nowp];
    }
    int mid = (nowl + nowr) / 2;
    int res = 0;
    if(l <= mid) res = max(res,find(l,r,nowl,mid,ls(nowp)));
    if(r > mid) res = max(res,find(l,r,mid + 1,nowr,rs(nowp)));
    //cout << res << '|';
    push_up(nowp);
    return res;
}

//void change(int pos,int dx,int l,int r,int nowp)
/*void build(int cur,int lt,int rt){
	int mid=lt+rt>>1;
	if(lt==rt){
		tree[cur]=1;
		return;
	}
	build(cur*2,lt,mid);
	build(cur*2+1,mid+1,rt);
	push_up(cur);
}
void change(int qx,int val,int lt,int rt,int cur){
	if(lt>qx||rt<qx)
		return;
	if(lt==rt){
		tree[cur]=val;
		return;
	}
	int mid=lt+rt>>1;
	change(qx,val,lt,mid,ls(cur));
	change(qx,val,mid+1,rt,rs(cur));
	push_up(cur);
	return;
}*/
//int find(int l,int r,int nowl,int nowr,int nowp)
/*int find(int qx,int qy,int lt,int rt,int cur){
	if(lt>qy||rt<qx)
		return -1e18;
	if(lt>=qx&&rt<=qy)
		return tree[cur];
	int mid=lt+rt>>1;
	return max(find(qx,qy,lt,mid,ls(cur)),find(qx,qy,mid+1,rt,rs(cur)));
}*/

int main(){
    int n = 1;
    int lim = 0;
    while(cin >> a[n]){
        lim = max(lim,a[n]);
        n++;
    }
    n--;
    //cout << lim << endl;
    int maxf;
    //cout << "YES" << endl;
    for(int i = 1; i <= n; i++){
        //cout << i << ':';
        maxf = 0;
        maxf = find(a[i],lim,1,lim,1);
        //cout << maxf << ' ';
        f[i] = maxf + 1;
        change(a[i],f[i],1,lim,1);
        //cout << tree[213];
        //cout << endl;
    }
    maxf = 0;
    //cout << tree[213] << endl;
    /*cout << endl;
    for(int i = 1; i <= n; i++) cout << f[i] << ' ';
    cout << endl;*/
    for(int i = 1; i <= n; i++) maxf = max(maxf,f[i]);
    cout << maxf << endl;
    build(1,1,lim);
    for(int i = 1; i <= n; i++){
        //cout << i << ':';
        maxf = 0;
        maxf = find(1,a[i] - 1,1,lim,1);
        //cout << maxf << ' ';
        f[i] = maxf + 1;
        change(a[i],f[i],1,lim,1);
        //cout << tree[213];
        //cout << endl;
    }
    maxf = 0;
    for(int i = 1; i <= n; i++) maxf = max(maxf,f[i]);
    cout << maxf << endl;
    return 0;
}