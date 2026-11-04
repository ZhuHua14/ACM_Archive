#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 2.2e7 + 5;

string s,news;

int d[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    for(auto ch : s){
        news.push_back('#');
        news.push_back(ch);
    }
    news.push_back('#');
    int l = 0, r = -1;
    int ans = -1;
    int n = news.size();
    for(int i = 0; i < n; i++){
        int k;
        if(r != -1) k = min(d[l + r - i],r - i);
        else k = 1;
        while(i - k >= 0 && i + k < n && news[i - k] == news[i + k]){
            k++;
        }
        if(i + k > r){
            r = i + k;
            l = i - k;
        }
        d[i] = k;
        ans = max(d[i] - 1,ans);
    }
    cout << ans;
    return 0;
}