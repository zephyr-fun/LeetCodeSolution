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