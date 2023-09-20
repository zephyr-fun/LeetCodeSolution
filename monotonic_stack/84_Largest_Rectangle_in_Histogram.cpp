// 2022.04.15
// not work
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int left = monotonic(heights);
        // cout << left;
        reverse(heights.begin(), heights.end());
        int right = monotonic(heights);
        // cout << right;
        return max(left, right);
    }
    int monotonic(vector<int>& heights){
        int res = 0;
        stack<int> st;
        st.push(0);
        for(int i = 1; i < heights.size(); i++){
            if(heights[i] < heights[st.top()]){
                st.push(i);
            }
            else if(heights[i] == heights[st.top()]){
                st.push(i);
            }
            else{
                while(!st.empty() && heights[i] > heights[st.top()]){
                    res = res > heights[st.top()] * st.size() ? res : heights[st.top()] * st.size();
                    st.pop();
                }
                st.push(i);
            }
        }
        while(!st.empty()){
            res = res > heights[st.top()] * st.size() ? res : heights[st.top()] * st.size();
            st.pop();
        }
        return res;
    }
};

// monotonic stack
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        int res = 0;
        st.push(0);
        for(int i = 1; i < heights.size(); i++){
            if(heights[i] > heights[st.top()]){
                st.push(i);
            }
            else if(heights[i] == heights[st.top()]){
                st.pop();
                st.push(i);
            }
            else{
                while(heights[i] < heights[st.top()]){
                    int mid = st.top();
                    st.pop();
                    int left = st.top();
                    int right = i;
                    int w = right - left - 1;
                    int h = heights[mid];
                    res = max(res, h * w);
                }
                st.push(i);
            }
        }
        return res;
    }
};

// 2022.07.11
class Solution {
public:
    void clear(stack<int>& st) {
        while(!st.empty()) {
            st.pop();
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        heights.insert(heights.begin(), 0);
        heights.emplace_back(0);
        int n = heights.size();
        stack<int> st;
        vector<int> left(n, -1);
        vector<int> right(n, -1);
        for(int i = 0; i < n; i++) {
            while(!st.empty() && heights[st.top()] > heights[i]) {
                int cur = st.top();
                st.pop();
                right[cur] = i;
            }
            st.push(i);
        }
        clear(st);
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && heights[st.top()] > heights[i]) {
                int cur = st.top();
                st.pop();
                left[cur] = i;
            }
            st.push(i);
        }
        int res = 0;
        for(int i = 1; i < n - 1; i++) {
            res = max(res, (right[i] - left[i] - 1) * heights[i]);
        }
        return res;
    }
};

// one time code
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
};

// 2022.10.03
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
};

// 2023.05.20
// left and right
class Solution {
public:
    void clear(stack<int>& st) {
        while(!st.empty()) {
            st.pop();
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        heights.insert(heights.begin(), 0);
        heights.emplace_back(0);
        int n = heights.size();
        stack<int> st;
        vector<int> left(n, -1);
        vector<int> right(n, -1);
        for(int i = 0; i < n; i++) {
            while(!st.empty() && heights[st.top()] > heights[i]) {
                right[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        clear(st);
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && heights[st.top()] > heights[i]) {
                left[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        int res = 0;
        for(int i = 1; i < n - 1; i++) {
            res = max(res, (right[i] - left[i] - 1) * heights[i]);
        }
        return res;
    }
};

// monotonic stack
// decrease
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.insert(heights.begin(), 0);
        heights.emplace_back(0);
        stack<int> st;
        int res = 0;
        int n = heights.size();
        for(int i = 0; i < n; i++) {
            while(!st.empty() && heights[st.top()] > heights[i]) {
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
};

// 2023.09.20
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int max_value = 0;
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        int n = heights.size();
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int right = i;
                int mid = st.top();
                st.pop();
                int left = st.top();
                max_value = max(max_value, heights[mid] * (right - left -1));
            }
            st.push(i);
        }
        return max_value;
    }
};

// reorder pop
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.insert(heights.begin(), 0);
        heights.emplace_back(0);
        int n = heights.size();
        stack<int> st;
        int max_value = 0;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int mid = heights[st.top()];
                st.pop();
                int left = st.top();
                int right = i;
                max_value = max(max_value, mid * (right - left - 1));
            }
            st.push(i);
        }
        return max_value;
    }
};