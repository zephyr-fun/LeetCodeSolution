// 2022.03.24
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        int left = leftBound(nums, target);
        int right = rightBound(nums, target);
        res.push_back(left);
        res.push_back(right);
        return res;
    }
    int leftBound(vector<int>& nums, int target){
        if(nums.size() == 0){
            return -1;
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
                //nums[mid] == target
                right = mid - 1; // lock the left bound, decrease right bound
            }
        }
        if(left >= nums.size() || nums[left] != target){
            return -1;
        }
        return left;
    }
    int rightBound(vector<int>& nums, int target){
        if(nums.size() == 0){
            return -1;
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
                //nums[mid] == target
                left = mid + 1; // lock the right bound, decrease left bound
            }
        }
        if(right < 0 || nums[right] != target){
            return -1;
        }
        return right;
    }
};