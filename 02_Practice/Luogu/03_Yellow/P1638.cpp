#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e6 + 5;

int n,m,a[MAXN];
int bot[MAXN],cnt;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int l = 1,r = 1,ansl = 0,ansr = 1e8;
    while(r <= n){
        bot[a[r]]++;
        if(bot[a[r]] == 1) cnt++;
        if(cnt == m){
            if(r - l < ansr - ansl){
                ansr = r;
                ansl = l;
            }
            while(l < r){
                bot[a[l]]--;
                if(bot[a[l]] == 0) cnt--;
                l++;
                if(cnt < m) break;
                if(r - l < ansr - ansl){
                    ansr = r;
                    ansl = l;
                }
            }
        }
        r++;
    }
    cout << ansl << ' ' << ansr;
   return 0;
}