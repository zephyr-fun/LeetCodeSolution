// 2022.10.03
// preSum + monotonic stack
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.insert(heights.begin(), 0);
        heights.emplace_back(0);
        int n = heights.size();
        stack<int> st;
        int res = 0;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && heights[i] < heights[st.top()]) {
                int cur = st.top();
                st.pop();
                int left = st.top();
                int right = i;
                res = max(res, (right - left - 1) * heights[cur]);
            }
            st.push(i);
        }
        return res;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> h(n, vector<int>(m, 0));
        for(int j = 0; j < m; j++) {
            h[0][j] = matrix[0][j] - '0';
        }
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == '1') {
                    h[i][j] = h[i - 1][j] + 1;
                }
            }
        }
        int res = 0;
        for(int i = 0; i < n; i++) {
            res = max(res, largestRectangleArea(h[i]));
        }
        return res;
    }
};

// 2022.10.21
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.insert(heights.begin(), 0);
        heights.emplace_back(0);
        int n = heights.size();
        int res = 0;
        stack<int> st;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && heights[i] < heights[st.top()]) {
                int cur = st.top();
                st.pop();
                int left = st.top();
                int right = i;
                res = max(res, (right - left - 1) * heights[cur]);
            }
            st.push(i);
        }
        return res;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int res = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> h(n, vector<int>(m, 0));
        for(int j = 0; j < m; j++) {
            h[0][j] = matrix[0][j] - '0';
        }
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == '1') {
                    h[i][j] = h[i - 1][j] + 1;
                }
            }
        }
        for(int i = 0; i < n; i++) {
            res = max(res, largestRectangleArea(h[i]));
        }
        return res;
    }
};

// 2023.05.23
// 加引用是真的快
class Solution {
public:
    int maxRow(vector<int>& nums) {
        nums.insert(nums.begin(), -1);
        nums.push_back(-1);
        stack<int> st;
        int n = nums.size();
        int res = 0;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] > nums[i]) {
                int val = nums[st.top()];
                st.pop();
                int left = st.top();
                int right = i;
                res = max(res, (right - left - 1) * val);
            }
            st.push(i);
        }
        return res;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> temp(n, vector<int>(m, 0));
        for(int i = 0; i < m; i++) {
            temp[0][i] = matrix[0][i] == '0' ? 0 : 1;
        }
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                temp[i][j] = matrix[i][j] == '0' ? 0 : matrix[i][j] - '0' + temp[i - 1][j];
            }
        }
        int res = 0;
        for(int i = 0; i < n; i++) {
            res = max(res, maxRow(temp[i]));
        }
        return res;
    }
};