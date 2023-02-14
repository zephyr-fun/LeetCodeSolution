// 2022.09.25
// T0 solution, with int[] replace unordered_map
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        // unordered_map<int, int> map;
        int n = hours.size();
        int map[2 * n + 7];
        int offset = n + 1;
        memset(map, -1, sizeof(map));
        int res = 0;
        int sum = 0;
        for(int i = 0; i < hours.size(); i++) {
            if(hours[i] > 8) {
                sum++;
            }
            else {
                sum--;
            }
            if(sum > 0) {
                res = i + 1;
            }
            else {
                if(map[sum - 1 + offset] != -1) {
                    res = max(res, i - map[sum - 1 + offset]);
                }
                if(map[sum + offset] == -1) {
                    map[sum + offset] = i;
                }
            }
        }
        return res;
    }
};

// monotonic stack
class Solution {
public:
    int longestWPI(vector<int>& hours) {
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

// 2023.02.14
// new monotonic stack template
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int res = 0;
        int n = hours.size();
        int preSum[n + 1];
        memset(preSum, 0, sizeof(preSum));
        stack<int> st;
        // candidate left end
        st.push(0);
        for(int i = 1; i <= n; i++) {
            preSum[i] = preSum[i - 1] + (hours[i - 1] > 8 ? 1 : -1);
            if(preSum[st.top()] > preSum[i]) {
                st.push(i);
            }
        }
        for(int i = n; i > 0; i--) {
            while(!st.empty() && preSum[st.top()] < preSum[i]) {
                res = max(res, i - st.top());
                st.pop();
            }
        }
        return res;
    }
};

// take advantage of the continuance
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        int map[n + 2];
        memset(map, 0, sizeof(map));
        map[0] = 0; // val, pos
        int res = 0;
        int cur = 0;
        // in case of preSum, iterate with i = 1
        for(int i = 1; i <= n; i++) {
            cur += hours[i - 1] > 8 ? -1 : 1;
            if(cur < 0) {
                res = i;
            }
            else {
                if(map[cur + 1]) {
                    res = max(res, i - map[cur + 1]);
                }
                if(map[cur] == 0) {
                    map[cur] = i;
                }
            }
        }
        return res;
    }
};