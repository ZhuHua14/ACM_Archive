#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 1e5 + 5;
int n,m1,m2;
/*是编号靠前而不是离开时间靠前，因为可能会出现一个很远的廊桥来来往往结果前面的没人用的情况*/

struct Airline{
    int l,r;
};
Airline air1[MAXN],air2[MAXN];
bool cmp(Airline a,Airline b){
    return a.l < b.l;
}

int airct1[MAXN],airct2[MAXN];
void print(Airline a[],int len){
    for(int i = 1; i <= len; i++){
        //cerr << a[i].l << ' ' << a[i].r << '\n';
    }
}

struct Node1{
    int l,r,cnt,id;

    bool operator<(const Node1 a)const{
        return id > a.id;
    }
    void print(){
        //cerr << l << ' ' << r << ' ' << id << ' ' << cnt << '\n'; 
    }
};
priority_queue<Node1> q1;/*闲廊桥*/

struct Node2{
    int l,r,cnt,id;

    bool operator<(const Node2 a)const{
        return r > a.r;
    }
    void print(){
        //cerr << l << ' ' << r << ' ' << id << ' ' << cnt << '\n'; 
    }
};
priority_queue<Node2> q2;/*忙廊桥*/


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m1 >> m2;
    for(int i = 1; i <= m1; i++){
        cin >> air1[i].l >> air1[i].r;
    }
    for(int i = 1; i <= m2; i++){
        cin >> air2[i].l >> air2[i].r;
    }
    sort(air1 + 1,air1 + 1 + m1,cmp);
    sort(air2 + 1,air2 + 1 + m2,cmp);
    print(air1,m1);
    //cerr << '\n';
    print(air2,m2);
    //cerr << '\n';

    Node1 top1 = {0,0,0,0};/*闲*/
    Node2 top2 = {0,0,0,0};/*忙*/
    int cnt1 = 0;
    q2.push({air1[1].l,air1[1].r,1,++cnt1});
    for(int i = 2; i <= m1; i++){
        while(!q2.empty()){
            //cerr << "err1\n";
            top2 = q2.top();
            if(top2.r < air1[i].l){
                //cerr << "A ";
                top2.print();
                q1.push({top2.l,top2.r,top2.cnt,top2.id});
                q2.pop();
            }
            else{
                break;
            }
        }
        if(q1.empty()){
            //cerr << "B ";
            //cerr << air1[i].l << ' ' << air1[i].r << ' ' << 1 << ' ' << cnt1 + 1 << '\n';
            top2.print();
            q2.push({air1[i].l,air1[i].r,1,++cnt1});
            continue;
        }
        top1 = q1.top();
        if(top1.r > air1[i].l){
            //cerr << "C ";
            top1.print();
            q2.push({air1[i].l,air1[i].r,1,++cnt1});
            continue;    
        }
        q1.pop();
        q2.push({top1.l,air1[i].r,++top1.cnt,top1.id});
    }
    //cerr << '\n';
    while(!q1.empty()){
        top1 = q1.top();
        q1.pop();
        top1.print();
        airct1[top1.id] = top1.cnt;
    }
    while(!q2.empty()){
        top2 = q2.top();
        q2.pop();
        top2.print();
        airct1[top2.id] = top2.cnt;
    }
    //cerr << '\n';
    for(int i = 1; i <= n; i++){
        airct1[i] += airct1[i - 1];
        //cerr << airct1[i] << ' ';
    }
    
    //cerr << "\n-------\n";

    int cnt2 = 0;
    top1 = {0,0,0,0};
    top2 = {0,0,0,0};
    q2.push({air2[1].l,air2[1].r,1,++cnt2});
    for(int i = 2; i <= m2; i++){
        while(!q2.empty()){
            top2 = q2.top();
            if(top2.r < air2[i].l){
                //cerr << "A ";
                top2.print();
                q1.push({top2.l,top2.r,top2.cnt,top2.id});
                q2.pop();
            }
            else{
                break;
            }
        }
        if(q1.empty()){
            //cerr << "B ";
            //cerr << air2[i].l << ' ' << air2[i].r << ' ' << 1 << ' ' << cnt2 + 1 << '\n';
            q2.push({air2[i].l,air2[i].r,1,++cnt2});
            continue;
        }
        top1 = q1.top();
        if(top1.r > air2[i].l){
            //cerr << "C ";
            top1.print();
            q2.push({air2[i].l,air2[i].r,1,++cnt2});
            continue;    
        }
        q1.pop();
        q2.push({top1.l,air2[i].r,++top1.cnt,top1.id});
    }
    //cerr << '\n';
    while(!q1.empty()){
        top1 = q1.top();
        q1.pop();
        top1.print();
        airct2[top1.id] = top1.cnt;
    }
    while(!q2.empty()){
        top2 = q2.top();
        q2.pop();
        top2.print();
        airct2[top2.id] = top2.cnt;
    }
    //cerr << '\n';
    for(int i = 1; i <= n; i++){
        airct2[i] += airct2[i - 1];
        //cerr << airct2[i] << ' ';
    }    

    int ans = 0;
    for(int i = 0; i <= n; i++){
        ans = max(ans,airct1[i] + airct2[n - i]);
    }
    cout << ans << '\n';
    return 0;
}