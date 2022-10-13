// 2022.10.13
class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        int n = s.size();
        unordered_map<char, int> map;
        map['I'] = 1;
        map['V'] = 5;
        map['X'] = 10;
        map['L'] = 50;
        map['C'] = 100;
        map['D'] = 500;
        map['M'] = 1000;
        for(int i = 0; i < n; i++) {
            if(i + 1 < n && map[s[i]] < map[s[i + 1]]) {
                int temp = 0;
                if(s[i] == 'I') {
                    if(s[i + 1] == 'V') {
                        temp = 4;
                    }
                    else {
                        temp = 9;
                    }
                }
                else if(s[i] == 'X') {
                    if(s[i + 1] == 'L') {
                        temp = 40;
                    }
                    else {
                        temp = 90;
                    }
                }
                else {
                    if(s[i + 1] == 'D') {
                        temp = 400;
                    }
                    else {
                        temp = 900;
                    }
                }
                res += temp;
                i++;
            }
            else {
                res += map[s[i]];
            }
        }
        return res;
    }
};

// optim
class Solution {
private:
    unordered_map<char, int> map = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
        {'E', -7777},
    };

public:
    int romanToInt(string s) {
        int n = s.size();
        s += 'E';
        int res = 0;
        for(int i = 0; i < n; i++) {
            if(map[s[i]] < map[s[i + 1]]) {
                res -= map[s[i]];
            }
            else {
                res += map[s[i]];
            }
        }
        return res;
    }
};