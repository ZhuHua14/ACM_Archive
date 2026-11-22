//D - Glitchy Robot
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 5;
const int MAXLOG = 18;

//不开long long见祖宗！！！！！


/*1.对A做前缀和可以得到机器人的当前坐标
  2.答案是前缀和里的最大 - 前缀和里的最小
  3.修改一个数的正负号相当于对后面的数同时做+ / - 2 * a[i]
  4.对于一个数列，从中间劈开，给前面/后面同时加/减一个数，
    最大和最小仍然只会在前面的最大和最小，后面的最大和最小之间产生。

    slu: 对前缀和建最大最小两个ST表，
         暴力的维护每个数字反号时的最大最小并统计答案;
*/

ll n, a[MAXN], presum[MAXN];
ll lb[MAXN], st_max[MAXLOG][MAXN], st_min[MAXLOG][MAXN];

void init(){
    lb[1] = 0;
    lb[2] = 1;
    for(int i = 3; i <= MAXN; i++){
        lb[i] = lb[i / 2] + 1;
    }
}

void getst(){
    for(int i = 0; i <= n; i++){
        st_max[0][i] = presum[i];
        st_min[0][i] = presum[i];
    }
    for(int j = 1; j <= MAXLOG; j++){
        for(int i = 0; i + (1 << j) - 1 <= n; i++){
            st_max[j][i] = max(st_max[j - 1][i],st_max[j - 1][i + (1 << (j - 1))/*i + pow(2,j - 1)*/]);
            st_min[j][i] = min(st_min[j - 1][i],st_min[j - 1][i + (1 << (j - 1))/*i + pow(2,j - 1)*/]);
        }
    }
}

ll getmax(ll l, ll r){
    ll mid = lb[r - l + 1];
    //cerr << l << ' ' << r << ' ' << "mid = " << mid << '|';
    return max(st_max[mid][l], st_max[mid][r - (1 << mid) + 1]);
}

ll getmin(ll l, ll r){
    ll mid = lb[r - l + 1];
    return min(st_min[mid][l], st_min[mid][r - (1 << mid) + 1]);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        presum[i] = a[i] + presum[i - 1];
    }
    init();
    getst();
    ll ans = getmax(0, n) - getmin(0, n) + 1, lmin = 0, lmax = 0, rmin = 0, rmax = 0;
    //cerr << getmax(0, n) << ' ' << getmax(0, n) << ' ' << ans << '\n';
    for(int i = 1; i <= n; i++){
        lmin = getmin(0, i - 1);
        lmax = getmax(0, i - 1);
        if(a[i] > 0){
            rmin = getmin(i, n) - 2 * abs(a[i]);
            rmax = getmax(i, n) - 2 * abs(a[i]);
        }
        else{
            rmin = getmin(i, n) + 2 * abs(a[i]);
            rmax = getmax(i, n) + 2 * abs(a[i]);
        }
        ans = max(ans, max(lmax, rmax) - min(lmin, rmin) + 1);
        //cerr << i << ' ' << lmin << ' ' << lmax << ' ' << rmin << ' ' << rmax << ' ' << ans << '\n';
    }
    cout << ans;
    return 0;
}