// 2022.08.29 sorted
class Solution {
public:
    string removeStars(string s) {
        stack<char> stk;
        for(auto& c : s) {
            if(c != '*') {
                stk.push(c);
            }
            else {
                if(!stk.empty()) {
                    stk.pop();
                }
            }
        }
        string res = "";
        while(!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};