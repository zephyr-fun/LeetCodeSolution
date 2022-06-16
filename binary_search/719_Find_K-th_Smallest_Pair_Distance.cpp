// 2022.06.16
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = 0;
        int right = 1e6;
        int len = -1; // own flag
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(check(nums, mid) >= k) {
                right = mid - 1;
            }
            else {
                len = mid;
                left = mid + 1;
            }
        }
        return len;
    }
    int check(vector<int>& nums, int len) {
        int n = nums.size();
        int res = 0;
        for(int i = 0, j = 1; i < n; i++) {
            while(j < n && nums[j] - nums[i] < len) {
                j++;
            }
            res += j - i - 1;
        }
        return res;
    }
};