// 2022.06.08
// can't work cause minus value
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int minVal = 0x3f3f3f3f;
        for(int i = 0; i < n; i++) {
            minVal = min(minVal, nums[i]);
        }
        for(int i = 0; i < n; i++) {
            nums[i] += abs(minVal);
        }
        int left = 0;
        int right = 0;
        int res = 0;
        int sum = 0;
        while(right < n) {
            sum += nums[right];
            right++;
            while(sum > k + (right - left) * abs(minVal) && left + 1 != right) {
                sum -= nums[left];
                left++;
            }
            if(sum == k + (right - left) * abs(minVal)) {
                res++;
            }
        }
        return res;
    }
};

// prefix + hash
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        unordered_map<int, int> map;
        map[0] = 1;
        int res = 0;
        for(int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
            if(map.find(prefix[i + 1] - k) != map.end()) {
                res += map[prefix[i + 1] - k];
            }
            map[prefix[i + 1]]++;
        }
        return res;
    }
};

// 2022.06.24
// hash + preSum
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> map;
        vector<int> preSum(n + 1, 0);
        map[preSum[0]]++;
        int res = 0;
        for(int i = 1; i <= n; i++) {
            preSum[i] = preSum[i - 1] + nums[i - 1];
            if(map.find(preSum[i] - k) != map.end()) {
                res += map[preSum[i] - k];
            }
            map[preSum[i]]++;
        }
        return res;
    }
};

// 2022.08.22
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, vector<int>> map; // sum value, subscript
        int cur = 0;
        int res = 0;
        map[0].emplace_back(-1);
        for(int i = 0; i < n; i++) {
            cur += nums[i];
            if(map.count(cur - k)) {
                res += map[cur - k].size();
            }
            map[cur].emplace_back(i);
        }
        return res;
    }
}

// optim
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> map;
        int cur = 0;
        int res = 0;
        map[0] = 1;
        for(int i = 0; i < n; i++) {
            cur += nums[i];
            if(map.count(cur - k)) {
                res += map[cur - k];
            }
            map[cur]++;
        }
        return res;
    }
};

// 2022.10.09
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> map;
        int res = 0;
        int cur = 0;
        map[0] = 1;
        for(int i = 0; i < n; i++) {
            cur += nums[i];
            if(map.count(cur - k)) {
                res += map[cur - k];
            }
            map[cur]++;
        }
        return res;
    }
};

// 2022.10.24
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> map;
        map[0] = 1;
        int cur = 0;
        int res = 0;
        for(int i = 0; i < n; i++) {
            cur += nums[i];
            if(map.count(cur - k)) {
                res += map[cur - k];
            }
            map[cur]++;
        }
        return res;
    }
};