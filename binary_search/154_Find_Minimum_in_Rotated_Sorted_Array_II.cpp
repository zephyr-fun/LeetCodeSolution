// 2022.08.28
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        int pos = 0;
        while(right >= 0 && nums[right] == nums[0]) {
            right--;
        }
        while(left <= right) {
            int mid = (left + right) >> 1;
            if(nums[mid] < nums[0]) {
                pos = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return nums[pos];
    }
};

// 
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        while(left < right) {
            int mid = (left + right) >> 1;
            if(nums[mid] < nums[right]) {
                right = mid;
            }
            else if(nums[mid] > nums[right]){
                left = mid + 1;
            }
            else {
                right--;
            }
            // cout << left << right << endl;
        }
        return nums[left];
    }
};

// 2022.11.21
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        int pos = 0;
        while(right >= 0 && nums[right] == nums[0]) {
            right--;
        }
        while(left <= right) {
            int mid = (left + right) >> 1;
            if(nums[mid] < nums[0]) {
                pos = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return nums[pos];
    }
};

// 