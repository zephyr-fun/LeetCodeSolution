// 2022.08.03
// O(n^2), O(nlogn)
class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k == 1) {
            int n = s.size();
            string res = s;
            for(int i = 0; i < n; i++) {
                s = s.substr(1) + s[0];
                res = min(res, s);
            }
            return res;
        }
        sort(s.begin(), s.end());
        return s;
    }
};

// 最小表示法
class Solution {
public:
    string orderlyQueue(string s, int t) {
        if(t == 1) {
            int n = s.size();
            int i = 0;
            int j = 1;
            int k = 0;
            while(i < n && j < n && k < n) {
                if(s[(i + k) % n] == s[(j + k) % n]) {
                    k++;
                }
                else {
                    s[(i + k) % n] > s[(j + k) % n] ? i = i + k + 1 : j = j + k + 1;
                    if(i == j) {
                        i++;
                    }
                    k = 0;
                }
            }
            i = min(i, j);
            return s.substr(i) + s.substr(0, i);
        }
        sort(s.begin(), s.end());
        return s;
    }
};