// 2022.04.27
const int MAX_S1 = 12 + 1;
const int MAX_ALLS2 = 1 << 12;
int dp[MAX_S1][MAX_ALLS2];
class Solution {
    int INF = 0x3f3f3f3f;
public:
    int connectTwoGroups(vector<vector<int>>& cost) {
        memset(dp, 0x3f, sizeof(dp));
        int s1 = cost.size();
        int s2 = cost[0].size();
        int ALLs2 = (1 << s2) - 1; // s2 all set
        dp[0][0] = 0;
        for(int i = 0; i < s1; i++) {
            for(int j = 0; j <= ALLs2; j++) {
                if(dp[i][j] == INF) {
                    continue;
                }
                // case 1
                int not_connected = (~j) & ALLs2;
                int subset = not_connected;
                do {
                    if(subset == 0) {
                        break;
                    }
                    int nxt = subset | j; // new next state
                    int price = 0;
                    for(int k = 0; k < s2; k++) {
                        if((subset & (1 << k)) != 0) {
                            price += cost[i][k];
                        }
                    }
                    dp[i + 1][nxt] = min(dp[i + 1][nxt], dp[i][j] + price);
                    subset = (subset - 1) & not_connected;
                } while(subset != not_connected);
                // case 2
                for(int connected = 0; connected < s2; connected++) {
                    if((j & (1 << connected)) != 0) {
                        int price = cost[i][connected];
                        int nxt = j;
                        dp[i + 1][nxt] = min(dp[i + 1][nxt], dp[i][j] + price);
                    }
                }
            }
        }
        return dp[s1][ALLs2];
    }
};


// 2022.04.28
// kind of hard to understand
class Solution {
public:
    int connectTwoGroups(vector<vector<int>>& cost) {
        constexpr int inf = 0x3f3f3f3f;
        const int m = cost.size();
        const int n = cost[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(1 << n, inf));
        dp[0][0] = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                for(int s = 0; s < 1 << n; s++) {
                    dp[i + 1][s | (1 << j)] = min({dp[i + 1][s | (1 << j)], dp[i + 1][s] + cost[i][j], dp[i][s] + cost[i][j]});
                }
            }
        }
        return dp[m].back();
    }
};

// KM
class Solution {
public:    
    int link[15], visx[15], visy[15],lx[15],ly[15];
    int n, m;
    vector<vector<int>> w;
    Solution() : w(vector<vector<int>>(15, vector<int> (15))) {}
    int can(int t){
        visx[t] = 1;
        for(int i = 1; i <= m; i++){
            //这里“lx[t]+ly[i]==w[t][i]”决定了这是在相等子图中找增广路的前提，非常重要
            if(!visy[i] && lx[t] + ly[i] == w[t][i]){
                visy[i] = 1;
                if(link[i] == -1 || can(link[i])){
                    link[i] = t;
                    return 1;
                }
            }
        }
        return 0;
    }
    int km(){
        int sum = 0; memset(ly, 0, sizeof(ly));
        for(int i = 1; i <= n; i++){//把各个lx的值都设为当前w[i][j]的最大值
        lx[i] = INT_MIN;
        for(int j = 1; j <= n; j++){
            if(lx[i] < w[i][j])
                lx[i] = w[i][j];
            }
        }
        memset(link, -1, sizeof(link));
        for(int i = 1; i <= n; i++){
            while(1){
                memset(visx, 0, sizeof(visx));
                memset(visy, 0, sizeof(visy));
                if(can(i))//如果它能够形成一条增广路径，那么就break
                    break;
                int d = INT_MAX;//否则，后面应该加入新的边,这里应该先计算d值
                //对于搜索过的路径上的XY点，设该路径上的X顶点集为S，Y顶点集为T，对所有在S中的点xi及不在T中的点yj
                for(int j = 1; j <= n; j++)        
                    if(visx[j])
                    for(int k = 1; k <= m; k++)
                       if(!visy[k])
                            d = min(d, lx[j] + ly[k] - w[j][k]);
                if(d == INT_MAX)
                    return -1;//找不到可以加入的边，返回失败（即找不到完美匹配）
                for (int j = 1; j <= n; j++)
                    if (visx[j])
                        lx[j] -= d;
                for(int j = 1; j <= m; j++)
                    if(visy[j])
                        ly[j] += d;
                }
        }
        for(int i = 1; i <= m; i++)
            if(link[i] > -1)
                sum += w[link[i]][i];
        return sum;
    }
    int connectTwoGroups(vector<vector<int>>& cost) {
        n = cost.size();
        m = cost[0].size();
        int tn = n, tm = m;
        n = max(n, m);
        m = max(m, n);  //转换成方阵才能过    
        vector<int> lmin(tn + 1, INT_MAX), rmin(tm + 1, INT_MAX);
        for (int i = 1; i <= tn; ++i) {
            for (int j = 1; j <= tm; ++j) {
                lmin[i] = min(lmin[i], cost[i - 1][j - 1]);
                rmin[j] = min(rmin[j], cost[i - 1][j - 1]);
            }
        }
        int ans = accumulate(lmin.begin() + 1, lmin.end(), 0) + accumulate(rmin.begin() + 1, rmin.end(), 0);
        for (int i = 1; i <= tn; ++i) {
            for (int j = 1; j <= tm; ++j) {
                w[i][j] = max(0 , lmin[i] + rmin[j] - cost[i - 1][j - 1]);
            }
        }
        return ans - km();
    }
};