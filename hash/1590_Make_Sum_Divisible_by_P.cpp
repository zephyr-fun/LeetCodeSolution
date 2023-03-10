// 2023.03.10
// presum + binary search didn't work cause you can't assume that longer sequences have lager possibility
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        vector<int> sum(n + 1, 0);
        for(int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + nums[i];
        }
        int res = 0x3f3f3f3f;
        if(sum[n] % p == 0) {
            return 0;
        }
        function<bool(int)> is_cap = [&] (int len) {
            for(int i = 0; i < n - len; i++) {
                if((sum[n] - (sum[i + len + 1] - sum[i])) % p == 0) {
                    return true;
                }
            }
            return false;
        };
        int left = 1;
        int right = n - 1;
        while(left <= right) {
            int mid = left + ((right - left) >> 1);
            if(is_cap(mid)) {
                res = min(res, mid);
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return res == 0x3f3f3f3f ? -1 : res;
    }
};

// presum + hash
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int k = 0;
        for(auto& num : nums) {
            k = (k + num) % p;
        }
        if(k == 0) {
            return 0;
        }
        unordered_map<int, int> last;
        last[0] = -1;
        int cur = 0;
        int n = nums.size();
        int res = n;
        for(int i = 0; i < n; i++) {
            cur = (cur + nums[i]) % p;
            int target = (cur - k + p) % p; // notice cur refers to sum(nums[0]->nums[j]), cur - (cur - k + p) % p = k
            if(last.count(target)) {
                res = min(res, i - last[target]);
            }
            last[cur] = i;
        }
        return res == n ? -1 : res;
    }
};