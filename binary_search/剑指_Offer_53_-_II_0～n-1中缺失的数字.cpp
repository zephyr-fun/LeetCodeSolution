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

// 2022.08.27
// inplace hash
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; ) {
            if(nums[i] >= 0 && nums[i] < n && nums[i] != nums[nums[i]]) {
                int idx = nums[i];
                int temp = nums[idx];
                nums[idx] = nums[i];
                nums[i] = temp;
            }
            else {
                i++;
            }
        }
        for(int i = 0; i < n; i++) {
            if(nums[i] != i) {
                return i;
            }
        }
        return n;
    }
};

// binary search
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
                left = mid + 1;
            }
            else {
                pos = mid;
                right = mid - 1;
            }
        }
        return pos == -1 ? n : pos;
    }
};