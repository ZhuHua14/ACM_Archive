//C - Second Choice Election
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;
struct Noters{
    int a, b;
};
Noters noter[MAXN];


 //

int n, m;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> noter[i].a >> noter[i].b;
    }

    return 0;
}