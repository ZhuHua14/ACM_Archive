#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;

int n, a[MAXN];
map<int, int> m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        m[a[i]]++;
    }
    auto it = m.begin();
    int len = 0, ans = 1e9;
    while(it != m.end()){
        //cerr << it->first << '|';
        if(next(it) == m.end() || 
          (next(it)->second < it->second) ||
          (next(it)->first != it->first + 1) ){
            len++;
            it->second--;
            if(it->second == 0){
                it = m.erase(it);
            }
            ans = min(ans, len);
            it = m.begin();
            //cerr << it->first << ' ';
            len = 0;
            continue;
        }
        it->second--;
        len++;
        if(it->second == 0){
            it = m.erase(it);
        }
        else{
            it++;
        }
        //cerr << '\n';
    }
    cout << ans;
    return 0;
}
/*-5 -4 -3 2 3 4 5*/