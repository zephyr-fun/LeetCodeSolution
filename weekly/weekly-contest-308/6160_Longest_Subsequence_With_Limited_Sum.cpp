// 2022.08.29 sorted
class Solution {
public:
    vector<int> nums;
    int n;
    int longSub(int target) {
        int left = 0;
        int right = 0;
        int cur = 0;
        int res = 0;
        while(right < n) {
            cur += nums[right];
            right++;
            while(cur > target) {
                cur -= nums[left];
                left++;
            }
            res = max(res, right - left);
        }
        return res;
    }
    vector<int> answerQueries(vector<int>& nums_, vector<int>& queries) {
        nums = nums_;
        sort(nums.begin(), nums.end());
        n = nums.size();
        int m = queries.size();
        for(int i = 0; i < m; i++) {
            queries[i] = longSub(queries[i]);
        }
        return queries;
    }
};