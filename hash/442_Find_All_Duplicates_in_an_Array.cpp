// 2022.05.08
// in place hash
// num belongs to [1, n], index belongs to [0, n - 1]
// mark the number[index] the first time you visit num, (num = index + 1)
// next time you will find the mark, then push it into the res vector
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for(auto num : nums) {
            if(nums[abs(num) - 1] < 0) {
                res.push_back(abs(num));
            }
            else {
                nums[abs(num) - 1] *= -1;
            }
        }
        return res;
    }
};