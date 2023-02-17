// 2022.08.09
class Solution {
public:
    int minStartValue(vector<int>& nums) {
		int n = nums.size();
        vector<int> diff(n, 0);
        diff[0] = nums[0];
        int res = diff[0];
        for(int i = 1; i < n; i++) {
            diff[i] = diff[i - 1] + nums[i];
            res = min(res, diff[i]);
        }
        return res >= 1 ? 1 : abs(res) + 1;
    }
};