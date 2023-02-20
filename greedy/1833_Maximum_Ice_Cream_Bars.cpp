// 2023.02.20
// greedy & sort
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int res = 0;
        int n = costs.size();
        int idx = 0;
        while(idx < n && coins >= costs[idx]) {
            res++;
            coins -= costs[idx];
            idx++;
        }
        return res;
    }
};

// optim
