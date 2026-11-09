#include<bits/stdc++.h>
using namespace std;
const int MAXN = 40;

vector<int> m[MAXN];
int incnt[MAXN],outcnt[MAXN];
int n,mm;
int toInt(char i){
    return (int)(i - 'A' + 1);
}
char toChar(int i){
    return (char)(i + 'A' - 1);
}
int nowans[MAXN],cnt;
bool isread[MAXN];
int ans = 0;
void dfs(int nowp,int nowcnt){
    if(outcnt[nowp] == 0 || isread[nowp] == 1){
        ans = max(ans,nowcnt);
        return;
    }
    else{
        for(int i = 0; i < m[nowp].size(); i++){
            dfs(m[nowp][i],nowcnt + 1);
        }
    }
}

int bfs(){/*0 -> 无异常 1-> 存在可行解 -1->出现矛盾*/
    queue<int> q;
    memset(nowans,0,sizeof(nowans));
    int nowincnt[MAXN];
    for(int i = 1; i <= n; i++){
        nowincnt[i] = incnt[i];        
        //cout << nowincnt[i] << ' ';
    } 
    //cout << "\n";
    cnt = 0;
    for(int i = 1; i <= n; i++){
        //cout<<i<<' ';
        if(nowincnt[i] == 0){
            q.push(i);
        }
    }
    if(q.empty()){
        return -1;
    }
    int nowtop;
    while(!q.empty()){
        nowtop = q.front();
        q.pop();
        nowans[++cnt] = nowtop;
        for(int i = 0; i < m[nowtop].size(); i++){
            nowincnt[m[nowtop][i]]--;
            if(nowincnt[m[nowtop][i]] == 0){
                q.push(m[nowtop][i]);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        //cout << nowincnt[i] << ' ';
        if(nowincnt[i] != 0){
            //cout << "\n";
            return -1;
        }
    }
    if(cnt == n){
        dfs(nowans[1],1);
        //cout << ans << '\n';
        if(ans == n){
            return 1;
        }
        return 0;
    }
    //cout << "\n";
    return 0;
}
int main(){
    cin >> n >> mm;
    string nowin;
    bool flag = 0;
    int nowcase = 0,finalans = 0;
    for(int i = 1; i <= mm; i++){
        cin >> nowin;
        //cout<<toInt(nowin[0])<<' '<<toInt(nowin[2]);
        m[toInt(nowin[0])].push_back(toInt(nowin[2]));
        incnt[toInt(nowin[2])]++;
        outcnt[toInt(nowin[0])]++;
        if(!flag){
            //cout << i << ":\n"; 
            nowcase = bfs();
            if(nowcase == -1 || nowcase == 1){
                flag = 1;
                finalans = i;
                continue;
            }
        }
    }
    if(flag == 0){
        cout << "Sorted sequence cannot be determined.";
        return 0;
    }
    if(nowcase == -1){
        cout << "Inconsistency found after " << finalans << " relations.";
        return 0;
    }
    string ansraid;
    if(nowcase == 1){
        for(int i = 1; i <= cnt; i++){
            ansraid.push_back(toChar(nowans[i]));
        }
        cout << "Sorted sequence determined after " << finalans << " relations: " << ansraid << '.';
        return 0;
    }    
}