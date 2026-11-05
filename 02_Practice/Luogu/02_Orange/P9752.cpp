#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 10;
const int LIM = 1e5 + 5;

int n,a[MAXN][7],ans;

pair<bool,int> check(int b[]){
    int p[7],diff;
    for(int i = 1; i <= n; i++){
        memset(p,0,sizeof(p));
        diff = 0;
        for(int j = 1; j <= 5; j++){
            // //cerr << a[i][j] << ' ' << b[j] << endl;
            if(a[i][j] != b[j]){
                p[++diff] = j;
            }
        }
        if(diff == 1) continue;
        else if(diff >= 3 || diff == 0) return {false,diff};
        else if(p[2] - p[1] != 1) return {false,diff};
        else{
            int d1 = (b[p[1]] > a[i][p[1]])? b[p[1]] - a[i][p[1]] : 10 - (a[i][p[1]] - b[p[1]]);
            int d2 = (b[p[2]] > a[i][p[2]])? b[p[2]] - a[i][p[2]] : 10 - (a[i][p[2]] - b[p[2]]);
            if(d1 != d2) return {false,diff};
        }
    }
    return {true,diff};
}

void print(int st[]){
    for(int i = 1; i <= 5; i++){
        //cerr << st[i] << ' ';
    }
    //cerr << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 5; j++){
            cin >> a[i][j];
        }
    }
    int st[7],cnt;
    // memset(st,0,sizeof(st));
    // check(st);
    for(int i = 0; i <= 1e5 - 1; i++){
        memset(st,0,sizeof(st));
        int tmp = i;
        cnt = 0;
        while(tmp != 0){
            st[++cnt] = tmp % 10;
            tmp /= 10;
        }
        if(check(st).first){
            ans++;
            //cerr << check(st).second << ' ';
            print(st);
        }
    }
    cout << ans << '\n';
    return 0;
}