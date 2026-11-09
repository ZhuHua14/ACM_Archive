#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
typedef struct Node{
    long long front,back;
}Node;
Node node1[MAXN],node0[MAXN];
Node Create(long long f,long long t){
    Node create;
    create.back = t;
    create.front = f;
    return create;
}
int fa[MAXN],n,t,cnttemp = 0,cnt0 = 0,cnt1 = 0;

int find(int x){
    return (fa[x] == x)? x : (fa[x] = find(fa[x]));
}

void marge(int f,int s){
    int ff = find(f),fs = find(s);
    if(ff == fs){
        return;
    }
    else{
        fa[fs] = ff;
        return;
    }
}

long long temp[2 * MAXN];
void init(){
    for(int i = 1; i < MAXN; i++){
        fa[i] = i;
    }
    sort(temp + 1,temp + cnttemp + 1);
    /*cout << "\ntemp(before):\n";
    for(int i = 1; i <= cnttemp; i++){
        cout << temp[i] << ' ';
    }*/
    int nowlen = unique(temp + 1,temp + 1 + cnttemp) - temp - 1;
    /*cout << "\ntemp(after):\n";
    for(int i = 1; i <= nowlen; i++){
        cout << temp[i] << ' ';
    }*/
    for(int i = 1; i <= cnt0; i++){
        node0[i].front = lower_bound(temp + 1,temp + nowlen + 1,node0[i].front) - temp;
        node0[i].back = lower_bound(temp + 1,temp + nowlen + 1,node0[i].back) - temp;
    }
    for(int i = 1; i <= cnt1; i++){
        node1[i].front = lower_bound(temp + 1,temp + nowlen + 1,node1[i].front) - temp;
        node1[i].back = lower_bound(temp + 1,temp + nowlen + 1,node1[i].back) - temp;
    }
    /*cout << "\nnode0:\n";
    for(int i = 1; i <= cnt0; i++){
        cout << node0[i].front << ' ' << node0[i].back << "|";
    }
    cout << "\nnode1:\n";
    for(int i = 1; i <= cnt1; i++){
        cout << node1[i].front << ' ' << node1[i].back << "|";
    }
    cout << '\n';*/
}

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        cnt0 = 0;
        cnt1 = 0;
        cnttemp = 0;
        int opt = 0,nowf,nowt;
        for(int i = 1; i <= n; i++){
            cin >> nowf >> nowt >> opt;
            if(opt == 0){
                node0[++cnt0] = Create(nowf,nowt);
            }
            else if(opt == 1){
                node1[++cnt1] = Create(nowf,nowt);
            }
            temp[++cnttemp] = nowf;
            temp[++cnttemp] = nowt;
        }
        init();
        for(int i = 1; i <= cnt1; i++){
            marge(node1[i].front,node1[i].back);
        }
        bool flag = 0;
        for(int i = 1; i <= cnt0; i++){
            if(find(node0[i].front) == find(node0[i].back)){
                flag = 1;
                break;
            }
        }
        if(flag) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}