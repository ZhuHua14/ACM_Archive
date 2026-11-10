// P1449 后缀表达式
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 60;
stack<int> s;
string str;
int pow10[10] = {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
int toint(int* num,int cnt){
    int ans = 0;
    for(int i = 1; i <= cnt; i++){
        ans += pow10[cnt - i] * num[i];
    }
    return ans;
}
void use(char c){
    int ans = 0,nowfront,nowto;
    nowto = s.top();
    s.pop();
    nowfront = s.top();
    s.pop();
    switch(c){
        case '+':{
            ans = nowto + nowfront;
            break;
        }
        case '-':{
            ans = nowfront - nowto;
            break;
        }
        case '*':{
            ans = nowfront * nowto;
            break;
        }
        case '/':{
            ans = nowfront / nowto;
            break;
        }
    }
    s.push(ans);
}
int main(){
    cin >> str;
    int nownum[MAXN],cnt = 0;
    for(int i = 0; i < str.size(); i++){
        if(str[i] >= '0' && str[i] <= '9'){
            nownum[++cnt] = str[i] - '0';
        }
        else if(str[i] == '.'){
            s.push(toint(nownum,cnt));
            cnt = 0;
        }
        else if(str[i] == '@') break;
        else{
            use(str[i]);
        }
    }
    cout << s.top();
    return 0;
}