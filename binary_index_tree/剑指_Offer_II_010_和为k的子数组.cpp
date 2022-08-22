// 2022.08.22
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> map;
        int cur = 0;
        int res = 0;
        map[0] = 1;
        for(int i = 0; i < n; i++) {
            cur += nums[i];
            if(map.count(cur - k)) {
                res += map[cur - k];
            }
            map[cur]++;
        }
        return res;
    }
};