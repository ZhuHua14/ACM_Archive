#include<bits/stdc++.h>
using namespace std;
const int MAXN = 105;
const int MAXT = 1e3 + 5;
struct Rubbish{
    int time,life,height;
};

bool cmp(Rubbish x,Rubbish y){
    return x.time < y.time;
}

Rubbish rubbish[MAXN];

int D,G,f[MAXN][MAXT];
int main(){
    //freopen("in.txt","r",stdin);
    cin >> D >> G;
    for(int i = 1; i <= G; i++){
        cin >> rubbish[i].time >> rubbish[i].life >> rubbish[i].height;
    }
    sort(rubbish + 1,rubbish + 1 + G,cmp);
    //memset(f,-0x3f,sizeof(f));
    f[0][0] = 10;
    for(int i = 1; i <= G; i++){
        for(int j = 0; j <= D; j++){
            if(j >= rubbish[i].height && f[i - 1][j - rubbish[i].height] >= rubbish[i].time){
                f[i][j] = max(f[i - 1][j - rubbish[i].height],f[i][j]);
            }
            if(f[i - 1][j] >= rubbish[i].time){
                f[i][j] = max(f[i - 1][j] + rubbish[i].life,f[i][j]);
            }
        }
    }
    int ans = 0;
    int ans_alive = 0;
    bool flag = 1;
    for(int i = 1; i <= G; i++){
        if(f[i][D] >= rubbish[i].time && flag) {
            ans_alive = i;
            flag = 0;
        }
        ans = max(ans,f[i][0]); 
    }
    if(ans_alive > 0){
         cout << rubbish[ans_alive].time /*<< ' ' << 1*/;
         return 0;
    }
    cout << ans;
    return 0;
    /*int maxh=0;
    int maxt=0;
    int i;
    for(i=1;i<=G;i++)
    {
        for(int j=0;j<=D;j++)
        {
            if(f[i][j]-rubbish[i].time>=0)
                maxh=max(maxh,j);
            maxt=max(maxt,f[i][j]);
        }
        if(maxh==D)
            break;
    }
    if(maxh==D)
        cout<<1<<' '<<rubbish[i].time<<endl;
    else
        cout<<2<<' '<<maxt<<endl;*/
}