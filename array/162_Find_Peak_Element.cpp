class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] > nums[mid + 1]) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return right;
    }
};

// 2023.01.03
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] > nums[mid + 1]) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return right;
    }
};

// 2023.03.05
class Solution {
public:
    int findPeakElement(vector<int>& nums_) {
        vector<int> nums;
        nums.emplace_back(INT_MIN);
        for(auto& num : nums_) {
            nums.emplace_back(num);
        }
        nums.emplace_back(INT_MIN);
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] < nums[mid + 1]) {
                left = mid + 1;
            }
            else if(nums[mid] < nums[mid - 1]){
                right = mid - 1;
            }
            else {
                return mid - 1;
            }
        }
        return -1;
    }
};