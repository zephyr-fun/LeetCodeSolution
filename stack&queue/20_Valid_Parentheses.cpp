// 2022.04.01
class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                st.push(')');
            }
            else if(s[i] == '['){
                st.push(']');
            }
            else if(s[i] == '{'){
                st.push('}');
            }
            else if(st.empty() || st.top() != s[i]){
                return false;
            }
            else{
                st.pop();
            }
        }
        return st.empty();
    }
};

// 2022.04.20
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                st.push(')');
            }
            else if(s[i] == '[') {
                st.push(']');
            }
            else if(s[i] == '{') {
                st.push('}');
            }
            else {
                if(st.empty() || st.top() != s[i]) {
                    return false;
                }
                else {
                    st.pop();
                }
            }
        }
        return st.empty();
    }
};

// 2022.07.03
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        bool flag = false;
        for(auto c : s) {
            if(c == '(') {
                st.push(')');
            }
            else if(c == '[') {
                st.push(']');
            }
            else if(c == '{') {
                st.push('}');
            }
            else {
                if(!st.empty()) {
                    if(st.top() == c) {
                        st.pop();
                    }
                    else {
                        flag = true;
                        break;
                    }
                }
                else {
                    flag = true;
                    break;
                }
            }
        }
        if(flag || !st.empty()) {
            return false;
        }
        return true;
    }
};

// optim
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto c : s) {
            if(c == '(') {
                st.push(')');
            }
            else if(c == '[') {
                st.push(']');
            }
            else if(c == '{') {
                st.push('}');
            }
            else {
                if(st.empty() || st.top() != c) {
                    return false;
                }
                else {
                    st.pop();
                }
            }
        }
        return st.empty();
    }
};