// 2022.04.15
// double pointers, O(n^2), TLE
class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0;
        for(int i = 0; i < height.size(); i++){
            if(i == 0 || i == height.size() - 1){
                continue;
            }
            int leftHeight = height[i];
            int rightHeight = height[i];
            for(int l = i - 1; l >= 0; l--){
                if(height[l] > leftHeight){
                    leftHeight = height[l];
                }
            }
            for(int r = i + 1; r < height.size(); r++){
                if(height[r] > rightHeight){
                    rightHeight = height[r];
                }
            }
            sum += min(leftHeight, rightHeight) - height[i];
        }
        return sum;
    }
};

// dp O(n)
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() <= 2){
            return 0;
        }
        vector<int> maxLeft(height.size(), 0);
        vector<int> maxRight(height.size(), 0);
        maxLeft[0] = height[0];
        for(int i = 1; i < height.size(); i++){
            maxLeft[i] = max(maxLeft[i - 1], height[i]);
        }
        maxRight[height.size() - 1] = height[height.size() - 1];
        for(int i = height.size() - 2; i >= 0; i--){
            maxRight[i] = max(maxRight[i + 1], height[i]);
        }
        int sum = 0;
        for(int i = 0; i < height.size(); i++){
            int count = min(maxLeft[i], maxRight[i]) - height[i];
            if(count > 0){
                sum += count;
            }
        }
        return sum;
    }
};

// monotonic stack
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() <= 2){
            return 0;
        }
        stack<int> st;
        st.push(0);
        int sum = 0;
        for(int i = 1; i < height.size(); i++){
            if(height[i] < height[st.top()]){
                st.push(i);
            }
            else if(height[i] == height[st.top()]){
                st.pop();
                st.push(i);
            }
            else{
                while(!st.empty() && height[i] > height[st.top()]){
                    int mid = st.top();
                    st.pop();
                    if(!st.empty()){
                        int h = min(height[st.top()], height[i]) - height[mid];
                        int w = i - st.top() - 1;
                        sum += h * w;
                    }
                }
                st.push(i);
            }
        }
        return sum;
    }
};


// 2022.07.11
// count by column
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> maxLeft(n, 0);
        vector<int> maxRight(n, 0);
        maxLeft[0] = height[0];
        maxRight[n - 1] = height[n - 1];
        for(int i = 1; i < n; i++) {
            maxLeft[i] = max(maxLeft[i - 1], height[i]);
        }
        for(int i = n - 2; i >= 0; i--) {
            maxRight[i] = max(maxRight[i + 1], height[i]);
        }
        int res = 0;
        for(int i = 0; i < n; i++) {
            int cur = min(maxLeft[i], maxRight[i]) - height[i];
            if(cur > 0) {
                res += cur;
            }
        }
        return res;
    }
};

// count by row(layer)
// monotonic stack
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int res = 0;
        int n = height.size();
        for(int i = 0; i < n; i++) {
            while(!st.empty() && height[st.top()] < height[i]) {
                int cur = st.top();
                st.pop();
                while(!st.empty() && height[st.top()] == height[cur]) {
                    st.pop();
                }
                if(!st.empty()) { // may not have st.top(), judge
                    res += (min(height[st.top()], height[i]) - height[cur]) * (i - st.top() - 1);
                }
            }
            st.push(i);
        }
        return res;
    }
};

// 2022.07.13
// col
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> maxLeft(n, 0);
        vector<int> maxRight(n, 0);
        maxLeft[0] = height[0];
        maxRight[n - 1] = height[n - 1];
        for(int i = 1; i < n; i++) {
            maxLeft[i] = max(maxLeft[i - 1], height[i]);
        }
        for(int i = n - 2; i >= 0; i--) {
            maxRight[i] = max(maxRight[i + 1], height[i]);
        }
        int res = 0;
        for(int i = 0; i < n; i++) {
            if(min(maxLeft[i], maxRight[i]) - height[i] > 0) {
                res += min(maxLeft[i], maxRight[i]) - height[i];
            }
        }
        return res;
    }
};

// layer
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        stack<int> st;
        int res = 0;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && height[i] > height[st.top()]) {
                int mid = st.top();
                st.pop();
                while(!st.empty() && height[st.top()] == height[mid]) {
                    st.pop();
                }
                if(!st.empty()) {
                    int h = min(height[st.top()], height[i]) - height[mid];
                    int w = i - st.top() - 1;
                    res += h * w;
                }
            }
            st.push(i);
        }
        return res;
    }
};

// 2022.09.11
// vertical
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftMax(n);
        vector<int> rightMax(n);
        leftMax[0] = 0;
        rightMax[n - 1] = 0;
        for(int i = 1, j = n - 2; i < n; i++, j--) {
            leftMax[i] = max(leftMax[i - 1], height[i - 1]);
            rightMax[j] = max(rightMax[j + 1], height[j + 1]);
        }
        int res = 0;
        for(int i = 0; i < n; i++) {
            if(min(leftMax[i], rightMax[i]) > height[i]) {
                res += min(leftMax[i], rightMax[i]) - height[i];
            }
        }
        return res;
    }
};

// horizontal
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        stack<int> st;
        int res = 0;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && height[i] > height[st.top()]) {
                int temp = st.top();
                st.pop();
                // accelerate
                while(!st.empty() && height[st.top()] == height[temp]) {
                    st.pop();
                }
                // accelerate
                if(!st.empty()) {
                    res += (min(height[i], height[st.top()]) - height[temp]) * (i - st.top() - 1);
                }
            }
            st.push(i);
        }
        return res;
    }
};