#include<bits/stdc++.h>
using namespace std;
const int MAXN = 105;
int n,f1[MAXN],f2[MAXN],a[MAXN];

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int maxf = 0;
    for(int i = 1; i <= n; i++){
        maxf = 0;
        for(int j = 1; j < n; j++){
            if(a[j] < a[i]) maxf = max(f1[j],maxf);
        }
        f1[i] = maxf + 1;
    }
    for(int i = n; i >= 1; i--){
        maxf = 0;
        for(int j = n; j > i; j--){
            if(a[i] > a[j]) maxf = max(f2[j],maxf);
        }
        f2[i] = maxf + 1;
    }
    int ans = 0;
    for(int k = 1; k <= n; k++){
        ans = max(f1[k] + f2[k],ans);
    }
    cout << n - ans + 1 << endl;
    return 0;
}