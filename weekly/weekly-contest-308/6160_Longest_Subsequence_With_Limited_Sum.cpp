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

// 2023.03.17
// optim with preSum
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int preSum[n + 1];
        memset(preSum, 0, sizeof(preSum));
        for(int i = 1; i <= n; i++) {
            preSum[i] = preSum[i - 1] + nums[i - 1];
        }
        int m = queries.size();
        vector<int> res(m, 0);
        for(int i = 0; i < m; i++) {
            int left = 0;
            int right = n;
            int pos = 0;
            while(left <= right) {
                int mid = left + ((right - left) >> 1);
                if(preSum[mid] <= queries[i]) {
                    pos = mid;
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
            res[i] = pos;
        }
        return res;
    }
};