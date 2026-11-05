#include<bits/stdc++.h>
using namespace std;
const int MAXN = 25;

int isread[MAXN];
string str[MAXN];
int n;
int ans = -0x3f3f3f3f;

int canto(string fromstr,string nextstr){
    int lenfrom = fromstr.size();
    int fromi = lenfrom - 1,toi = 0;
    while(fromi > 0 && toi < nextstr.size() - 1){
        if(fromstr.substr(fromi,lenfrom) == nextstr.substr(0,toi + 1) ){
            return fromstr.substr(fromi,lenfrom).size();
        }
        fromi--;
        toi++;
    }
    return 0;
}

string add(string sum,string add,int cnt){
    return sum + add.substr(cnt,add.size());
}

void dfs(string nowstr,int nowfrom){
    for(int i = 1; i <= n; i++){
        if(isread[i] < 2){
            int nowcnt = canto(str[nowfrom],str[i]);
            //cout << nowcnt << ' ' << str[nowfrom] << ' ' << str[i] << '\n'; 
            if(nowcnt != 0 && nowcnt != str[nowfrom].size() && str[i].size()){
                isread[i]++;
                dfs(add(nowstr,str[i],nowcnt),i);
                isread[i]--;
            }
        }
    }
    int nowsize = nowstr.size();
    //cout << nowstr << ' ' << ans << '\n';
    ans = max(ans,nowsize);
    return;
}


int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> str[i];
    }
    char start;
    cin >> start;
    for(int i = 1; i <= n; i++){
        if(str[i][0] == start){
            memset(isread,0,sizeof(isread));
            isread[i]++;
            dfs(str[i],i);
        }
    }
    cout << ans;
    return 0;
}