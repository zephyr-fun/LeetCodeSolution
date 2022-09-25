// 2022.09.25
// 缺少一步构造二段性，可以用单调栈对前缀和筛选一遍，然后再二分
// class Solution {
// public:
//     int longestESR(vector<int>& sales) {
//         int n = sales.size();
//         for(auto& s : sales) {
//             if(s > 8) {
//                 s = 1;
//             }
//             else {
//                 s = -1;
//             }
//         }
//         vector<int> pre(n + 1, 0);
//         for(int i = 1; i <= n; i++) {
//             pre[i] = pre[i - 1] + sales[i - 1];
//         }
//         int res = 0;
//         int left = 0;
//         int right = n;
//         while(left <= right) {
//             int mid = left + (right - left) / 2;
//             bool flag = false;
//             for(int i = 0; i <= n - mid; i++) {
//                 if(pre[i + mid] - pre[i] >= 0) {
//                     flag = true;
//                     break;
//                 }
//             }
//             if(flag) {
//                 left = mid + 1;
//                 if(mid)
//                 res = mid;
//             }
//             else {
//                 right = mid - 1;
//             }
//         }
//         return res;
//     }
// };
// same as 1124
class Solution {
public:
    int longestESR(vector<int>& hours) {
        // 处理数组为每天的得分
        int n = hours.size();
        for(int i = 0; i < n; i++) {
            if(hours[i] > 8) {
                hours[i] = 1;
            }
            else {
               hours[i] = -1;
            }
        }
        // 求前缀和
        int pre[n + 1];
        memset(pre, 0, sizeof(pre));
        for(int i = 1; i <= n; i++) {
            pre[i] = pre[i - 1] + hours[i - 1];
        }
        // 单调栈记录前缀和的递减下标（★也就是首次最低值下标）
        stack<int> st;
        // while(s.size()) s.pop();
        for(int i = 0; i <= n; i++) {
            if(st.empty() || pre[st.top()] > pre[i]) {
                st.push(i);
            }
        }
        int res = 0;
        // 枚举右边界
        for(int i = n; i >= 0; i--) {
            if(st.empty()) {
                break;
            }
            while(!st.empty() && st.top() >= i) {
                st.pop();
            }
            while(!st.empty() && pre[st.top()] < pre[i]) {
                res = max(res, i - st.top());
                st.pop();
            }
        }
        return res;
    }
};