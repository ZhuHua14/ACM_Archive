// P5911 [POI 2004] PRZ
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 16;
struct Node{
    ll w,t;
    Node(ll _w,ll _t): w(_w),t(_t) {}
    Node(){}
};

Node node[MAXN];
ll n,w,f[1 << MAXN],lb[1 << MAXN],cw[1 << MAXN],ct[1 << MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> w >> n;
    for(int i = 1; i <= n; i++){
        cin >> node[i].t >> node[i].w;
    }
    memset(f,0x3f,sizeof(f));
    f[0] = 0;
    for(int i = 0; i < (1 << n); i++){
    	for(int j = 1;j <= n; j++){
    		if(i & (1 << (j - 1))){
    			ct[i] = max(ct[i],node[j].t);
    			cw[i] += node[j].w;
			}
		}
	}
    for(int u = 0; u < (1 << n); u++){
        if(w >= cw[u]) f[u] = ct[u];
        for(int v = u; v; v = (v - 1) & u){
            if(w >= cw[u ^ v]) f[u] = min(f[u],f[v] + ct[u ^ v]);
        }
    }
    cout << f[(1 << n) - 1] << endl;
    return 0;
}