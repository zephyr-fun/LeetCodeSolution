// 2022.12.05
// optim residual
// class Solution {
// public:
//     int lastStoneWeight(vector<int>& stones) {
//         int n = stones.size();
//         int sum = accumulate(stones.begin(), stones.end(), 0);
//         int target = sum / 2;
//         vector<int> dp(target + 1, 0);
//         for(int i = 0; i < n; i++) {
//             for(int j = target; j >= stones[i]; j--) {
//                 dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
//             }
//         }
//         cout << dp[target];
//         return sum - 2 * dp[target];
//     }
// };
// by rules
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>, less<int>> pque;
        for(auto& stone : stones) {
            pque.push(stone);
        }
        while(pque.size() >= 2) {
            int a = pque.top();
            pque.pop();
            int b = pque.top();
            pque.pop();
            int c = abs(a - b);
            if(c != 0) {
                pque.push(c);
            }
        }
        return pque.size() ? pque.top() : 0;
    }
};