#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 105;
const int MOD = 1e9 + 7;

struct Matrix{
    int sizex,sizey;
    ll cube[MAXN][MAXN];

    Matrix(){ 
        memset(cube,0,sizeof(cube));
        sizex = 0;
        sizey = 0;
    }

    void print(){
        for(int i = 1; i <= sizex; i++){
            for(int j = 1; j <= sizey; j++){
                cout << cube[i][j] << ' ';
            }
            cout << '\n';
        }
    }

    Matrix operator+(const Matrix& a)const{
        Matrix ans;
        ans.sizex = sizex;
        ans.sizey = sizey;
        for(int i = 1; i <= sizex; i++){
            for(int j = 1; j <= sizey; j++){
                ans.cube[i][j] = cube[i][j] + a.cube[i][j];
            }
        }
        return ans;
    }

    Matrix operator-(const Matrix& a)const{
        Matrix ans;
        ans.sizex = sizex;
        ans.sizey = sizey;
        for(int i = 1; i <= sizex; i++){
            for(int j = 1; j <= sizey; j++){
                ans.cube[i][j] = cube[i][j] - a.cube[i][j];
            }
        }
        return ans;
    }

    Matrix operator*(const Matrix& a)const{
        Matrix ans;
        ans.sizex = sizex;
        ans.sizey = a.sizey;
        for(int i = 1; i <= ans.sizex; i++){
            for(int j = 1; j <= ans.sizey; j++){
                for(int k = 1; k <= sizey; k++){
                    ans.cube[i][j] = (ans.cube[i][j] % MOD  + ((cube[i][k] % MOD) * (a.cube[k][j] % MOD)) % MOD) % MOD;
                }
            }
        }
        return ans;
    }


};

Matrix pow(const Matrix& a,ll n){
    Matrix ans,tmp;
    ans.sizex = ans.sizey = a.sizex;
    for(int i = 1; i <= a.sizex; i++){
        ans.cube[i][i] = 1;
    }
    tmp = a;
    while(n){
        if(n & 1){
            ans = ans * tmp;
        }
        tmp = tmp * tmp;
        n >>= 1;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Matrix a,b;
    cin >> a.sizex >> a.sizey >> b.sizey;
    b.sizex = a.sizey;
    for(int i = 1; i <= a.sizex; i++){
        for(int j = 1; j <= a.sizey; j++){
            cin >> a.cube[i][j];
        }
    }
    for(int i = 1; i <= b.sizex; i++){
        for(int j = 1; j <= b.sizey; j++){
            cin >> b.cube[i][j];
        }
    }
    (a * b).print();
    return 0;
}