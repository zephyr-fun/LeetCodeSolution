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