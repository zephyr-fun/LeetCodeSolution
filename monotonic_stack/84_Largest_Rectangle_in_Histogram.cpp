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