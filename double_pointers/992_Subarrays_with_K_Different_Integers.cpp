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

// 2022.12.03
class Solution {
public:
    int lessThan(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int n = nums.size();
        int l = 0;
        int r = 0;
        int res = 0;
        while(r < n) {
            map[nums[r]]++;
            r++;
            while(l < r && map.size() > k) {
                map[nums[l]]--;
                if(map[nums[l]] == 0) {
                    map.erase(nums[l]);
                }
                l++;
            }
            res += r - l;
        }
        return res;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return lessThan(nums, k) - lessThan(nums, k - 1);
    }
};

// subject to "1 <= nums[i], k <= nums.length"
// so we can optim unordered_map with vector<int>