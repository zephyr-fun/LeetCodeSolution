// 2022.08.18
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> temp(32, 0);
        for(auto& num : nums) {
            for(int i = 31; i >= 0; i--) {
                if(num & (1 << i)) {
                    temp[i] = (temp[i] + 1) % 3;
                }
            }
        }
        int res = 0;
        for(int i = 0; i <= 31; i++) {
            if(temp[i]) {
                res |= 1 << i;
            }
        }
        return res;
    }
};