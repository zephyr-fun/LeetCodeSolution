// 2022.09.12
class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string cur = "";
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                st.push(cur);
                cur = "";
            }
            else if(s[i] == ')') {
                string temp = st.top();
                st.pop();
                // in case the test sample is not valid
                // if(!st.empty()) {
                //     temp = st.top();
                //     st.pop();
                // }
                reverse(cur.begin(), cur.end());
                cur = temp + cur;
            }
            else {
                cur += s[i];
            }
        }
        return cur;
    }
};

// 2023.01.05
class Solution {
public:
    string helper(string& s) {
        // 先找到最里面的左括号
        int l = s.find_last_of('(', s.size() - 1);
        // 如果没有括号直接返回
        if(l == string::npos) {
            return s;
        }
        // 找到最里面的右括号的位置
        int r = l + 1;
        while(s[r] != ')'){
            r++;
        }
        // 初始化双指针，指向最里面括号的两端字符
        int left = l + 1;
        int right = r - 1;
        // 反转括号内的字符串
        while(left < right) {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
        // 用之前找到的左边括号的位置调用erase方法删除左括号
        s.erase(l, 1);
        // 因为上一行代码删除了左括号，字符串长度少了1，所以这一步r要减1
        s.erase(r - 1, 1);
        // 递归调用
        return helper(s);
    }

    string reverseParentheses(string s) {
        return helper(s);
    }
};