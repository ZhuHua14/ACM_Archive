//L. CCPC 新赛制 2
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 30;

struct Commit{
    string name, result;
    int t;
};

vector<Commit> v[MAXN];
set<string> sw[MAXN], sa[MAXN];
int res[MAXN];

int n, m, q;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> q;
    Commit tmp;
    char p;
    for(int i = 1; i <= q; i++){
        cin >> tmp.name >> p >> tmp.result >> tmp.t;
        v[p - 'A'].push_back(tmp);
    }
    bool flag1 = 0, flag2 = 0;
    for(int i = 0; i < n; i++){
        flag2 = 0;
        int sz = v[i].size();
        for(int j = 0; j < sz; j++){
            if(v[i][j].result == "WA"){
                sw[i].insert(v[i][j].name);
            }
            else if(v[i][j].result == "AC"){
                sw[i].insert(v[i][j].name);
                sa[i].insert(v[i][j].name);
            }
            if(j == sz - 1 || 
              (j + 1 < sz && v[i][j].t != v[i][j + 1].t)){
                int e = sw[i].size(), s = sa[i].size();
                if(s >= 50 || (e > 0 && s >= 0.2 * e) || v[i][j].t >= 240){
                    flag2 = 1;
                }
                else if(flag2 == 1){
                    flag1 = 1;
                    cout << char(i + 'A');
                    break;
                }
            }
        }
    }
    if(!flag1) cout << '-';
    return 0;
}