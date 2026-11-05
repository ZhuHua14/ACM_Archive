#include<bits/stdc++.h>
using namespace std;
const int MAXN = 255;
string num;
int k,intnum[MAXN],nowlenth;
void erase(int pos){
    for(int i = pos + 1; i < nowlenth; i++){
        intnum[i - 1] = intnum[i];
    }
    nowlenth--;
}
int main(){
    //freopen("out.txt","w",stdout);
    cin >> num >> k;    
    nowlenth = num.size();
    for(int i = 0; i < nowlenth; i++){
        intnum[i] = num[i] - '0';
    }
    int pos = 0,nowcnt = 0;
    while(nowcnt < k){
        if(intnum[pos - 1] > intnum[pos]){
            erase(pos - 1);
            pos = 0;
            nowcnt++;
        }
        else if(pos == nowlenth - 1){
            erase(pos);
            pos = 0;
            nowcnt++;
        }
        else{
            pos++;
        }
    }
    bool flag = 1;
    for(int i = 0; i < nowlenth; i++){
        if(flag && intnum[i] == 0 && nowlenth != 1) continue;
        flag = 0;
        cout << intnum[i];
    }
    return 0;
}