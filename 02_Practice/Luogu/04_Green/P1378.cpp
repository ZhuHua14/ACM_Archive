// P1378 油滴扩展
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 16;
const double PI = 3.1415926535;
typedef struct Point{
    int x,y;
}Point;
double maxs;
Point point[MAXN];
int n;
int xmax,ymax,xmin,ymin;
double r[MAXN];
bool isread[MAXN];
double ans = 6e8 + 5.0;
double dis(Point a,Point b){
    return sqrt(pow(a.x - b.x,2) + pow(a.y - b.y,2));
}
double minr(bool read[],double round[],Point nowpoint){
    double nowr = min((double)(xmax - nowpoint.x),(double)(nowpoint.x - xmin));
    nowr = min((double)(ymax - nowpoint.y),nowr);
    nowr = min((double)(nowpoint.y - ymin),nowr);
    for(int i = 1; i <= n ;i++){
        if(read[i] == 1){
            if(dis(point[i],nowpoint) <= round[i]){
                nowr = 0.0;
                return nowr;
            }
            nowr = min(nowr,dis(point[i],nowpoint) - round[i]);
        }
    }
    return nowr;
}

void dfs(int nowcnt,double nows){
    if(nowcnt == n){
        //cout << nows << ' ' << maxs - nows << '\n';
        ans = min(ans,abs(maxs - nows));
        return;
    }
    for(int i = 1; i <= n; i++){
        if(isread[i] == 0){
            r[i] = minr(isread,r,point[i]);
            isread[i] = 1;
            dfs(nowcnt + 1,nows + PI * r[i] * r[i]);
            isread[i] = 0;
        }
    }
}
int main(){
    cin >> n;
    cin >> xmax >> ymax >> xmin >> ymin;
    if(xmax < xmin){
        swap(xmax,xmin);
    }
    if(ymax < ymin){
        swap(ymax,ymin);
    }
    maxs = (xmax - xmin) * (ymax - ymin);
    for(int i = 1; i <= n; i++){
        cin >> point[i].x >> point[i].y;
    }
    dfs(0,0.0);
    cout << (int)(ans + 0.5);
    return 0;
}