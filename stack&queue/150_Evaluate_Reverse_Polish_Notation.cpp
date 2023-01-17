// 2022.04.01
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                if(tokens[i] == "+"){
                    st.push(num2 + num1);
                }
                else if(tokens[i] == "-"){
                    st.push(num2 - num1);
                }
                else if(tokens[i] == "*"){
                    st.push(num2 * num1);
                }
                else{
                    st.push(num2 / num1);
                }
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};

// 2022.04.20
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i = 0; i < tokens.size(); i++) {
            if(tokens[i] == "+") { // a little bit redundent
                int temp2 = st.top();
                st.pop();
                int temp1 = st.top();
                st.pop();
                st.push(temp1 + temp2);
            }
            else if(tokens[i] == "-") {
                int temp2 = st.top();
                st.pop();
                int temp1 = st.top();
                st.pop();
                st.push(temp1 - temp2);
            }
            else if(tokens[i] == "*") {
                int temp2 = st.top();
                st.pop();
                int temp1 = st.top();
                st.pop();
                st.push(temp1 * temp2);
            }else if(tokens[i] == "/") {
                int temp2 = st.top();
                st.pop();
                int temp1 = st.top();
                st.pop();
                st.push(temp1 / temp2);
            }
            else {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};

// 2023.01.17
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n = tokens.size();
        for(int i = 0; i < n; i++) {
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                if(tokens[i] == "+") {
                    st.push(first + second);
                }
                else if(tokens[i] == "-") {
                    st.push(second - first);
                }
                else if(tokens[i] == "*") {
                    st.push(first * second);
                }
                else {
                    st.push(second / first);
                }
            }
            else {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};