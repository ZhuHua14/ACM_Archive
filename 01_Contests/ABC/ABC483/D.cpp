//D - Glitchy Robot
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

/*1.对A做前缀和可以得到机器人的当前坐标
  2.答案是前缀和里的最大 - 前缀和里的最小
  3.修改一个数的正负号相当于对后面的数同时做+ / - 2 * a[i]
  4.对于一个数列，从中间劈开，给前面/后面同时加/减一个数，
    最大和最小仍然只会在前面的最大和最小，后面的最大和最小之间产生。

    slu: 对前缀和建最大最小两个ST表，
         暴力的维护每个数字反号时的最大最小并统计答案;
*/

//test

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    return 0;
}