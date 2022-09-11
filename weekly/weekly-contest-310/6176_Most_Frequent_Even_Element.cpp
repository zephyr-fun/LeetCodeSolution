// 2022.09.11
class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int res = -1;
        int maxVal = 0;
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] & 1) {
                continue;
            }
            map[nums[i]]++;
        }
        for(auto [k, v] : map) {
            if(v > maxVal) {
                res = k;
                maxVal = v;
            }
            else if(v == maxVal) {
                res = min(res, k);
            }
        }
        return res;
    }
};