// P9913 「RiOI-3」water problem
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e9 + 5;
int t,n;
int main(){
    cin >> t;
    for(int i = 1; i <= t; i++){
        cin >> n;
        if(n >= 6 || n == 1 || n == 4){
            cout << "Yes\n"; 
        }
        else{
            cout << "No\n";
        }
    }
    return 0;
}