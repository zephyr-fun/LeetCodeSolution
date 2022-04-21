// 2022.04.01
class Solution {
public:
    void subReverse(string& s, int start, int end){
        int left = start;
        int right = end;
        while(left < right){
            s[left] ^= s[right];
            s[right] ^= s[left];
            s[left] ^= s[right];
            left++;
            right--;
        }
    }
    string removeDuplicates(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); i++){
            if(st.empty()){
                st.push(s[i]);
            }
            else if(st.top() == s[i]){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        string res;
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        subReverse(res, 0, res.size() - 1);
        return res;
    }
};

// 2022.04.20
class Solution {
public:
    string removeDuplicates(string s) {
        string sStack;
        for(auto c : s) {
            if(!sStack.empty() && sStack.back() == c) {
                sStack.pop_back();
            }
            else {
                sStack += c;
            }
        }
        return sStack;
    }
};