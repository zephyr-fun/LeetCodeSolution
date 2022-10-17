// 2022.10.15
class Solution {
public:
    int countTime(string time) {
        string h = time.substr(0, 2);
        string m = time.substr(3, 2);
        int hh = 0;
        int mm = 0;
        if(h[0] == '?' && h[1] == '?') {
            hh = 24;
        }
        else if(h[0] != '?' && h[1] != '?') {
            hh = 1;
        }
        else if(h[0] == '?') {
            if(h[1] < '4') {
                hh = 3;
            }
            else {
                hh = 2;
            }
        }
        else {
            if(h[0] == '2') {
                hh = 4;
            }
            else {
                hh = 10;
            }
        }
        
        if(m[0] == '?' && m[1] == '?') {
            mm = 60;
        }
        else if(m[0] != '?' && m[1] != '?') {
            mm = 1;
        }
        else if(m[0] == '?') {
            mm = 6;
        }
        else {
            mm = 10;
        }
        return hh * mm;
    }
};