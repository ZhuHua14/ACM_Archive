#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;

int pi[2 * MAXN];
string mode,mmain;

void make_pi(string s){
    int j = 0,maxsize = s.size();
    pi[0] = 0;
    for (int i = 1; i < maxsize; i++) {
        //j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
}

int ans[MAXN],cnt = 0;

void kmp1(string text,string patton){
    string findstr = patton + "#" + text;
    make_pi(findstr);
    int modesize = patton.size(),from = patton.size() + 1,to = findstr.size();
    for(int i = from; i < to; i++){
        if(pi[i] == modesize){
            ans[++cnt] = i - from - modesize + 2;
        }
    }
}

void kmp2(string text,string patton){
    make_pi(patton);
    memset(ans,0,sizeof(ans));
    cnt = 0;
    int maxsize = text.size(),j = 0,modesize = patton.size();
    for(int i = 0;i < maxsize; i++){
        while(j > 0 && patton[j] != text[i]) j = pi[j - 1];
        if(text[i] == patton[j]) j++;
        if(j == modesize){
            ans[++cnt] = i - modesize + 2;
        }
    }
}
int main(){
    cin >> mmain >> mode;
    kmp2(mmain,mode);
    for(int i = 1; i <= cnt; i++){
        cout << ans[i] << '\n';
    }
    for(int i = 0; i < mode.size(); i++){
        cout << pi[i] << ' ';
    }
    return 0;
}