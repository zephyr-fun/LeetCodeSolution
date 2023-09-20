// 2022.04.15
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size(), -1);
        if(nums.size() == 0){
            return res;
        }
        stack<int> st;
        st.push(0);
        for(int i = 1; i < nums.size() * 2; i++){
            if(nums[i % nums.size()] < nums[st.top()]){
                st.push(i % nums.size());
            }
            else if(nums[i % nums.size()] == nums[st.top()]){
                st.push(i % nums.size());
            }
            else{
                while(!st.empty() && nums[i % nums.size()] > nums[st.top()]){
                    res[st.top()] = nums[i % nums.size()];
                    st.pop();
                }
                st.push(i % nums.size());
            }
        }
        return res;
    }
};

// 2022.05.30
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size(), -1);
        stack<int> st;
        st.push(0);
        for(int i = 0; i < nums.size() * 2; i++) {
            if(nums[i % nums.size()] <= nums[st.top()]) {
                st.push(i % nums.size());
            }
            else {
                while(!st.empty() && nums[i % nums.size()] > nums[st.top()]) {
                    res[st.top()] = nums[i % nums.size()];
                    st.pop();
                }
                st.push(i % nums.size());
            }
        }
        return res;
    }
};

// 2022.06.20
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> st;
        for(int i = 0; i < 2 * n; i++) {
            while(!st.empty() && nums[st.top() % n] < nums[i % n]) {
                int temp = st.top() % n;
                st.pop();
                res[temp] = nums[i % n];
            }
            st.push(i);
        }
        return res;
    }
};

// 2022.07.01
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        st.push(0);
        vector<int> res(n, -1);
        for(int i = 0; i < 2 * n; i++) {
            while(!st.empty() && nums[i % n] > nums[st.top()]) {
                int idx = st.top();
                st.pop();
                res[idx] = nums[i % n];
            }
            st.push(i % n);
        }
        return res;
    }
};

// 2022.07.11
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> res(n, -1);
        for(int i = 0; i < 2 * n; i++) {
            while(!st.empty() && nums[st.top()] < nums[i % n]) {
                int t = st.top();
                st.pop();
                res[t] = nums[i % n];
            }
            st.push(i % n);
        }
        return res;
    }
};

// 2022.09.14
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> st;
        for(int i = 0; i < 2 * n - 1; i++) {
            while(!st.empty() && nums[st.top()] < nums[i % n]) {
                res[st.top()] = nums[i % n];
                st.pop();
            }
            st.push(i % n);
        }
        return res;
    }
};

// 2022.09.26
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> st;
        for(int i = 0; i < 2 * n; i++) {
            while(!st.empty() && nums[st.top()] < nums[i % n]) {
                res[st.top()] = nums[i % n];
                st.pop();
            }
            st.push(i % n);
        }
        return res;
    }
};

// 2023.03.18
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> st;
        for(int i = 0; i < 2 * n; i++) {
            while(!st.empty() && nums[i % n] > nums[st.top()]) {
                res[st.top()] = nums[i % n];
                st.pop();
            }
            st.push(i % n);
        }
        return res;
    }
};

// 2023.09.20
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> st;
        for (int i = 0; i < 2 * n; i++) {
            while (!st.empty() && nums[i % n] > nums[st.top()]) {
                res[st.top()] = nums[i % n];
                st.pop();
            }
            st.push(i % n);
        }
        return res;
    }
};