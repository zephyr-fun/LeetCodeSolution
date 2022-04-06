// 2022.04.06
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            count += nums[i];
            res = count > res ? count : res;
            if(count <= 0){
                count = 0;
            }
        }
        return res;
    }
};