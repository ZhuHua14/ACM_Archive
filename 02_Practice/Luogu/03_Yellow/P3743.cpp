// P3743 小鸟的设备
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 1e5 + 5;
const double LIM = 1e18;
const double eps = 1e-6;

int n,p;

struct Node{
    double a, b;
    double t;
    Node() {}
};

Node node[MAXN];

bool cmp(Node x, Node y){
    return x.t < y.t;
}

bool check(double t){
    double sume = t * p;
    for(int i = 1; i <= n; i++){
        if(node[i].t >= t) break;
        sume -= t * node[i].a - node[i].b;
        if(sume < 0){
            return 0;
        }
    }
    if(sume < 0) return 0;
    return 1;
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> p;
    double suma = 0;
    for(int i = 1; i <= n; i++){
        cin >> node[i].a >> node[i].b;
        node[i].t  = node[i].b / node[i].a;
        suma += node[i].a;
    }
    sort(node + 1, node + 1 + n, cmp);
    double l = node[1].t, r = LIM;
    if(suma <= p){
        cout << -1 << endl;
        return 0;
    }
    while(r - l >= eps){
        double mid = (l + r) / 2;
        if(check(mid)){
            l = mid;
        }
        else{
            r = mid;
        } 
    }
    cout << (l + r) / 2 << endl;
    return 0;
}