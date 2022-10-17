// 2022.10.16
class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> set;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            set.insert(nums[i]);
            int temp = 0;
            string s = to_string(nums[i]);
            for(int j = s.size() - 1; j >= 0; j--){
                temp *= 10;
                temp += s[j] - '0';
            }
            set.insert(temp);
        }
        return set.size();
    }
};

// no string
class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> set;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            set.insert(nums[i]);
            int temp = 0;
            while(nums[i]) {
                temp = temp * 10 + nums[i] % 10;
                nums[i] /= 10;
            }
            set.insert(temp);
        }
        return set.size();
    }
};