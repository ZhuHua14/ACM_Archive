#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 105;
const int MOD = 1e9 + 7;

struct Matrix{
    int sizex,sizey;
    ll cube[MAXN][MAXN];

    void print(){
        cout << sizex << ' ' << sizey << '\n';
        for(int i = 1; i <= sizex; i++){
            for(int j = 1; j <= sizey; j++){
                cout << cube[i][j] << ' ';
            }
            cout << '\n';
        }
    }

    Matrix operator+(const Matrix& other)const;

};

Matrix Matrix::operator+(const Matrix& other)const{
    Matrix ans;
    ans.sizex = sizex;
    ans.sizey = sizey;
    for(int i = 1; i <= ans.sizex; i++){
        for(int j = 1; j <= ans.sizey; j++){
            ans.cube[i][j] = cube[i][j] + other.cube[i][j];
        }
    }
    return ans;
}

// Matrix pow(Matrix a,ll n){
//     Matrix ans,tmp;
//     ans.sizex = ans.sizey = a.sizex;
//     for(int i = 1; i <= a.sizex; i++){
//         ans.cube[i][i] = 1;
//     }
//     tmp = a;
//     while(n){
//         if(n & 1){
//             ans = ans * tmp;
//         }
//         tmp = tmp * tmp;
//         n >>= 1;
//     }
//     return ans;
// }

Matrix a,b;

int main(){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
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
    Matrix c = a + b;
    return 0;
}