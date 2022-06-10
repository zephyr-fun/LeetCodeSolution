// 2022.06.10
class Solution {
public:
    int bestRotation(vector<int>& nums) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);
        int res = 0;
        for(int i = 0; i < n; i++) {
            int bound1 = (i - (n - 1) + n) % n;
            int bound2 = (i - nums[i] + n) % n;
            if(bound1 <= bound2) {
                diff[bound1]++;
                diff[bound2 + 1]--;
            }
            else {
                diff[bound1]++;
                diff[n]--;
                diff[0]++;
                diff[bound2 + 1]--;
            }
        }
        for(int i = 1; i < n; i++) {
            diff[i] += diff[i - 1];
        }
        for(int i = 0; i < n; i++) {
            if(diff[i] > diff[res]) {
                res = i;
            }
        }
        return res;
    }
};