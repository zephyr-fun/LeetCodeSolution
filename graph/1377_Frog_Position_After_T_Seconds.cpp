// 2023.05.24
// https://leetcode.cn/problems/frog-position-after-t-seconds/solution/dfs-ji-yi-ci-you-qu-de-hack-by-endlessch-jtsr/
// 自顶向下，减少一些不必要的访问
class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> g(n + 1);
        g[1] = {0};
        for(auto& e : edges) {
            g[e[0]].emplace_back(e[1]);
            g[e[1]].emplace_back(e[0]);
        }
        double res = 0;
        function<bool(int, int, int, long long)> dfs = [&] (int x, int fa, int left, long long prod) -> bool {
            if(x == target && (left == 0 || g[x].size() == 1)) {
                res = 1.0 / prod;
                return true;
            }
            if(x == target || left == 0) {
                return false;
            }
            for(int y : g[x]) {
                if(y != fa && dfs(y, x, left - 1, prod * (g[x].size() - 1))) {
                    return true;
                }
            }
            return false;
        };
        dfs(1, 0, t, 1);
        return res;
    }
};

// 自底向上，减少一些乘积计算
class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> g(n + 1);
        g[1] = {0};
        for(auto& e : edges) {
            g[e[0]].emplace_back(e[1]);
            g[e[1]].emplace_back(e[0]);
        }
        function<long long(int, int, int)> dfs = [&] (int x, int fa, int left) -> long long {
            // t秒后恰好到达或者是叶子节点，返回的0或者1相当于判断是否找到了target
            if(left == 0) {
                return x == target;
            }
            if(x == target) {
                return g[x].size() == 1;
            }
            // 继续在x的儿子中找target
            for(int y : g[x]) {
                if(y != fa) {
                    // prod即为一个标志位
                    auto prod = dfs(y, x, left - 1);
                    // 如果找到了，开始返回乘积
                    if(prod) {
                        return prod * (g[x].size() - 1);
                    }
                }
            }
            return 0;
        };
        auto prod = dfs(1, 0, t);
        return prod ? 1.0 / prod : 0;
    }
};