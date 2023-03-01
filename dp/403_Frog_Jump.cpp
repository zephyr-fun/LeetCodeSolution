// 2023.03.01
// limitation on stones[i] may cause the mapping to exceed the range of int
// so the mapping here use the form of (auto key = to_string(cur) + "_" + to_string(step))
class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_set<int> set;
        for(auto& stone : stones) {
            set.insert(stone);
        }
        unordered_map<string, bool> dp;
        function<bool(int, int)> dfs = [&] (int cur, int step) {
            auto key = to_string(cur) + "_" + to_string(step);
            if(dp.count(key)) {
                return dp[key];
            }
            if(cur == stones.back()) {
                return true;
            }
            for(int i = -1; i <= 1; i++) {
                if(step + i == 0) {
                    continue;
                }
                int next = cur + step + i;
                if(set.count(next)) {
                    dp[key] = dfs(next, step + i);
                    if(dp[key]) {
                        return true;
                    }
                }
            }
            dp[key] = false;
            return false;
        };
        if(!set.count(1)) {
            return false;
        }
        return dfs(1, 1);
    }
};

// cola version to overcome the mapping limitation
// class Solution {
// public:
//     bool canCross(vector<int>& stones) {
//         int n = stones.size();
//         if(stones[1] != 1) return false;
//         map<int,int> mp;
//         map<int,bool> f; //记忆化cache
//         for(int i = 0; i < n; i++) mp[stones[i]] = i;

//         std::function<bool(int,int)> dfs = [&](int idx,int k){
//             auto key = idx * 10000 + k; //key值可以这样映射
//             if(f.count(key)) return f[key];
//             if(idx == n - 1) return true;
//             for(int i = -1; i <= 1; i++){
//                 if(k + i == 0) continue;
//                 int next = stones[idx] + k + i;
//                 if(mp.count(next)){
//                     bool cur = dfs(mp[next],k + i);
//                     f[key] = cur; 
//                     if(cur) return true;
//                 }
//             }
//             f[key] = false;
//             return false;
//         };
        
//         return dfs(1,1);
//     }
// };

// dp
class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if(stones[1] != 1) {
            return false;
        }
        bool dp[2021][2021];
        memset(dp, false, sizeof(dp));
        dp[1][1] = true;
        for(int i = 2; i < n; i++) {
            for(int j = 1; j < i; j++) {
                int k = stones[i] - stones[j];
                if(k <= j + 1) {
                    dp[i][k] = dp[j][k - 1] || dp[j][k] || dp[j][k + 1];
                }
            }
        }
        for(int i = 1; i < n; i++) {
            if(dp[n - 1][i]) {
                return true;
            }
        }
        return false;
    }
};