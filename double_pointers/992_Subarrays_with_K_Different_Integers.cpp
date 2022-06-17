// 2022.05.27
// Convert "exactly k" to "at most k" - "at most k-1"
https://leetcode.cn/problems/subarrays-with-k-different-integers/solution/k-ge-bu-tong-zheng-shu-de-zi-shu-zu-by-l-ud34/
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostDistinct(nums, k) - atMostDistinct(nums, k - 1);
    }
    int atMostDistinct(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int count = 0;
        int size = nums.size();
        int res = 0;
        vector<int> freq(size + 1, 0);
        while(right < size) {
            if(freq[nums[right]] == 0) {
                count++;
            }
            freq[nums[right]]++;
            right++;
            while(count > k) {
                freq[nums[left]]--;
                if(freq[nums[left]] == 0) {
                    count--;
                }
                left++;
            }
            res += right - left;
        }
        return res;
    }
};

// 2022.06.17
// at most - at most = exactly
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostKDistinct(nums, k) - atMostKDistinct(nums, k - 1);
    }
    int atMostKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        int left = 0;
        int right = 0;
        int res = 0;
        vector<int> freq(n + 1, 0);
        while(right < n) {
            if(freq[nums[right]] == 0) {
                cnt++;
            }
            freq[nums[right]]++;
            while(left <= right && cnt > k) {
                freq[nums[left]]--;
                if(freq[nums[left]] == 0) {
                    cnt--;
                }
                left++;
            }
            res += right - left + 1;
            right++;
        }
        return res;
    }
};