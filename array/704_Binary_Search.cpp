// 2022.03.24
// recursion
class Solution {
public:
    int res = -1;
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0){
            return res;
        }
        binarySearch(nums, target, 0, nums.size() - 1);
        return res;
    }
    void binarySearch(vector<int>& nums, int target, int low, int high){
        if(low > high){
            return;
        }
        int mid = low + (high - low) / 2;
        if(nums[mid] > target){
            binarySearch(nums, target, low, mid - 1);
        }
        else if(nums[mid] < target){
            binarySearch(nums, target, mid + 1, high);
        }
        else{
            res = mid;
        }
    }
};
// non recursion
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int res = -1;
        if(nums.size() == 0){
            return res;
        }
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] > target){
                right = mid - 1;
            }
            else if(nums[mid] < target){
                left = mid + 1;
            }
            else{
                // nums[mid] == target
                return mid;
            }
        }
        return res;
    }
};