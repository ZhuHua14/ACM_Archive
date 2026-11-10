// P10058 Reverse and Rotate
#include<bits/stdc++.h>
using namespace std;
string s;
int n,revcnt,movecnt;
int main(){
    cin >> s;
    cin >> n;
    int len = s.size();
    char op;
    string temp;
    int nowmove;
    for(int i = 1; i <= n; i++){
        cin >> op;
        if(op == 'r'){
            cin >> temp;
            revcnt++;
            revcnt %= 2;
        }
        else{
            cin >> nowmove;
            if(revcnt == 1){
                if(op == '>'){
                    movecnt -= nowmove;
                }
                else{
                    movecnt += nowmove;
                }
            }
            else{
                if(op == '<'){
                    movecnt -= nowmove;
                }
                else{
                    movecnt += nowmove;
                }
            }
            movecnt += len;
            movecnt %= len;
        }
    }
    string ans1;
    if(revcnt == 0){
        ans1 = s;
    }
    else{
        for(int i = 0; i < len; i++){
            ans1.push_back(s[len - i - 1]);
        }
    }
    string ans2;
    if(revcnt == 1) movecnt = len - movecnt;
    for(int i = len - movecnt; i < 2 * len - movecnt; i++){
        int nowp = (i + len) % len;
        ans2.push_back(ans1[nowp]);
    }
    cout << ans2;
    return 0;
}