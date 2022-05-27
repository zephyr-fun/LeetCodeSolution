// 2022.05.27
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