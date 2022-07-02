// 2022.06.26
class Solution {
public:
    int makeMax(vector<int>& a, vector<int>& b) {
        // Ci = Bi - Ai;
        // find max subarray sum among array C
        // sum = sum(a)
        // res = sum + max subarray sum
        int n = a.size();
        int delta = -0x3f3f3f3f;
        int dp = 0;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += a[i];
            dp = max(dp, 0) + b[i] - a[i];
            delta = max(delta, dp);
        }
        return sum + delta;
    }
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        return max(makeMax(nums1, nums2), makeMax(nums2, nums1));
    }
};

// 2022.07.02
class Solution {
public:
    int makeOnesideMax(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int dp = 0;
        int delta = -0x3f3f3f3f;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums1[i];
            dp = max(dp, 0) + nums2[i] - nums1[i];
            delta = max(delta, dp);
        }
        return sum + delta;
    }
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        return max(makeOnesideMax(nums1, nums2), makeOnesideMax(nums2, nums1));
    }
};