// 2022.08.04
class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int& a, int& b) {
            return a > b;
        });
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
        }
        vector<int> res;
        int temp = 0;
        for(auto num : nums) {
            if(temp <= sum / 2) {
                temp += num;
                res.emplace_back(num);
            }
            else {
                break;
            }
        }
        return res;
    }
};