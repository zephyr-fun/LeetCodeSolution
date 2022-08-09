// 2022.08.09
class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> st;
        for(auto& digit : num) {
            while(st.size() != 0 && st.back() > digit && k) {
                st.pop_back();
                k--;
            }
            st.push_back(digit);
        }

        while(k) {
            st.pop_back();
            k--;
        }
        string res = "";
        bool zero = true;
        for(auto& digit : st) {
            if(zero && digit == '0') {
                continue;
            }
            zero = false;
            res += digit;
        }
        return res == "" ? "0" : res;
    }
};