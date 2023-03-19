// 2022.06.20
// maxVal < st.top()
// num[i] < maxVal
// val
// num[i] < maxVal < st.top()
// subscript
// num[i] < st.top() < maxVal
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        int maxVal = -0x3f3f3f3f;
        for(int i = n - 1; i >= 0; i--) {
            if(nums[i] < maxVal) {
                return true;
            }
            while(!st.empty() && st.top() < nums[i]) {
                maxVal = max(maxVal, st.top());
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};

// 2022.08.11
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> st;
        int maxVal = -0x3f3f3f3f;
        int n = nums.size();
        for(int i = n - 1; i >= 0; i--) {
            if(nums[i] < maxVal) {
                return true;
            }
            while(!st.empty() && st.top() < nums[i]) {
                maxVal = max(maxVal, st.top());
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};

// 2023.03.19
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        int maxVal = -0x3f3f3f3f;
        stack<int> st;
        for(int i = n - 1; i >= 0; i--) {
            if(nums[i] < maxVal) {
                return true;
            }
            while(!st.empty() && st.top() < nums[i]) {
                maxVal = max(maxVal, st.top());
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};