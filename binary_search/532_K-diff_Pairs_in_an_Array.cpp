// 2022.06.16
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = 0;
        for(int i = 0; i < n; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1;
            int right = n - 1;
            int pos = -1;
            while(left <= right) {
                int mid = left + (right - left) / 2;
                if(nums[mid] - nums[i] > k) {
                    right = mid - 1;
                }
                else if(nums[mid] - nums[i] < k){
                    left = mid + 1;
                }
                else {
                    pos = mid;
                    break;
                }
            }
            res += pos == -1 ? 0 : 1;
        }
        return res;
    }
};