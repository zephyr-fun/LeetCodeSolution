// 2022.12.04
// dfs
class Solution {
public:
    void dfs(vector<int>& toppingCosts, int p, int cur, int& res, int target) {
        if(abs(res - target) < cur - target) { // why not abs(cur - target)? because when cur is less than target, there exists the possibility that cur can be more closer to target
            return ;
        }
        else if(abs(res - target) >= abs(cur - target)) {
            if(abs(res - target) > abs(cur - target)) {
                res = cur;
            }
            else {
                res = min(res, cur);
            }
        }
        if(p == toppingCosts.size()) {
            return ;
        }
        dfs(toppingCosts, p + 1, cur + toppingCosts[p] * 2, res, target);
        dfs(toppingCosts, p + 1, cur + toppingCosts[p], res, target);
        dfs(toppingCosts, p + 1, cur, res, target);
    }
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int res = *min_element(baseCosts.begin(), baseCosts.end());
        for(auto& b : baseCosts) {
            dfs(toppingCosts, 0, b, res, target);
        }
        return res;
    }
};

// dp
