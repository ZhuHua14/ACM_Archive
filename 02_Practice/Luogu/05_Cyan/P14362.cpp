//Author:ZhuHua14(luogu)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2e4 + 5;
const int MAXM = 2e6 + 5;
const int MAXK = 15;

struct Edge{
	int u,v,w;

	void print(){
		//cerr << u << ' ' << v << ' ' << w << '\n';
	}
};
Edge edge[MAXM],edge2[MAXM];
int ecnt;
bool cmp(Edge x,Edge y){
	return x.w < y.w;
}

struct Node{
	int pay1,pay[MAXN];
};
Node node[MAXK];

int n,m,k;
ll ans = 5e18;
int fa[MAXN];

int find(int x){
	return (fa[x] == x) ? x : (fa[x] = find(fa[x]));
}

bool merge(int a,int b){
	int faa = find(a),fab = find(b);
	if(faa != fab){
		fa[faa] = fab;
		return 1;
	}
	else return 0;
}

void init(){
    for(int i = 1; i <= n + 2 * k; i++){
        fa[i] = i;
    }
}

void solve1(){
	sort(edge + 1,edge + 1 + m,cmp);
    ll na = 0;
    int cnt = 0;
    init();
	for(int i = 1; i <= m; i++){
		if(merge(edge[i].u,edge[i].v)){
			na += edge[i].w;
			edge2[++ecnt] = edge[i];
            cnt++;
		}
		if(cnt == n - 1) break;
	}
    ans = min(ans,na);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
    cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		cin >> edge[i].u >> edge[i].v >> edge[i].w;
	}
	for(int i = 1; i <= k; i++){
		cin >> node[i].pay1;
		for(int j = 1; j <= n; j++){
			cin >> node[i].pay[j];
		}
	}
    
    solve1();
    
    for(int i = 1; i <= k; i++){
        for(int j = 1; j <= n; j++){
            edge2[++ecnt] = {n + i,j,node[i].pay[j]};
        }
    }

    sort(edge2 + 1,edge2 + 1 + ecnt,cmp);
    int nst[MAXK],kcnt = 0,p = 0;
    ll na = 0;
    for(int i = 1; i <= (1 << k) - 1; i++){
        int tmp = i;
        kcnt = 0,p = 0,na = 0;

        while(tmp){//处理子集
            p++;
            if(tmp & 1){
                nst[++kcnt] = p;
				na += node[p].pay1;
            }
            tmp >>= 1;
        }

		for(int i = 1; i <= kcnt; i++){
			////cerr << nst[i] << '\n';
		}

		init();

		int ccnt = 0;
		bool flag = 0;
		for(int i = 1; i <= ecnt; i++){
			flag = 0;
			if(edge2[i].u > n){
				////cerr << edge2[i].u << '\n';
				for(int j = 1; j <= kcnt; j++){
					//cerr << nst[j] << ' ';
					if(nst[j] + n == edge2[i].u){
						flag = 1;
						break;
					}
				}
			}
			//cerr << '\n';
			if(edge2[i].u > n && !flag) continue;
			if(merge(edge2[i].u,edge2[i].v)){
				edge2[i].print();
				na += edge2[i].w;
            	ccnt++;
			}
			if(ccnt == n + kcnt - 1) break;

		}
		ans = min(ans,na);
		//cerr << '\n';
    }
	cout << ans << '\n';
	return 0;
}

