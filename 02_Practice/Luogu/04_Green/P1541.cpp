#include<bits/stdc++.h>
using namespace std;
const int MAXN = 355;
const int MAXCNT = 45;
int score[MAXN],n,m,bot[5],f[MAXCNT][MAXCNT][MAXCNT][MAXCNT];

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> score[i];
    }
    int nowin;
    for(int i = 1; i <= m; i++){
        cin >> nowin;
        bot[nowin]++;
    }
    f[0][0][0][0] = score[1];
    for(int c1 = 0; c1 <= bot[1]; c1++){
    for(int c2 = 0; c2 <= bot[2]; c2++){
    for(int c3 = 0; c3 <= bot[3]; c3++){
    for(int c4 = 0; c4 <= bot[4]; c4++){
        int nowp = 1 + c1 + c2 * 2 + c3 * 3 + c4 * 4;
        if(c1 != 0) f[c1][c2][c3][c4] = max(f[c1][c2][c3][c4],f[c1 - 1][c2][c3][c4] + score[nowp]);
        if(c2 != 0) f[c1][c2][c3][c4] = max(f[c1][c2][c3][c4],f[c1][c2 - 1][c3][c4] + score[nowp]);
        if(c3 != 0) f[c1][c2][c3][c4] = max(f[c1][c2][c3][c4],f[c1][c2][c3 - 1][c4] + score[nowp]);
        if(c4 != 0) f[c1][c2][c3][c4] = max(f[c1][c2][c3][c4],f[c1][c2][c3][c4 - 1] + score[nowp]);
    }    
    }    
    }    
    }
    cout << (f[bot[1]][bot[2]][bot[3]][bot[4]]) << endl;
    return 0;
}
