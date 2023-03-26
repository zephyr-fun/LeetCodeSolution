// 2022.09.04
class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_map<int, int> map;
        int n = nums.size();
        for(int i = 0; i < n - 1; i++) {
            map[nums[i] + nums[i + 1]]++;
            if(map[nums[i] + nums[i + 1]] > 1) {
                return true;
            }
        }
        return false;
    }
};

// 2023.03.26
class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_set<int> set;
        int cur = 0;
        for(int i = 0; i < nums.size() - 1; i++) {
            cur = nums[i] + nums[i + 1];
            if(set.count(cur)) {
                return true;
            }
            set.insert(cur);
        }
        return false;
    }
};