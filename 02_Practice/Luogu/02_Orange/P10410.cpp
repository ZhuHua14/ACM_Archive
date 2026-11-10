// P10410 「QFOI R2」寺秋山霭苍苍
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Node{
    double x,y;
};


Node node[3];
double l,r,S,p,ans;

double dis(Node a, Node b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double getS(double a,double b,double c){
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

void init(){
    double len[3];
    len[0] = dis(node[0],node[1]);
    len[1] = dis(node[0],node[2]);
    len[2] = dis(node[2],node[1]);
    S = getS(len[0],len[1],len[2]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> l >> r;
    for(int i = 0; i < 3; i++){
        cin >> node[i].x >> node[i].y;
    }
    init();
    if(l > 0.5) p = l;
    else if(r < 0.5) p = r;
    else p = 0.5;
    S *= 1 - 3 * p * (1 - p);
    cout << S << endl;
    return 0;
}