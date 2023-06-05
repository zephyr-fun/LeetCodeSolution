// 2023.06.04
class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_set<double> set;
        int i = 0;
        int j = nums.size() - 1;
        while(i < j) {
            set.insert((nums[i] + nums[j]) / 2.0);
            i++;
            j--;
        }
        return set.size();
    }
};

// optim
// (nums[i] + nums[j]) / 2.0 === nums[i] + nums[j]
// thus unordered_set<double> -> unordered_set<int>
class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_set<int> set;
        int i = 0;
        int j = nums.size() - 1;
        while(i < j) {
            set.insert(nums[i] + nums[j]);
            i++;
            j--;
        }
        return set.size();
    }
};