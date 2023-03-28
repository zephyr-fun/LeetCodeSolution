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

// 2023.03.28
// 原地标记法，利用原数组的nums[i]->(1, n)性质，将其作为一个vis[n]标记数组
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        for(int i = 0; i < n; i++) {
            // 判断标记
            if(nums[abs(nums[i]) - 1] < 0) {
                res.emplace_back(abs(nums[i]));
            }
            // 做标记
            else {
                nums[abs(nums[i]) - 1] *= -1;
            }
        }
        return res;
    }
};