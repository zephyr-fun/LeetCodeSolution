// 2022.10.27
class Solution {
public:
    int arraySign(vector<int>& nums) {
        int nega = 0;
        int n = nums.size();
        for(auto& num : nums) {
            if(num == 0) {
                return 0;
            }
            nega += num < 0 ? 1 : 0;
        }
        return nega % 2 ? -1 : 1;
    }
};