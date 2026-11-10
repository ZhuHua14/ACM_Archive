// P3958 [NOIP 2017 提高组] 奶酪
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 5;
typedef struct Point{
    double x,y,z;
}Point;
Point point[MAXN];
Point Create(double x,double y,double z){
    Point create;
    create.x = x;
    create.y = y;
    create.z = z;
    return create;
}
double dist(Point a,Point b){
    double dx = abs(a.x - b.x),dy = abs(a.y - b.y),dz = abs(a.z - b.z);
    double sum = (dx * dx) + (dy * dy) + (dz * dz);
    return sqrt(sum);
}
int fa[MAXN],n,h,r,t;
int flag[MAXN];
void init(){
    for(int i = 0; i <= n + 1; i++){
        fa[i] = i;
        flag[i] = 0;
    }
}

int find(int x){
    return x == fa[x]? x : (fa[x] = find(fa[x]));
}

bool marge(int f,int s){
    int faf = find(f),fas = find(s);
    if(faf == fas) return 0;
    else{
        fa[fas] = faf;
        return 1;
    }
}
bool isread[MAXN];
bool dfs(int nowp){
    if(flag[nowp] == -1) return 1;
    if(fa[nowp] == nowp) return 0;
    for(int i = 1; i <= n; i++){
        if(fa[i] == nowp && (!isread[i])){
            isread[i] = 1;
            dfs(i);
            isread[i] = 0;
        }
    }
    return 0;
}
int main(){
    cin >> t;
    while(t--){
        cin >> n >> h >> r;
        init();
        for(int i = 1; i <= n; i++){
            cin >> point[i].x >> point[i].y >> point[i].z;
        }
        for(int i = 1; i <= n; i++){
            for(int j = i; j <= n; j++){
                if(dist(point[i],point[j]) <= 2 * r){
                    marge(i,j);
                }
            }
            if(point[i].z <= r){
                marge(0,i);
            }
            if(h - point[i].z <= r){
                marge(n + 1,i);
            }
        }
        if(find(0) == find(n + 1)) cout << "Yes\n";
        else cout << "No\n";
    }
}