#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
int pi[MAXN];

void make_pi(string s){
    int j = 0,maxsize = s.size();
    pi[0] = 0;
    for (int i = 1; i < maxsize; i++) {
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
}

int n;
string nowin;
int main(){
    cin >> n;
    cin >> nowin;
    make_pi(nowin);
    cout << n - pi[n - 1];
    return 0;
}