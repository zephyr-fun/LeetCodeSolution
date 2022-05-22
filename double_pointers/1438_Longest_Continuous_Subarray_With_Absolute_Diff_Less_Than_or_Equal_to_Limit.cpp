// 2022.05.22
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        int res = 0;
        deque<int> maxQue;
        deque<int> minQue;
        for(int left = 0, right = 0; right < n; right++) {
            while(!maxQue.empty() && maxQue.back() < nums[right]) {
                maxQue.pop_back();
            }
            while(!minQue.empty() && minQue.back() > nums[right]) {
                minQue.pop_back();
            }
            maxQue.push_back(nums[right]);
            minQue.push_back(nums[right]);
            while(!maxQue.empty() && !minQue.empty() && maxQue.front() - minQue.front() > limit) {
                if(maxQue.front() == nums[left]) {
                    maxQue.pop_front();
                }
                if(minQue.front() == nums[left]) {
                    minQue.pop_front();
                }
                left++;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};