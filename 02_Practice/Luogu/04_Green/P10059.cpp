// P10059 Choose
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const int MAXLOG = 25;
const int INF = 0x3f3f3f3f;
int lb[MAXN],a[MAXN],ans[MAXN],maxf[MAXN][MAXLOG],minf[MAXN][MAXLOG];
int t,n,k;

void getLog(){
    lb[1] = 0;
    lb[2] = 1;
    for(int i = 3; i <= MAXN; i++){
        lb[i] = lb[i / 2] + 1;
    }
}

void clear(){
    memset(a,0,sizeof(a));
    memset(ans,0,sizeof(ans));
    /*for(int i = 1; i <= MAXN; i++){
        for(int j = 0; j <= MAXLOG; j++){
            maxf[i][j] = -INF;
            minf[i][j] = INF;
        }
    }*/
}

void init(){
    for(int i = 1; i <= n; i++){
        maxf[i][0] = a[i];
        minf[i][0] = a[i];
    }
    for(int len = 1; len <= MAXLOG; len++){
        for(int i = 1; i + (1 << len) - 1 <= n; i++){
            maxf[i][len] = max(maxf[i][len - 1],maxf[i + (1 << (len - 1))][len - 1]);
            minf[i][len] = min(minf[i][len - 1],minf[i + (1 << (len - 1))][len - 1]);
        }
    }
}

int rmax(int l,int r){
    int mid = lb[r - l + 1];
    //cout <<"max:" << mid << ' ' << maxf[l][mid] << ' ' << maxf[r - (1 << mid) + 1][mid];
    return max(maxf[l][mid],maxf[r - (1 << mid) + 1][mid]);
}

int rmin(int l,int r){
    int mid = lb[r - l + 1];
    return min(minf[l][mid],minf[r - (1 << mid) + 1][mid]);
}

int check(int len){
    int r = 0,cnt = 0;
    for(int l = 1; l + len - 1 <= n; l++){
        cnt++;
        r = l + len - 1;
        //cout << rmax(l,r) << ' ' << rmin(l,r) << ' ' << l  << ' ' << r << '|';
        ans[l] = rmax(l,r) - rmin(l,r);
    }
    sort(ans + 1,ans + cnt + 1,greater<int>());
    return ans[k];
}

int main(){
    cin >> t;
    getLog();
    while(t--){
        clear();
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        init();
        int maxm = check(n - k + 1);
        cout << maxm << ' ';
        int l = 1,r = n - k + 1,nowans = r;
        while(l < r){
            int mid = (l + r) / 2;
            if(check(mid) >= maxm){
                nowans = mid;
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        cout << nowans << endl;
    }
    return 0;
}