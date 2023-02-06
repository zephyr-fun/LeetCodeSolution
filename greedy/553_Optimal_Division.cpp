// 2023.02.06
class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) {
            return to_string(nums[0]);
        }
        if(n == 2) {
            return to_string(nums[0]) + "/" + to_string(nums[1]);
        }
        string res = "";
        for(int i = 0; i < n; i++) {
            res += to_string(nums[i]);
            if(i != n - 1) {
                res += "/";
            }
            if(i == 0) {
                res += "(";
            }
            if(i == n - 1) {
                res += ")";
            }
        }
        return res;
    }
};