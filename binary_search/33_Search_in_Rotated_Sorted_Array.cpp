// 2022.07.12
// change original vector
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        while(left <= right) {
            int mid = (left + right) >> 1;
            if(nums[mid] == target) {
                return mid;
            }
            if(target >= nums[0]) {
                if(nums[mid] < nums[0]) {
                    nums[mid] = 0x3f3f3f3f;
                }
            }
            else {
                if(nums[mid] >= nums[0]) {
                    nums[mid] = -0x3f3f3f3f;
                }
            }
            if(nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return -1;
    }
};

// first find out Dividing Point
// second subarea binary search
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int pos = -1;
        int l = 0;
        int r = nums.size() - 1;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(nums[mid] >= nums[0]) {
                l = mid + 1;
                pos = mid;
            }
            else {
                r = mid - 1;
            }
        }
        if(target >= nums[0]) {
            l = 0;
            r = pos;
        }
        else {
            l = pos + 1;
            r = nums.size() - 1;
        }
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(nums[mid] == target) {
                return mid;
            }
            else if(nums[mid] > target) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return -1;
    }
};

// 2022.07.21
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        int pos = -1;
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
            right = n - 1;
        }
        while(left <= right) {
            int mid = (left + right) >> 1;
            if(nums[mid] == target) {
                return mid;
            }
            else if(nums[mid] < target){
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return -1;
    }
};