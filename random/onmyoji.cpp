#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int INF = 0x3f3f3f3f;
int n, len[10];

struct node {
    int c;
    int d;
}op[10][35]; // 装备库

int dp[7][200]; // 当前i种御魂，达成j暴击率的最大暴击伤害
int f[33][200];

void solve(){
    cin >> n;
    memset(dp, -1, sizeof(dp));
    memset(len, 0, sizeof(len)); // 记录每种装备有多少个
    for(int i = 0; i <= 6; i++) {
        dp[i][0] = 0; // 暴击率为0时，暴伤设置为0，方便转移
    }
    int type, cc, dd;
    for(int i = 1; i <= n; i++) {
        cin >> type >> cc >> dd;
        op[type][++len[type]] = {cc, dd};
    }

    for(int i = 1; i <= 6; i++){
        memset(f, -1, sizeof(f));

        for(int j = 1; j <= len[i]; j++){
            for(int k = 150; k >= op[i][j].c; k--){
                if(dp[i - 1][k - op[i][j].c] >= 0) {
                    f[j][k] = max(f[j][k], dp[i - 1][k - op[i][j].c] + op[i][j].d);
                }
            }
        // dp[i][k] = max(dp[i][k], dp[i-1][k-op[i][j].c] + op[i][j].d);
        }
        for(int k = 0; k <= 150; k++) dp[i][k] = dp[i - 1][k];
        for(int k = 0; k <= 150; k++){
            for(int j = 1; j <= len[i]; j++){
                dp[i][k] = max(dp[i][k], f[j][k]);
            }
            //   if(k<=24) cout<<dp[i][k]<<' ';
        }
    //  cout<<endl;
    }
    int ans = -1;
    for(int k = 100; k <= 150; k++) ans = max(ans, dp[6][k]);
    if(ans == -1) cout << "TAT" << endl;
    else cout << ans << endl;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}

// c++
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
struct node{
    int bao;
    int shang;
};
int res;
// 暴力解法过70%
int dfs(int pos, int all_bao, int all_shang, vector<vector<node> > &v){
    if(pos == 7){
        if(all_bao >= 100) res = max(res, all_shang);
        return 0;
    }
    for(int i = 0; i < int(v[pos].size()); i++){
        dfs(pos + 1, all_bao + v[pos][i].bao, all_shang + v[pos][i].shang, v);
    }
}
// 背包 100%
void bag(vector<vector<node> > &v){
    int capacity = 0;// 所有可能中配出装备的最大的暴击率为容量
    for(int i = 1; i <= 6; ++i){
        int tmp = 0;
        for(auto n : v[i])
            tmp = max(tmp, n.bao);
        capacity += tmp;
    }
    int dp[8][200];
    // 背包必须恰好装满，除背包容量为0时的伤害为0外，所有初始化为负无穷
    for(int i = 0; i <= 6; ++i){
        fill(dp[i], dp[i] + capacity + 1, -0x3f3f3f3f);
        dp[i][0] = 0;
    }
    for(int i = 1; i <= 6; ++i){
        for(auto n : v[i]){
            for(int j = 1; j <= capacity; ++j){
                if(j >= n.bao && dp[i - 1][j - n.bao] != -0x3f3f3f3f)
                    dp[i][j] = max(dp[i - 1][j], max(dp[i][j], dp[i - 1][j - n.bao] + n.shang));
                else dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            }
        }
    }
    // 从100到capacity的背包中选择出最大伤害
    for(int j = 100; j <= capacity; ++j)
        if(dp[6][j] > res) res = dp[6][j];
    return ;
}
int main(){
    int t, n;
    scanf("%d", &t);
    vector<vector<node> > v;
    for(int i = 0; i < 7; ++i) v.push_back(*new vector<node>);
    while(t--){
        scanf("%d", &n);
        for(int i = 0; i < n; ++i){
            int pos;
            node tmp;
            scanf("%d%d%d", &pos, &(tmp.bao), &(tmp.shang));
            v[pos].push_back(tmp);
        }
        res = -1;
        dfs(1, 0, 0, v);
        if(res == -1) printf("TAT\n");
        else printf("%d\n", res);
        for(int i = 1; i < 7; ++i) v[i].clear();
    }
    return 0;
}
//2
//12
//1 12 6
//1 14 10
//2 22 3
//2 3 38
//3 24 1
//3 3 15
//3 11 23
//4 13 2
//5 19 10
//5 17 11
//5 16 2
//6 20 2
//11
//1 14 16
//1 17 3
//2 6 32
//3 3 24
//4 12 3
//4 13 0
//5 22 5
//5 21 4
//6 3 37
//6 14 6
//6 23 0