// 2022.10.01
class Solution {
public:
    string reformatNumber(string number) {
        string temp = "";
        string res = "";
        for(auto& c : number) {
            if(c >= '0' && c <= '9') {
                temp += c;
            }
        }
        int n = temp.size();
        int idx = 0;
        while(n > 4) {
            for(int i = 0; i < 3; i++) {
                res += temp[idx];
                idx++;
            }
            res += '-';
            n -= 3;
        }
        if(n == 2 || n == 3) {
            res += temp.substr(idx);
        }
        else {
            res += temp.substr(idx, 2);
            res += '-';
            res += temp.substr(idx + 2);
        }
        return res;
    }
};