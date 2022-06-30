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

// 2022.04.16
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = leftBound(nums, target);
        int right = rightBound(nums, target);
        return {left, right};
    }
    int leftBound(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] < target) {
                left = mid + 1;
            }
            else if(nums[mid] > target) {
                right = mid - 1;
            }
            else {
                right = mid - 1; // find left bound
            }
        }
        if(left >= nums.size() || nums[left] != target) { // insure
            return -1;
        }
        return left;
    }
    int rightBound(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] < target) {
                left = mid + 1;
            }
            else if(nums[mid] > target) {
                right = mid - 1;
            }
            else {
                left = mid + 1; // find right bound
            }
        }
        if(right < 0 || nums[right] != target) { // insure
            return -1;
        }
        return right;
    }
};

// 2022.06.30
class Solution {
public:
    int lower(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int res = -1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] > target) {
                right = mid - 1;
            }
            else if(nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
                res = mid;
            }
        }
        return res;
    }

    int upper(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int res = -1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] > target) {
                right = mid - 1;
            }
            else if(nums[mid] < target) {
                left = mid + 1;
            }
            else {
                left = mid + 1;
                res = mid;
            }
        }
        return res;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = lower(nums, target);
        int up = upper(nums, target);
        return {low, up};
    }
};