#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 15;
const double INF = DBL_MAX;
//f[i][pos] -> 走过i表示的点，且停在pos时的最短距离;
//f[i][pos] = min(f[i - (1 << (pos - 1))][pos'] + dist(pos',pos));
//其中dist(i,j)为下标为i，j的点之间的距离;
struct Node{
    double x,y;
    Node(double _x,double _y): x(_x),y(_y) {}
    Node() {}
};
Node node[MAXN + 5];
double dist(Node a,Node b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double f[MAXN + 5][(1 << MAXN) + 1];
ll n;

void init(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j < (1 << n); j++){
            f[i][j] = INF;
        }
    }
    for(int i = 1; i <= n; i++){
        f[i][(1 << (i - 1))] = dist(node[i],Node(0,0));
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> node[i].x >> node[i].y;
    }
    init();
	for(int i = 1; i < (1 << n); i++){
        for(int pos = 1; pos <= n; pos++){
        	if(i & (1 << (pos - 1))){
                for(int pos1 = 1; pos1 <= n; pos1++){
                	if((pos1 != pos) && (i & (1 << (pos1 - 1)))) f[pos][i] = min(f[pos][i],f[pos1][i - (1 << (pos - 1))] + dist(node[pos],node[pos1]));
            	}	
			}
        }
    }
    double ans = INF;
    for(int i = 1; i <= n; i++){
        ans = min(ans,f[i][(1 << n) - 1]);
    }
    printf("%.2lf",ans);
    return 0;
}