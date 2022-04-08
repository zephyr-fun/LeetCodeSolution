// 2022.04.08
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < 32; i++){
            int mask = 1 << i;
            int cnt = 0;
            for(int j = 0; j < nums.size(); j++){
                if(nums[j] & mask){// remove != 0
                    cnt++;
                }
            }
            if(cnt % 3 != 0){
                res |= mask;
            }
        }
        return res;
    }
};

// ^
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0;
        for (auto x : nums) {
            b = (b ^ x) & ~a;
            a = (a ^ x) & ~b;
        }
        return b;
    }
};