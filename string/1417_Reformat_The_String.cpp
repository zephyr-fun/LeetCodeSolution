// 2022.08.11
class Solution {
public:
    string reformat(string s) {
        string a = "";
        string b = "";
        for(auto c : s) {
            if(c >= 'a' && c <= 'z') {
                a += c;
            }
            else {
                b += c;
            }
        }
        if(abs((int)a.size() - (int)b.size()) > 1) {
            return "";
        }
        if(a.size() < b.size()) {
            string temp = a;
            a = b;
            b = temp;
        }
        string res = "";
        int i = 0;
        int j = 0;
        while(i < a.size() || j < b.size()) {
            if(i < a.size()) {
                res += a[i];
                i++;
            }
            if(j < b.size()) {
                res += b[j];
                j++;
            }
        }
        return res;
    }
};