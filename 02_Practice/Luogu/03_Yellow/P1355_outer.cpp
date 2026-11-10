// P1355 神秘大三角
#include<bits/stdc++.h>
using namespace std;

const double EPS = 1e-6;

struct Point{
    double x = 0, y = 0;

    bool operator==(const Point other)const{
        return fabs(x - other.x) <= EPS && fabs(y - other.y) <= EPS;
    }

    void print(){
        cerr << x << ' ' << y << '\n';
    }
};

bool isin(Point a,Point b,Point p){
    bool flag1 = fabs(((a.y - b.y) * (a.x - p.x)) - ((a.x - b.x) * (a.y - p.y))) <= EPS;
    bool flag2 = (p.x >= min(a.x,b.x)) && (p.x <= max(a.x,b.x));
    bool flag3 = (p.y >= min(a.y,b.y)) && (p.y <= max(a.y,b.y));
    return flag1 && flag2 && flag3;
}

Point a,b,c,p;

struct Vector{
    double x = 0, y = 0;

    Vector() {}
    Vector(Point a,Point b) : x(b.x - a.x), y(b.y - a.y) {}

    double operator*(const Vector other)const{
        return x * other.y - other.x * y;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> p.x >> p.y;
    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    cin >> c.x >> c.y;
    if(a == p || b == p || c == p){
        cout << "On";
        return 0;
    }
    else if(isin(a,b,p) || isin(a,c,p) || isin(b,c,p)){
        cout << "On";
        return 0;
    }

    Vector ab = Vector(a,b),bc = Vector(b,c),ca = Vector(c,a);
    Vector ap = Vector(a,p),bp = Vector(b,p),cp = Vector(c,p);

    if((ab * ap > 0 && bc * bp > 0 && ca * cp > 0) || 
       (ab * ap < 0 && bc * bp < 0 && ca * cp < 0) ){
        cout << "In";
    }
    else cout << "Out";
    return 0;
}