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