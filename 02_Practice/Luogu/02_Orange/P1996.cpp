#include<bits/stdc++.h>
using namespace std;

int n,m;
int main(){
    cin >> n >> m;
    queue<int> q;
    for(int i = 1; i <= n; i++){
        q.push(i);
    }
    int nowtop;
    while(!q.empty()){
        for(int i = 1; i < m; i++){
            nowtop = q.front();
            q.pop(); 
            q.push(nowtop);
        }
        nowtop = q.front();
        q.pop();
        cout << nowtop << ' ';
    }
    return 0;
}