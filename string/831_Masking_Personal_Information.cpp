// 2023.04.01
class Solution {
public:
    vector<string> prefix = {"***-***-", "+*-***-***-", "+**-***-***-", "+***-***-***-"};
    string maskPII(string s) {
        string res = "";
        int at = s.find('@');
        if(at != string::npos) {
            res += s[0] >= 'a' && s[0] <= 'z'? s[0] : s[0] + 32;
            res += "*****";
            res += s[at - 1] >= 'a' && s[at - 1] <= 'z' ? s[at - 1] : s[at - 1] + 32;
            res += '@'; 
            for(int i = at + 1; i < s.size(); i++) {
                if(s[i] == '.') {
                    res += '.';
                    continue;
                }
                res += s[i] >= 'a' && s[i] <= 'z' ? s[i] : s[i] + 32;
            }
        }
        else {
            int cnt = 0;
            for(int i = 0; i < s.size(); i++) {
                if(s[i] >= '0' && s[i] <= '9') {
                    cnt++;
                }
            }
            res += prefix[cnt - 10];
            string temp = "";
            for(int i = s.size() - 1, tail = 0; i >= 0 && tail < 4; i--) {
                if(s[i] >= '0' && s[i] <= '9') {
                    temp = s[i] + temp;
                    tail++;
                }
            }
            res += temp;
        }
        return res;
    }
};