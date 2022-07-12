// 2022.07.07
// recursion
class Solution {
public:
    string decode(string s, int& i) { // & i 
        int num = 0;
        string temp = "";
        for( ; i < s.size(); i++) {
            if(s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + s[i] - '0';
            }
            else if(s[i] >= 'a' && s[i] <= 'z') {
                temp += s[i];
            }
            else if(s[i] == '[') {
                string last_temp = decode(s, ++i);
                string loop_temp = last_temp;
                for(int k = 1; k < num; k++) {
                    last_temp += loop_temp;
                }
                temp = temp + last_temp;
                int score = 0;
                num = 0;
            }
            else {
                // s[i] == ']'
                return temp;
            }
        }
        return temp;
    }
    string decodeString(string s) {
        // i and &i
        int i = 0;
        return decode(s, i);
    }
};

// stack
class Solution {
public:
    string decodeString(string s) {
        stack<pair<string, int>> st;
        string temp = "";
        int num = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + s[i] - '0';
            }
            else if(s[i] >= 'a' && s[i] <= 'z') {
                temp += s[i];
            }
            else if(s[i] == '[') {
                st.push({temp, num});
                temp = "";
                num = 0;
            }
            else {
                // s[i] == ']'
                auto [last_temp, last_num] = st.top();
                st.pop();
                string loop_temp = "";
                for(int i = 0; i < last_num; i++) {
                    loop_temp += temp;
                }
                temp = last_temp + loop_temp;
            }
        }
        return temp;
    }
};

// 2022.07.12
// stack
class Solution {
public:
    string decodeString(string s) {
        int num = 0;
        string temp = "";
        stack<pair<string, int>> st;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if(s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + s[i] - '0';
            }
            else if(s[i] >= 'a' && s[i] <= 'z') {
                temp += s[i];
            }
            else if(s[i] == '[') {
                st.push({temp, num});
                num = 0;
                temp = "";
            }
            else {
                // s[i] == ']'
                auto [prevS, prevNum] = st.top();
                st.pop();
                string ss = "";
                for(int i = 0; i < prevNum; i++) {
                    ss += temp;
                }
                temp = prevS + ss;
                num = 0;
            }
        }
        return temp;
    }
};