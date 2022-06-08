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