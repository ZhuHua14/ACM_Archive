#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e6 + 5;
const int MAXM = 80;
int node[MAXN][MAXM],soncnt[MAXN];
bool isend[MAXN];

int toint(char c){
    if(c >= 'a' && c <= 'z') return c - 'a';
    else if(c >= 'A' && c <= 'Z') return c - 'A' + 26;
    else return c - '0' + 52;
}
int cnt = 0;
void add(char* s){
    int nowlenth = strlen(s),nowc,nowp = 0;
    for(int i = 0; i < nowlenth; i++){
        nowc = toint(s[i]);
        if(node[nowp][nowc] == 0){
            cnt++;
            node[nowp][nowc] = cnt;
        }
        nowp = node[nowp][nowc];
        soncnt[nowp]++;
        //cout << nowp << ' ';
    }
    //cout << '\n';
    isend[nowp] = 1;
}
int ans = 0;

int findstr(char* s){
    int nowlenth = strlen(s),nowc,nowp = 0;
    for(int i = 0; i < nowlenth; i++){
        nowc = toint(s[i]);
        if(node[nowp][nowc] == 0) return 0;
        nowp = node[nowp][nowc];
    }
    return soncnt[nowp];
}

int t,n,q;
char nowstr[MAXN];
int main(){
    //freopen("in.txt","r",stdin);        
    //freopen("out.txt","w",stdout);
    scanf("%d",&t);
    for(int i = 1; i <= t; i++){
        scanf("%d%d",&n,&q);
        for(int k = 0; k <= cnt; k++){
            for(int j = 0; j <= MAXM; j++){
                node[k][j] = 0;
            }
        }
        for(int j = 0; j <= cnt; j++){
            soncnt[j] = 0;
        }
        cnt = 0;
        for(int j = 1; j <= n; j++){
            scanf("%s",nowstr);
            add(nowstr);
        }
        for(int j = 1; j <= q; j++){
            scanf("%s",nowstr);
            printf("%d\n",findstr(nowstr));
        }
    }
}