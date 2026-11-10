// P1002 [NOIP 2002 普及组] 过河卒
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 25;
typedef struct Point{
    int x,y;
}Point;
int dx[9] = {0,1,-1,2,-2,1,-1,2,-2};
int dy[9] = {0,2,2,1,1,-2,-2,-1,-1};
Point horsepoint,finalpoint;

bool outrange(int x,int y){
    return x > finalpoint.x || y > finalpoint.y || x < 0 || y < 0;
}
int f[MAXN][MAXN];

signed main(){
    cin >> finalpoint.x >> finalpoint.y;
    cin >> horsepoint.x >> horsepoint.y;
    f[0][0] = 1;
    for(int i = 0; i <= finalpoint.x; i++){
        for(int j = 0; j <= finalpoint.y; j++){
            if(!outrange(i - 1,j)) f[i][j] += f[i - 1][j];
            if(!outrange(i,j - 1)) f[i][j] += f[i][j - 1];
            for(int k = 0; k <= 8; k++){
                if((!(outrange(horsepoint.x + dx[k],horsepoint.y + dy[k]))) && ((i == horsepoint.x + dx[k]) && (j == horsepoint.y + dy[k]))){
                    //cout << i << ' ' << j << ' ' << '\n';
                    f[i][j] = 0;
                    break;
                }
            }
        }
    }
    /*for(int i = 1; i <= finalpoint.x; i++){
        for(int j = 1; j <= finalpoint.y; j++){
            cout << f[i][j] << ' ';
        }
        cout << endl;
    }*/
    cout << f[finalpoint.x][finalpoint.y] << endl;
    return 0;
}