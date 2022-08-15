// 2022.08.07 contest 2022.08.15 update
class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int res = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(nums[j] - nums[i] == diff) {
                    for(int k = j + 1; k < n; k++) {
                        if(nums[k] - nums[j] == diff) {
                            res++;
                        }
                    }
                }
            }
        }
        return res;
    }
};