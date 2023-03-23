// 2023.03.23
// O(mnlogn)
class Solution {
public:
    bool is_arithmetic(vector<int>& temp) {
        int n = temp.size();
        int diff = temp[1] - temp[0];
        for(int i = 2; i < n; i++) {
            if(temp[i] - temp[i - 1] != diff) {
                return false;
            }
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size();
        int m = l.size();
        vector<bool> res(m);
        for(int i = 0; i < m; i++) {
            vector<int> temp(nums.begin() + l[i], nums.begin() + r[i] + 1);
            sort(temp.begin(), temp.end());
            res[i] = is_arithmetic(temp);
        }
        return res;
    }
};

// optim by removing sort process
class Solution {
public:
    vector<int> nums;
    bool is_arithmetic(int l, int r) {
        int n = r - l + 1;
        int maxVal = -0x3f3f3f3f;
        int minVal = 0x3f3f3f3f;
        unordered_set<int> set;
        for(int i = l; i <= r; i++) {
            maxVal = max(maxVal, nums[i]);
            minVal = min(minVal, nums[i]);
            set.insert(nums[i]);
        }
        if((maxVal - minVal) % (n - 1) != 0) {
            return false;
        }
        int diff = (maxVal - minVal) / (n - 1);
        int cur = minVal;
        while(cur < maxVal) {
            if(!set.count(cur)) {
                return false;
            }
            cur += diff;
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums_, vector<int>& l, vector<int>& r) {
        nums = nums_;
        int m = l.size();
        vector<bool> res(m);
        for(int i = 0; i < m; i++) {
            res[i] = is_arithmetic(l[i], r[i]);
        }
        return res;
    }
};