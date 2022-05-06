// 2022.05.05
// memory search
class Solution {
public:
    int mod = 1000000007;
    int cache[105][205];
    int size;
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        size = locations.size();
        memset(cache, -1, sizeof(cache));
        return dfs(locations, start, finish, fuel);
    }
    int dfs(vector<int>& locations, int start, int finish, int fuel) {
        // if we already searched the sub task, return results
        if(cache[start][fuel] != -1) {
            return cache[start][fuel];
        }
        // if we run out of the fuel, and we are not at the finish point
        if(fuel == 0 && start != finish) {
            cache[start][fuel] = 0;
            return 0;
        }
        // if we still have fuel, but can't go any where
        bool hasNext = false;
        for(int i = 0; i < locations.size(); i++) {
            if(i != start) {
                if(abs(locations[i] - locations[start]) <= fuel) {
                    hasNext = true;
                    break;
                }
            }
        }
        if(fuel != 0 && !hasNext) {
            int remain = cache[start][fuel] = start == finish ? 1 : 0;
            return remain;
        }
        // if we are already at the finish point, conut 1
        int sum = start == finish ? 1 : 0;
        for(int i = 0; i < size; i++) {
            if(i != start) {
                if(abs(locations[i] - locations[start]) <= fuel) {
                    sum += dfs(locations, i, finish, fuel - abs(locations[i] - locations[start]));
                    sum %= mod;
                }
            }
        }
        cache[start][fuel] = sum;
        return sum;
    }
};

class Solution {
public:
    int mod = 1000000007;
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int size = locations.size();
        // dp[i][j] refers to the maximum path to get to the finish point at pos i, with rest j fuel
        vector<vector<int>> dp(size, vector<int>(fuel + 1, 0));
        for(int j = 0; j <= fuel; j++) {
            dp[finish][j] = 1;
        }
        // 从状态转移方程可以发现 f[i][fuel]=f[i][fuel]+f[k][fuel-need]
        // 在计算 f[i][fuel] 的时候依赖于 f[k][fuel-need]
        // 其中 i 和 k 并无严格的大小关系
        // 而 fuel 和 fuel-need 具有严格大小关系：fuel >= fuel-need
        // 因此需要先从小到大枚举油量
        for(int j = 0; j <= fuel; j++) {
            for(int i = 0; i < size; i++) {
                for(int k = 0; k < size; k++) {
                    if(i != k) {
                        if(abs(locations[i] - locations[k]) <= j) {
                            dp[i][j] += dp[k][j - abs(locations[i] - locations[k])];
                            dp[i][j] %= mod;
                        }
                    }
                }
            }
        }
        return dp[start][fuel];
    }
};