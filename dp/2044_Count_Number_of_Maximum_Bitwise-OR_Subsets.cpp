// 2022.05.31
// state enumerate
class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int mask = 1 << n;
        int max = 0;
        int res = 0;
        for(int state = 0; state < mask; state++) {
            int cur = 0;
            for(int i = 0; i < n; i++) {
                if(((state >> i) & 1) == 1) {
                    cur |= nums[i];
                }
            }
            if(cur > max) {
                max = cur;
                res = 1;
            }
            else if(cur == max) {
                res++;
            }
        }
        return res;
    }
};