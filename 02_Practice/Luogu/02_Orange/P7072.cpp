#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;
const int MAXA = 605;

int n,w,a[MAXN];
int bot[MAXA],maxa = 0;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> w;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }    
    for(int i = 1; i <= n; i++){
        bot[a[i]]++;
        maxa = max(maxa,a[i]);
        int pos = maxa,cnt = max(1,i * w / 100);
        while(cnt - bot[pos] > 0){
            cnt -= bot[pos];  
            pos--;
        }
        cout << pos << ' ';
    }
   return 0;
}