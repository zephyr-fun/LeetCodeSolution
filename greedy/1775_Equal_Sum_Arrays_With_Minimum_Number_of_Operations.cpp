// 2022.12.07
class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        if(6 * nums1.size() < nums2.size() || 6 * nums2.size() < nums1.size()) {
            return -1;
        }
        int diff = accumulate(nums2.begin(), nums2.end(), 0) - accumulate(nums1.begin(), nums1.end(), 0);
        if(diff < 0) {
            diff = -diff;
            swap(nums1, nums2);
        }
        int cnt[6]{};
        for(int x : nums1) {
            cnt[6 - x]++;
        }
        for(int x : nums2) {
            cnt[x - 1]++;
        }
        for(int i = 5, res = 0; ; i--) {
            if(i * cnt[i] >= diff) {
                return res + (diff + i - 1) / i;
            }
            res += cnt[i];
            diff -= i * cnt[i];
        }
    }
};

// 2023.02.27
class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if(6 * n < m || 6 * m < n) {
            return -1;
        }
        int sum1 = 0;
        int sum2 = 0;
        int map[6];
        memset(map, 0, sizeof(map));
        for(auto& num : nums1) {
            sum1 += num;
            map[6 - num]++;
        }
        for(auto& num : nums2) {
            sum2 += num;
            map[num - 1]++;
        }
        if(sum1 > sum2) {
            return minOperations(nums2, nums1);
        }
        int diff = sum2 - sum1;
        int res = 0;
        int idx = 5;
        while(diff) {
            if(diff >= map[idx] * idx) {
                diff -= map[idx] * idx;
                res += map[idx];
            }
            else {
                res += (diff % idx == 0 ? diff / idx : diff / idx + 1);
                diff = 0;
            }
            idx--;
        }
        return res;
    }
};