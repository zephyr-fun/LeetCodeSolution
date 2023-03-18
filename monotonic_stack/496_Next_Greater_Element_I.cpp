// 2022.04.15
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map;
        for(int i = 0; i < nums1.size(); i++){
            map[nums1[i]] = i;
        }
        vector<int> res(nums1.size(), -1);
        if(nums1.size() == 0){
            return res;
        }
        stack<int> st;
        st.push(0);
        for(int i = 1; i < nums2.size(); i++){
            if(nums2[i] < nums2[st.top()]){
                st.push(i);
            }
            else if(nums2[i] == nums2[st.top()]){
                st.push(i);
            }
            else{
                while(!st.empty() && nums2[i] > nums2[st.top()]){
                    if(map.find(nums2[st.top()]) != map.end()){
                        res[map[nums2[st.top()]]] = nums2[i];
                    }
                    st.pop();
                }
                st.push(i);
            }
        }
        return res;
    }
};

// 2022.05.30
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map;
        for(int i = 0; i < nums1.size(); i++) {
            map[nums1[i]] = i;
        }
        stack<int> st;
        st.push(0);
        vector<int> res(nums1.size(), -1);
        for(int i = 1; i < nums2.size(); i++) {
            if(nums2[i] <= nums2[st.top()]) {
                st.push(i);
            }
            else {
                while(!st.empty() && nums2[i] > nums2[st.top()]) {
                    if(map.find(nums2[st.top()]) != map.end()) {
                        res[map[nums2[st.top()]]] = nums2[i];
                    }
                    st.pop();
                }
                st.push(i);
            }
        }
        return res;
    }
};

// 2022.06.20
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        unordered_map<int, int> map;
        for(int i = 0; i < m; i++) {
            map[nums1[i]] = i;
        }
        stack<int> st;
        vector<int> res(m, -1);
        for(int i = 0; i < n; i++) {
            while(!st.empty() && st.top() < nums2[i]) {
                int temp = st.top();
                st.pop();
                if(map.find(temp) != map.end()) {
                    res[map[temp]] = nums2[i];
                }
            }
            st.push(nums2[i]);
        }
        return res;
    }
};

// 2022.07.01
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> help(m, -1);
        vector<int> res(n, -1);
        stack<int> st;
        st.push(0);
        for(int i = 1; i < m; i++) {
            while(!st.empty() && nums2[i] > nums2[st.top()]) {
                int idx = st.top();
                st.pop();
                help[idx] = nums2[i];
            }
            st.push(i);
        }
        unordered_map<int, int> map;
        for(int i = 0; i < m; i++) {
            map[nums2[i]] = i;
        }
        for(int i = 0; i < n; i++) {
            res[i] = help[map[nums1[i]]];
        }
        return res;
    }
};

// optim
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> res(n, -1);
        unordered_map<int, int> map;
        for(int i = 0; i < n; i++) {
            map[nums1[i]] = i;
        }
        stack<int> st;
        st.push(0);
        for(int i = 0; i < m; i++) {
            while(!st.empty() && nums2[i] > nums2[st.top()]) {
                int idx = st.top();
                st.pop();
                if(map.find(nums2[idx]) != map.end()) {
                    res[map[nums2[idx]]] = nums2[i];
                }
            }
            st.push(i);
        }
        return res;
    }
};

// 2022.07.11
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        unordered_map<int, int> map;
        for(int i = 0; i < nums1.size(); i++) {
            map[nums1[i]] = i;
        }
        stack<int> st;
        vector<int> res(n, -1);
        for(int i = 0; i < nums2.size(); i++) {
            while(!st.empty() && st.top() < nums2[i]) {
                if(map.count(st.top())) {
                    res[map[st.top()]] = nums2[i];
                }
                st.pop();
            }
            st.push(nums2[i]);
        }
        return res;
    }
};

// 2022.09.11
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> res(n, -1);
        unordered_map<int, int> map;
        stack<int> st;
        for(int i = 0; i < n; i++) {
            map[nums1[i]] = i;
        }
        for(int i = 0; i < m; i++) {
            while(!st.empty() && nums2[st.top()] < nums2[i]) {
                if(map.count(nums2[st.top()])) {
                    res[map[nums2[st.top()]]] = nums2[i];
                }
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};

// 2022.09.26
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        unordered_map<int, int> map;
        for(int i = 0; i < n; i++) {
            map[nums1[i]] = i;
        }
        vector<int> res(n, -1);
        stack<int> st;
        for(int i = 0; i < m; i++) {
            while(!st.empty() && st.top() < nums2[i]) {
                if(map.count(st.top())) {
                    res[map[st.top()]] = nums2[i];
                }
                st.pop();
            }
            st.push(nums2[i]);
        }
        return res;
    }
};

// 2023.03.18
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map;
        for(int i = 0; i < nums1.size(); i++) {
            map[nums1[i]] = i;
        }
        vector<int> res(nums1.size(), -1);
        stack<int> st;
        for(int i = 0; i < nums2.size(); i++) {
            while(!st.empty() && nums2[i] > st.top()) {
                res[map[st.top()]] = nums2[i];
                st.pop();
            }
            if(map.count(nums2[i])) {
                st.push(nums2[i]);
            }
        }
        return res;
    }
};