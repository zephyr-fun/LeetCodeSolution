// 2022.06.15
// TLE without string hash
class Solution {
public:
    string longestDupSubstring(string s) {
        int n = s.size();
        int left = 1;
        int right = n;
        string res;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            string temp = check(s, mid, n);
            if(temp.size() != 0) {
                res = temp;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return res;
    }
    string check(string s, int len, int n) {
        unordered_set<string> set;
        string res;
        for(int i = 0; i <= n - len; i++) {
            string temp = s.substr(i, len);
            if(set.count(temp) > 0) {
                res = temp;
            }
            else {
                set.insert(temp);
            }
        }
        return res;
    }
};

// string hash
class Solution {
public:
    const int P = 131;
    vector<unsigned long long> h;
    vector<unsigned long long> p;
    unordered_set<unsigned long long> set;
    string longestDupSubstring(string s) {
        int n = s.size();
        h.resize(n + 7);
        p.resize(n + 7);
        p[0] = 1;
        for(int i = 0; i < n; i++) {
            p[i + 1] = p[i] * P;
            h[i + 1] = h[i] * P + s[i];
        }
        int left = 1;
        int right = n;
        string res;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            string temp = check(s, mid, n);
            if(temp.size() != 0) {
                res = temp;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return res;
    }
    string check(string s, int len, int n) {
        // cout << "len:" << len << endl;
        for(int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            unsigned long long cur = h[j] - h[i - 1] * p[j - i + 1];
            // cout << "cur" << cur << "str:" << s.substr(i - 1, len) << endl;
            if(set.count(cur)) {
                string res = s.substr(i - 1, len);
                return res;
            }
            else {
                set.insert(cur);
            }
        }
        return "";
    }
};

// 2022.06.27
// binary search without string hash TLE
class Solution {
public:
    string longestDupSubstring(string s) {
        int n = s.size();
        int left = 0;
        int right = n;
        string res = "";
        while(left <= right) {
            int mid = left + (right - left) / 2;
            unordered_map<string, int> map;
            for(int i = 0; i <= s.size() - mid; i++) {
                string temp = s.substr(i, mid);
                map[temp]++;
                if(map[temp] >= 2) {
                    res = temp;
                }
            }
            if(res.size() < mid) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return res;
    }
};

// string hash