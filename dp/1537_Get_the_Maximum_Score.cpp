// 2022.06.23
// double points, O(1) space
class Solution {
public:
    int MOD = 1e9 + 7;
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        long long sum1 = 0;
        long long sum2 = 0;
        int i = 1;
        int j = 1;
        while(i <= n || j <= m) {
            if(i <= n && j <= m) {
                if(nums1[i - 1] < nums2[j - 1]) {
                    sum1 += nums1[i - 1];
                    i++;
                }
                else if(nums1[i - 1] > nums2[j - 1]) {
                    sum2 += nums2[j - 1];
                    j++;
                }
                else {
                    sum1 = sum2 = max(sum1, sum2) + nums1[i - 1];
                    i++;
                    j++;
                }
            }
            else if(i <= n) {
                sum1 += nums1[i - 1];
                i++;
            }
            else {
                sum2 += nums2[j - 1];
                j++;
            }
        }
        return int(max(sum1, sum2) % MOD);
    }
};
// also sequence dp, O(n) space
class Solution {
public:
    int MOD = 1e9 + 7;
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<long long> dp1(n + 1, 0);
        vector<long long> dp2(m + 1, 0);
        int i = 1;
        int j = 1;
        while(i <= n || j <= m) {
            if(i <= n && j <= m) {
                if(nums1[i - 1] < nums2[j - 1]) {
                    dp1[i] = dp1[i - 1] + nums1[i - 1];
                    i++;
                }
                else if(nums1[i - 1] > nums2[j - 1]) {
                    dp2[j] = dp2[j - 1] + nums2[j - 1];
                    j++;
                }
                else {
                    dp1[i] = dp2[j] = max(dp1[i - 1], dp2[j - 1]) + nums1[i - 1];
                    i++;
                    j++;
                }
            }
            else if(i <= n) {
                dp1[i] = dp1[i - 1] + nums1[i - 1];
                i++;
            }
            else {
                dp2[j] = dp2[j - 1] + nums2[j - 1];
                j++;
            }
        }
        return int(max(dp1[n], dp2[m]) % MOD);
    }
};