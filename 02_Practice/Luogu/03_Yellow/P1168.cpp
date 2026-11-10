// P1168 中位数
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
priority_queue<int> pq1;
priority_queue<int,vector<int>,greater<int> > pq2;
int a[MAXN],n;
void balence(){
    while(pq2.size() < (pq1.size() + pq2.size() + 1) / 2){
        pq2.push(pq1.top());
        pq1.pop();
    }
    while(pq2.size() > (pq1.size() + pq2.size() + 1) / 2){
        pq1.push(pq2.top());
        pq2.pop();
    }
}
void insert(int x){
    if(pq2.empty() || x >= pq2.top()){
        pq2.push(x);
        balence();
    }
    else{
        pq1.push(x);
        balence();
    }
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        insert(a[i]);
        if(i % 2 == 1){
            cout << pq2.top() << '\n';
        }
    }
    return 0;
}