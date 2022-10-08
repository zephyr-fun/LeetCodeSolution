// 2022.10.08
// https://leetcode.cn/problems/advantage-shuffle/solution/tian-ji-sai-ma-by-endlesscheng-yxm6/
class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> res(n, 0);
        vector<int> idx(n, 0);
        for(int i = 0; i < n; i++) {
            idx[i] = i;
        }
        sort(nums1.begin(), nums1.end());
        sort(idx.begin(), idx.end(), [&](int& a, int& b) {
            return nums2[a] < nums2[b];
        });
        int left = 0;
        int right = n - 1;
        for(auto num : nums1) {
            res[num > nums2[idx[left]] ? idx[left++] : idx[right--]] = num;
        }
        return res;
    }
};