// 2022.07.31
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int step = 1;
        sort(nums.begin(), nums.end());
        int i = 0;
        while(i < n && nums[i] == 0) {
            i++;
        }
        if(i >= n) {
            return 0;
        }
        int sum = nums[i];
        i++;
        while(i < n && sum < nums[nums.size() - 1]) {
            if(nums[i] - nums[i - 1] > 0) {
                sum += nums[i] - nums[i - 1];
                step++;
            }
            
            i++;
        }
        return step;
    }
};

// optim
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> set;
        for(auto num : nums) {
            if(num != 0) {
                set.insert(num);
            }
        }
        return set.size();
    }
};