// 2022.08.23
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        vector<int> presum(n + 1);
        presum[0] = 0;
        int res = 0x3f3f3f3f;
        for(int i = 0; i < n; i++) {
            presum[i + 1] = presum[i] + nums[i];
        }
        for(int i = 1; i <= n; i++) {
            int temp = presum[i] - target;
            int left = 0;
            int right = i - 1;
            int pos = -1;
            while(left <= right) {
                int mid = (left + right) >> 1;
                if(presum[mid] <= temp) {
                    pos = mid;
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
            if(pos != -1) {
                res = min(res, i - pos);
            }
        }
        return res == 0x3f3f3f3f ? 0 : res;
    }
};

// 2022.08.30
// double pointers
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int cur = 0;
        int res = 0x3f3f3f3f;
        while(right < n) {
            cur += nums[right];
            right++;
            while(left <= right && cur >= target) {
                res = min(res, right - left);
                cur -= nums[left];
                left++;
            }
        }
        return res == 0x3f3f3f3f ? 0 : res;
    }
};

// 2023.06.16
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = 0x3f3f3f3f;
        int left = 0;
        int right = 0;
        int n = nums.size();
        int cur = 0;
        while(right < n) {
            cur += nums[right];
            right++;
            while(left < right && cur >= target) {
                res = min(res, right - left);
                cur -= nums[left];
                left++;
            }
        }
        return res == 0x3f3f3f3f ? 0 : res;
    }
};