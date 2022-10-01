// 2022.08.29 sorted
class Solution {
public:
    bool check(string& s) {
        for(int i = 1; i < s.size(); i++) {
            if(s[i - 1] == '0' && s[i] == '1') {
                return false;
            }
        }
        return true;
    }
    int secondsToRemoveOccurrences(string s) {
        int n = s.size();
        int res = 0;
        while(!check(s)) {
            for(int i = 1; i < n; i++) {
                if(s[i - 1] == '0' && s[i] == '1') {
                    s[i - 1] = '1';
                    s[i] = '0';
                    i++;
                }
            }
            res++;
        }
        return res;
    }
};

// 2022.10.01
https://leetcode.cn/problems/time-needed-to-rearrange-a-binary-string/solution/by-endlesscheng-pq2x/
class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int n = s.size();
        int pre = 0;
        int f = 0;
        for(auto& c : s) {
            if(c == '0') {
                pre++;
            }
            else if(pre) {
                f = max(f + 1, pre);
            }
        }
        return f;
    }
};