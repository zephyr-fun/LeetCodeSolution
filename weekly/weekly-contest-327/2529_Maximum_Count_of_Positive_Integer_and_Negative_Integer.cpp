// 2023.01.08
// normal O(n)
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos = 0;
        int neg = 0;
        for(auto& num : nums) {
            if(num > 0) {
                pos++;
            }
            else if(num < 0) {
                neg++;
            }
        }
        return max(pos, neg);
    }
};

// binary search
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        int mid;
        if(nums[left] > 0 || nums[right] < 0) {
            return n;
        }
        while(left <= right) {
            mid = left + (right - left) / 2;
            if(nums[mid] < 0) {
                left = mid + 1;
            }
            else if(nums[mid] > 0) {
                right = mid - 1;
            }
            else {
                break;
            }
        }
        if(!nums[mid]) {
            left = mid - 1;
            right = mid + 1;
            while(left >= 0 && nums[left] == 0) {
                left--;
            }
            while(right < n && nums[right] == 0) {
                right++;
            }
            return max(left + 1, n - right);
        }
        return max(right + 1, n - left);
    }
};