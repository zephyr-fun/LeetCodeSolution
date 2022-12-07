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