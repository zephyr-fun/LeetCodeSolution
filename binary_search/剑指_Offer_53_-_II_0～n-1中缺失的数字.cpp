// 2022.08.11
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        int pos = -1;
        while(left <= right) {
            int mid = (left + right) >> 1;
            if(nums[mid] == mid) {
                pos = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return pos + 1;
    }
};