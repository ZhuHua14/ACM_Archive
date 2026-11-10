// P1983 [NOIP 2013 普及组] 车站分级
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 5;
int n,m;
vector<int> v[MAXN];
int bot[MAXN],a[MAXN],incnt[MAXN];
bool isinit[MAXN][MAXN];
int nowans = 1;

void tsort(){
    queue<pair<int,int> > q;
    for(int i = 1; i <= n; i++){
        if(incnt[i] == 0){       
            q.push((pair<int,int>){i,1});
        }
    }
    pair<int,int> nowtop;
    while(!q.empty()){
        nowtop = q.front();
        nowans = max(nowans,nowtop.second);
        q.pop();
        for(int i = 0; i < v[nowtop.first].size(); i++){
            incnt[v[nowtop.first][i]]--;
            if(incnt[v[nowtop.first][i]] == 0){
                q.push((pair<int,int>){v[nowtop.first][i],nowtop.second + 1});
            } 
        }
    }
}

int main(){
    cin >> n >> m;
    int nowcnt;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            bot[j] = 0;
        }
        cin >> nowcnt;
        for(int j = 1; j <= nowcnt; j++){
            cin >> a[j];
            bot[a[j]] = 1;
            //cout << a[j] << ' ' << bot[a[j]] << '|';
        }
        /*for(int j = 1; j <= nowcnt; j++){
            cout << a[j] << ' ';
        }
        cout << '\\';
        for(int j = 1; j <= n; j++){
            cout << bot[j] << ' ';
        }
        cout << '\\';*/
        for(int k = a[1]; k <= a[nowcnt]; k++){
            if(bot[k] == 0){
                for(int j = 1; j <= nowcnt; j++){
                    if(isinit[k][a[j]]) continue;
                    //cout << k << ' ' << a[j] << '|';
                    v[k].push_back(a[j]);
                    incnt[a[j]]++;
                    isinit[k][a[j]] = 1;
                }
            }
        }
        //cout << endl;
    }
    tsort();
    cout << nowans;
    return 0;
}