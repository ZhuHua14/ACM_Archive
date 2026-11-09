#include<bits/stdc++.h>
using namespace std;
const int MAXN = 20;
const int MOD = 1e4;
stack<long long> s1;
long long pow10[13] = {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000,10000000000,100000000000,1000000000000};
long long toint(int* num,int cnt){
    long long ans = 0;
    for(int i = 1; i <= cnt; i++){
        ans += pow10[cnt - i] * num[i];
    }
    return ans % MOD;
}
int num[MAXN],cnt,nowfront,nowto;
string str;
int main(){
    //freopen("in.txt","r",stdin);
    cin >> str;
    bool flag = 0;
    for(int i = 0; i < str.size(); i++){
        if(str[i] >= '0' && str[i] <= '9'){
            num[++cnt] = str[i] - '0';
        }
        else{
            s1.push(toint(num,cnt));
            if(flag){
                //cout << s1.top() << ' ' ;
                nowfront = s1.top();
                s1.pop();
                nowto = s1.top();
                s1.pop();
                s1.push((nowfront % MOD) * (nowto % MOD) % MOD);
                flag = 0;
            }
            if(str[i] == '*'){
                flag = 1;
            }
            cnt = 0;
        } 
    }
    if(cnt != 0){
        s1.push(toint(num,cnt));
        if(flag){
            //cout << s1.top() << ' ' ;
            nowfront = s1.top();
            s1.pop();
            nowto = s1.top();
            s1.pop();
            s1.push((nowfront % MOD) * (nowto % MOD) % MOD);
            flag = 0;
        }
    }
    int ans = 0;
    while(!s1.empty()){
        //cout << s1.top() << ' ' ;
        ans += (s1.top() % MOD);
        ans %= MOD;
        s1.pop();
    }
    cout << ans % MOD;
    return 0;
}