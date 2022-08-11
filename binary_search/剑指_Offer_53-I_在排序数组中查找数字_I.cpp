// 2022.08.11
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        int posl = -1;
        int posr = -1;
        while(left <= right) {
            int mid = (left + right) >> 1;
            if(nums[mid] < target) {
                left = mid + 1;
            }
            else if(nums[mid] > target) {
                right = mid - 1;
            }
            else {
                posl = mid;
                right = mid - 1;
            }
        }
        left = 0;
        right = n - 1;
        while(left <= right) {
            int mid = (left + right) >> 1;
            if(nums[mid] < target) {
                left = mid + 1;
            }
            else if(nums[mid] > target) {
                right = mid - 1;
            }
            else {
                posr = mid;
                left = mid + 1;
            }
        }
        if(posl == -1) {
            return 0;
        }
        return posr - posl + 1;
    }
};