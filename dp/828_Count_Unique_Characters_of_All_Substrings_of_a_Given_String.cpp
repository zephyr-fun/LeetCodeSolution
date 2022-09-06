// 2022.09.06
class Solution {
public:
    int uniqueLetterString(string s) {
        int n = s.size();
        int res = 0;
        int temp = 0;
        int last0[26];
        int last1[26];
        memset(last0, -1, sizeof(last0));
        memset(last1, -1, sizeof(last1));
        for(int i = 0; i < n; i++) {
            int c = s[i] - 'A';
            temp += i - last0[c]; // substrings between i and last0 will gain a new single c, which means res of countUniqueChars() for each one of them will +1
            temp -= last0[c] - last1[c]; //  substrings between last0 and last1 will gain another c(they already have one previously), which means res of countUniqueChars() for each one of them will -1
            res += temp;
            last1[c] = last0[c];
            last0[c] = i;
        }
        return res;
    }
};