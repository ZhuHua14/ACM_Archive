// P8818 [CSP-S 2022] 策略游戏
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 1e5 + 5;
const int MAXLOG = 20;
const ll INF = 0x3f3f3f3f3f3f3f3f;

ll n,m,q;
ll lb[MAXN];
 
void getlog(){
    lb[1] = 0;
    lb[2] = 1;
    for(int i = 3; i < MAXN; i++){
        lb[i] = lb[i / 2] + 1;
    }
}

struct STable{
    ll len,ary[MAXN];
    ll st1[2][MAXN][MAXLOG],st2[MAXN][MAXLOG],st3[MAXN][MAXLOG];
    /*st2+0min st3-0max st1[0]max st1[1]min*/

    void init(){
        for(int i = 1; i <= len; i++){
            st1[0][i][0] = ary[i];
            st1[1][i][0] = ary[i];
            if(ary[i] >= 0){
                st2[i][0] = ary[i];
                st3[i][0] = -INF;
            }    
            else if(ary[i] < 0){
                st2[i][0] = INF;
                st3[i][0] = ary[i];
            }
        }
        for(int pow = 1; pow < MAXLOG; pow++){
            for(int i = 1; i + (1 << (pow)) - 1 <= len; i++){
                st1[0][i][pow] = max(st1[0][i][pow - 1],st1[0][i + (1 << (pow - 1))][pow - 1]);
                st1[1][i][pow] = min(st1[1][i][pow - 1],st1[1][i + (1 << (pow - 1))][pow - 1]);
                st2[i][pow] = min(st2[i][pow - 1],st2[i + (1 << (pow - 1))][pow - 1]);
                st3[i][pow] = max(st3[i][pow - 1],st3[i + (1 << (pow - 1))][pow - 1]);
            }
        }
    }

    ll findmax(ll l,ll r){
        ll mid = lb[r - l + 1];
        return max(st1[0][l][mid],st1[0][r - (1 << mid) + 1][mid]);
    }/*max*/
    
    ll findmin(ll l,ll r){
        ll mid = lb[r - l + 1];
        return min(st1[1][l][mid],st1[1][r - (1 << mid) + 1][mid]);
    }/*min*/
    
    ll findmax2(ll l,ll r){
        ll mid = lb[r - l + 1];
        return max(st3[l][mid],st3[r - (1 << mid) + 1][mid]);
    }/*-0max*/
    
    ll findmin2(ll l,ll r){
        ll mid = lb[r - l + 1];
        return min(st2[l][mid],st2[r - (1 << mid) + 1][mid]);
    }/*+0min*/

};

STable sta,stb;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    getlog();
    cin >> n >> m >> q;
    sta.len = n, stb.len = m;
    for(int i = 1; i <= n; i++){
        cin >> sta.ary[i];
    }
    for(int i = 1; i <= m; i++){
        cin >> stb.ary[i];
    }
    sta.init(), stb.init();
    ll l1,r1,l2,r2;
    while(q--){
        cin >> l1 >> r1 >> l2 >> r2;
        ll amax = sta.findmax(l1,r1),amin2 = sta.findmin2(l1,r1),amax2 = sta.findmax2(l1,r1),amin = sta.findmin(l1,r1);
        ll bmax = stb.findmax(l2,r2),bmin2 = stb.findmin2(l2,r2),bmax2 = stb.findmax2(l2,r2),bmin = stb.findmin(l2,r2);
        //cout << amax << ' ' << amin2 << ' ' << amax2 << ' ' << amin << '\n';
        //cout << bmax << ' ' << bmin2 << ' ' << bmax2 << ' ' << bmin << '\n';
        if(bmin >= 0){/*a+0- b+0*/
            if(amax < 0) cout /*<< "3-1" */<< amax * bmax << '\n';
            else cout /*<< "3-2" */<< amax * bmin << '\n';
        }
        else if(bmax < 0){/*a+0- b-*/
            if(amin >= 0) cout /*<< "4-1" */<< amin * bmin << '\n';
            else cout /*<< "4-2" */<< amin * bmax << '\n';
        }
        else if(amax < 0){/*a- b+0-*/
            //cout << 1 << ' ';
            cout << amax * bmax << '\n';
        }
        else if(amin >= 0){/*a+0 b+0-*/
            //cout << 2 << ' ';
            cout << amin * bmin << '\n';
        }
        else{
            //cout << 5 << ' ';
            cout << max(amin2 * bmin,amax2 * bmax) << '\n';
        }
        //cout << '\n';
    }
    return 0;
}


/*719 720 721 2 
  736 737 738 2
  749 750 751 1
  786 787 788 1
  809 810 811 2 
  881 882 883 884 885  2 
  962 963 964 965 1 2
*/