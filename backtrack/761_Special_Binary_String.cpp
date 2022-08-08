// 2022.08.08
class Solution {
public:
    string makeLargestSpecial(string s) {
        if(s.size() <= 2) {
            return s;
        }
        vector<string> vali;
        string temp;
        int cnt = 0;
        for(auto c : s) {
            temp += c;
            if(c == '1') {
                cnt++;
            }
            else {
                cnt--;
                if(cnt == 0) {
                    vali.emplace_back('1' + makeLargestSpecial(temp.substr(1, temp.size() - 2)) + '0');
                    temp.clear();
                }
            }
        }
        sort(vali.begin(), vali.end(), [](string& a, string& b) {
            return a + b > b + a;
        });
        string res;
        for(auto va : vali) {
            res += va;
        }
        return res;
    }
};