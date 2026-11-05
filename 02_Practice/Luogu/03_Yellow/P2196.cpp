#include<bits/stdc++.h>
using namespace std;
const int MAXN = 25;

int val[MAXN];
bool cube[MAXN][MAXN];
/*vector<int> dag1[MAXN],dag2[MAXN];*/
int f[MAXN],pre[MAXN];

void print(int nowp){
    if(pre[nowp] == 0){
        cout << nowp << ' ';
        return;
    }
    print(pre[nowp]);
    cout << nowp << ' ';
}
/*void dfs(int from){
    if(dag2[from].size() == 0){
        bool flag = 0;
        for(int i = 0; i <= dag1[from].size(); i++){
            if(f[dag1[from][i]] + val[from] > f[from]){
                if(flag = 0){
                    cnt2++;
                    temp[cnt2] = from;
                    f[from] = f[dag1[from][i]] + val[from];
                }
            }
        }
    }
    for(int i = 0 ;)
}*/

//f[i] = max(f[j]) + val[i] ((j,i))
int n;
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> val[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            cin >> cube[i][j];
        }
    }
    int nowans = 0,nowend = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j < i; j++){
            if(cube[j][i] != 0 && f[j] > f[i]){
                f[i] = f[j];
                pre[i] = j;
            }
        }
        f[i] += val[i];
        if(nowans < f[i]){
            nowans = f[i];
            nowend = i;
        }
    }
    print(nowend);
    cout << endl;
    cout << nowans;
    return 0;
}