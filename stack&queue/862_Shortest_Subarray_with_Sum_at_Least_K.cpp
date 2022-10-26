// 2022.10.26
// if there is no negative number
// class Solution {
// public:
//     int shortestSubarray(vector<int>& nums, int k) {
//         int n = nums.size();
//         vector<long long> presum(n + 1, 0);
//         for(int i = 1; i <= n; i++) {
//             presum[i] = presum[i - 1] + nums[i - 1];
//         }
//         int res = 0x3f3f3f3f;
//         for(int i = 1; i <= n; i++) {
//             int left = 0;
//             int right = i - 1;
//             int pos = -1;
//             while(left <= right) {
//                 int mid = (left + right) >> 1;
//                 if(presum[mid] <= presum[i] - k) {
//                     pos = mid;
//                     left = mid + 1;
//                 }
//                 else {
//                     right = mid - 1;
//                 }
//             }
//             if(pos != -1) {
//                 res = min(res, i - pos);
//             }
//         }
//         return res == 0x3f3f3f3f ? -1 : res;
//     }
// };

// https://www.acwing.com/video/2966/
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> presum(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            presum[i] = presum[i - 1] + nums[i - 1];
        }
        int res = 0x3f3f3f3f;
        deque<int> dq;
        dq.push_back(0);
        for(int i = 1; i <= n; i++) {
            while(!dq.empty() && presum[dq.front()] + k <= presum[i]) {
                res = min(res, i - dq.front());
                dq.pop_front();
            }
            while(!dq.empty() && presum[dq.back()] > presum[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return res == 0x3f3f3f3f ? -1 : res;
    }
};