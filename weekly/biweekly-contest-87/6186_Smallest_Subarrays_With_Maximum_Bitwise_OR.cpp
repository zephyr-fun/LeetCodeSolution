// 2022.09.17
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        vector<int> bit(32, -1);
        for(int i = n - 1; i >= 0; i--) {
            for(int j = 0; j < 32; j++) {
                if(nums[i] & (1 << j)) {
                    bit[j] = i;
                }
            }
            int last = i;
            for(int j = 0; j < 32; j++) {
                last = max(last, bit[j]);
            }
            res.emplace_back(last - i + 1);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};