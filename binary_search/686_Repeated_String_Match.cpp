// 2022.06.13
class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int an = a.size();
        int bn = b.size();
        int left = 1;
        int right = bn / an + 2;
        cout << right;
        int res = -1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            string cura = "";
            int cnt = mid;
            while(cnt > 0) {
                cura += a;
                cnt--;
            }
            if(cura.find(b) != string::npos) {
                res = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return res;
    }
};

// 2022.06.28
// brute force, no analyze
class Solution {
public:
    bool check(string& a, string& b) {
        if(a.size() < b.size() || a.find(b) == string::npos) {
            return false;
        }
        return true;
    }
    int repeatedStringMatch(string a, string b) {
        int n = a.size();
        int m = b.size();
        int left = 0;
        int right = m / n + 2;
        int res = -1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            string temp = "";
            for(int i = 0; i < mid; i++) {
                temp += a;
            }
            if(check(temp, b)) {
                res = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return res;
    }
};

// https://leetcode.cn/problems/repeated-string-match/solution/gong-shui-san-xie-yi-ti-san-jie-qia-chan-3hbr/
// analyze upper bound and lower bound
class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int lower = b.size() / a.size();
        if(b.size() % a.size() != 0) {
            lower += 1;
        }
        int upper = lower + 1;
        string low = "";
        for(int i = 0; i < lower; i++) {
            low += a;
        }
        string up = low + a;
        if(low.find(b) != string::npos) {
            return lower;
        }
        if(up.find(b) != string::npos) {
            return upper;
        }
        return -1;
    }
};

// 2022.12.18
class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int lower = b.size() / a.size();
        if(b.size() % a.size() != 0) {
            lower += 1;
        }
        int upper = lower + 1;
        string low = "";
        for(int i = 0; i < lower; i++) {
            low += a;
        }
        string up = low + a;
        if(low.find(b) != string::npos) {
            return lower;
        }
        if(up.find(b) != string::npos) {
            return upper;
        }
        return -1;
    }
};