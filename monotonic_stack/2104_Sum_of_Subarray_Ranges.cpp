// 2022.11.24
class Solution {
public:
    int n;
    long long subArrayRanges(vector<int>& nums) {
        n = nums.size();
        vector<long long> minVal = getCnt(nums, true);
        vector<long long> maxVal = getCnt(nums, false);
        long long res = 0;
        for(int i = 0; i < n; i++) {
            res += (maxVal[i] - minVal[i]) * nums[i];
        }
        return res;
    }
    vector<long long> getCnt(vector<int> nums, bool isMin) {
        vector<int> a(n, 0);
        vector<int> b(n, 0);
        stack<int> st;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && (isMin ? nums[st.top()] >= nums[i] : nums[st.top()] <= nums[i])) {
                st.pop();
            }
            a[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while(!st.empty()) {
            st.pop();
        }
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && (isMin ? nums[st.top()] > nums[i] : nums[st.top()] < nums[i])) {
                st.pop();
            }
            b[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        vector<long long> res(n, 0);
        for(int i = 0; i < n; i++) {
            res[i] = (i - a[i]) * 1LL * (b[i] - i);
        }
        return res;
    }
};