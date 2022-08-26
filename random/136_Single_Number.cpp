// 2022.04.08
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(auto num : nums){
            res ^= num;
        }
        return res;
    }
};

// 2022.08.26
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(auto& num : nums) {
            res ^= num;
        }
        return res;
    }
};