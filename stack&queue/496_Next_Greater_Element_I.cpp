// 2022.09.10
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
            while(!st.empty() && nums2[st.top()] < nums2[i]) {
                int idx = st.top();
                st.pop();
                if(map.count(nums2[idx])) {
                    res[map[nums2[idx]]] = nums2[i];
                }
            }
            st.push(i);
        }
        return res;
    }
};