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

// 2022.06.10
// maxQue && minQue && order
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxQue;
        deque<int> minQue;
        int n = nums.size();
        int res = 0;
        for(int left = 0, right = 0; right < n; right++) {
            while(!maxQue.empty() && nums[right] > maxQue.back()) {
                maxQue.pop_back();
            }
            maxQue.push_back(nums[right]);
            while(!minQue.empty() && nums[right] < minQue.back()) {
                minQue.pop_back();
            }
            minQue.push_back(nums[right]);
            while(left <= right && maxQue.front() - minQue.front() > limit) {
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

// multiset, already ordered
// diff between set and multiset
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> set;
        int n = nums.size();
        int res = 0;
        int left = 0;
        int right = 0;
        while(right < n) {
            set.insert(nums[right]);
            while(left <= right && *set.rbegin() - *set.begin() > limit) {//*set.rbegin() - *set.begin()
                set.erase(set.find(nums[left]));
                left++;
            }
            res = max(res, right - left + 1);
            right++;
        }
        return res;
    }
};