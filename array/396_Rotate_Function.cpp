// sliding window
// 2022.05.26
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int cur = 0;
        vector<int> rotateNums(2 * n, 0);
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            cur += nums[i] * i;
            rotateNums[i] = nums[i];
            rotateNums[i + n] = nums[i];
        }
        int maxNow = cur;
        for(int i = 1; i < n; i++) {
            cur -= (sum - nums[i - 1]);
            cur += nums[i - 1] * (n - 1);
            maxNow = max(cur, maxNow);
        }
        return maxNow;
    }
};