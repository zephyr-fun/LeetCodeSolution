// 2022.06.05
// sort + double pointer
class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = 0;
        int right = 0;
        int res = 0;
        while(left < n) {
            while(right < n && nums[right] - nums[left] <= k) {
                right++;
            }
            res++;
            left = right;
        }
        return res;
    }
};