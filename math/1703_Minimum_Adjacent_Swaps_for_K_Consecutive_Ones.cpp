// 2022.12.18
class Solution {
public:
    int minMoves(vector<int> &nums, int k) {
        vector<int> p;
        for(int i = 0; i < nums.size(); ++i) {
            if (nums[i]) p.push_back(i - p.size()); // p_i = q_i - idx
        }   
        int m = p.size();
        int s[m + 1];
        s[0] = 0;
        partial_sum(p.begin(), p.end(), s + 1); // p's presum
        int res = INT_MAX;
        for(int i = 0; i <= m - k; ++i) {
            // p[i] 到 p[i+k-1] 中所有数到 p[i+k/2] 的距离之和，取最小值
            res = min(res, s[i] + s[i + k] - s[i + k / 2] * 2 - p[i + k / 2] * (k % 2));
        } 
        return res;
    }
};