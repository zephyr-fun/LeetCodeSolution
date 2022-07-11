// 2022.04.14
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> res(temperatures.size(), 0);
        st.push(0);
        for(int i = 1; i < temperatures.size(); i++){
            if(temperatures[i] < temperatures[st.top()]){
                st.push(i);
            }
            else if(temperatures[i] == temperatures[st.top()]){
                st.push(i);
            }
            else{
                while(!st.empty() && temperatures[i] > temperatures[st.top()]){ // note !st.empty()
                    res[st.top()] = i - st.top();
                    st.pop();
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
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<int> st;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && temperatures[st.top()] < temperatures[i]) {
                res[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};