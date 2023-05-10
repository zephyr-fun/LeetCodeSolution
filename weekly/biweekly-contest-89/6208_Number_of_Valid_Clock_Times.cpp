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

// 2023.05.09
class Solution {
public:
    int countTime(string time) {
        int h = 0;
        int m = 0;
        string hh = time.substr(0, 2);
        string mm = time.substr(3);
        if(hh[0] == '?' && hh[1] == '?') {
            h = 24;
        }
        else if(hh[0] != '?' && hh[1] != '?') {
            h = 1;
        }
        else if(hh[0] != '?') {
            if(hh[0] == '2') {
                h = 4;
            }
            else {
                h = 10;
            }
        }
        else {
            if(hh[1] <= '3') {
                h = 3;
            }
            else {
                h = 2;
            }
        }

        if(mm[0] == '?' && mm[1] == '?') {
            m = 60;
        }
        else if(mm[0] != '?' && mm[1] != '?') {
            m = 1;
        }
        else if(mm[0] != '?') {
            m = 10;
        }
        else {
            m = 6;
        }
        return h * m;
    }
};