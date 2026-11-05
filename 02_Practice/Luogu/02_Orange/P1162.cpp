#include<bits/stdc++.h>
using namespace std;
const int MAXN = 35;
int mmap[MAXN][MAXN],n;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
bool outofrange(pair<int,int> point){
    return point.first <= 0 || point.second <= 0 || point.second > n || point.first > n;
}
int main(){
    cin >> n;
    bool flag = 0;
    pair<int,int> start;
    queue<pair<int,int> > q;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> mmap[i][j];
            if((i == 1 || i == n || j == 1 || j == n) && mmap[i][j] == 0){
                q.push({i,j});
            }
            if(mmap[i][j] == 0){
                mmap[i][j] = 2;
            }
        }
    }
    pair<int,int> nowtop;
    while(!q.empty()){
        nowtop = q.front();
        q.pop();
        for(int i = 0; i <= 3; i++){
            if(mmap[nowtop.first + dx[i]][nowtop.second + dy[i]] == 2 && !outofrange({nowtop.first + dx[i],nowtop.second + dy[i]})){
                q.push({nowtop.first + dx[i],nowtop.second + dy[i]});
                mmap[nowtop.first + dx[i]][nowtop.second + dy[i]] = 0;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << mmap[i][j] << ' ';
        }
        cout << "\n";
    }
    return 0;
}
