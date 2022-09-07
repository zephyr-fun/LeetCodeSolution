// 2022.09.07
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        int pos = -1;
        while(left < right && nums[left] == nums[right]) {
            right--;
        }
        int temp = right;
        while(left <= right) {
            int mid = (left + right) >> 1;
            if(nums[mid] >= nums[0]) {
                left = mid + 1;
                pos = mid;
            }
            else {
                right = mid - 1;
            }
        }
        if(target >= nums[0]) {
            left = 0;
            right = pos;
        }
        else {
            left = pos + 1;
            right = temp;
        }
        while(left <= right) {
            int mid = (left + right) >> 1;
            if(nums[mid] > target) {
                right = mid - 1;
            }
            else if(nums[mid] < target){
                left = mid + 1;
            }
            else {
                return true;
            }
        }
        return false;
    }
};