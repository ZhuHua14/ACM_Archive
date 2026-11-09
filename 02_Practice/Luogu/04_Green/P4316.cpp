#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 1e5 + 5;
struct Edge{
	ll from,to,val;

	Edge(ll _from,ll _to,ll _val): from(_from),to(_to),val(_val) {}

	Edge() {}
};

vector<Edge> edge[MAXN];

ll n,m,incnt[MAXN],outcnt[MAXN];

double p[MAXN],e[MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    p[1] = 1.0; 
    cin >> n >> m;
    Edge nowin;
    for(int i = 1; i <= m; i++){
    	cin >> nowin.from >> nowin.to >> nowin.val;
    	edge[nowin.from].push_back(nowin);
    	incnt[nowin.to]++;
    	outcnt[nowin.from]++;
    }
    queue<ll> q;
    q.push(1);
    while(!q.empty()){
    	ll nowtop = q.front();
    	q.pop();
    	for(int i = 0; i < edge[nowtop].size(); i++){
    		incnt[edge[nowtop][i].to]--;
    		e[edge[nowtop][i].to] += (e[nowtop] + p[nowtop] * (double)edge[nowtop][i].val) * (1.0 / (double)outcnt[nowtop]);
    		p[edge[nowtop][i].to] += (p[nowtop]) * (1.0 / (double)outcnt[nowtop]);
    		if(incnt[edge[nowtop][i].to] == 0){
    			q.push(edge[nowtop][i].to);
    		}
    	}
    }
    printf("%.2f",e[n]);
    return 0;
}