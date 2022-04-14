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