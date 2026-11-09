#include<bits/stdc++.h>
using namespace std;
string str;
long long n;
long long dfs(long long n){
    long long l = 1;
    int lenth = str.size();
    while(n > lenth){
        l = lenth;
        while(l < n) l *= 2;
        l /= 2;
        //cout << l << ' ' << n << ' ' << n - l <<  "\n";
        if(n - l == 1) n = l;
        else n = n - l - 1;
    }
    //cout << n <<  "\n";
    return n - 1;
}
int main(){
    cin >> str >> n;
    long long ans = dfs(n);
    cout << str[ans];
    return 0;
}