// 2022.10.16
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_set<int> set;
        int res = -1;
        for(auto& num : nums) {
            if(num > 0) {
                if(set.count(-num)) {
                    res = max(res, num);
                }
            }
            else {
                set.insert(num);
            }
        }
        return res;
    }
};