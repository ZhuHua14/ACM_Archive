//C - Second Choice Election
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;
struct Noters{
    int a, b;
};
vector<Noters> noter[MAXN];

int n, m, max1 = 0, max2 = 0, maxv, tmp1, bot[MAXN];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    Noters tmp;
    for(int i = 1; i <= m; i++){
        cin >> tmp.a >> tmp.b;
        bot[tmp.a]++;
        noter[tmp.a].push_back(tmp);
    }
    // for(int i = 1; i <= n; i++){
    //     ////cerr << bot[i] << ' ';
    // }
    // ////cerr << '\n';1
    for(int i = 1; i <= n; i++){
        if(bot[i] > bot[max1]) max1 = i;
    }
    for(int i = 1; i <= n; i++){
        if(i != max1 && bot[i] <= bot[max1] && bot[i] > bot[max2]) max2 = i;
    }
    for(int i = 1; i <= n; i++){
        tmp1 = ((i == max1) ?  max2 : max1);
        maxv = bot[tmp1];    
        for(auto note : noter[i]){
            bot[note.b]++;
            if(bot[note.b] > maxv || (bot[note.b] == maxv && note.b < tmp1)){
                maxv = bot[note.b];
                tmp1 = note.b;
            }
            //cerr << tmp1 << ' ';
        }

        cout << tmp1;
        for(auto note : noter[i]){
            bot[note.b]--;
        }
        cout << '\n';
        //cerr << '\n';
    }
    return 0;
}