// 2023.10.10
class Solution {
public:
    int splitNum(int num) {
        string n = to_string(num);
        sort(n.begin(), n.end());
        string n1 = "";
        string n2 = "";
        for (int i = 0; i < n.size(); i += 2) {
            n1 += n[i];
            if (i + 1 < n.size()) {
                n2 += n[i + 1];
            }
        }
        return stoi(n1) + stoi(n2);
    }
};

// optim
class Solution {
public:
    int splitNum(int num) {
        int cnt[10]{};
        int n = 0;
        while (num) {
            cnt[num % 10]++;
            num /= 10;
            n++;
        }
        int res[2] = {0, 0};
        for (int i = 0, j = 0; i < n; i++) {
            while (cnt[j] == 0) {
                j++;
            }
            res[i & 1] = res[i & 1] * 10 + j;
            cnt[j]--;
        }
        return res[0] + res[1];
    }
};

// optim 2
class Solution {
public:
    int splitNum(int num) {
        string s = to_string(num);
        int res[2]{};
        sort(s.begin(), s.end());
        for (int i = 0; i < s.size(); i++) {
            res[i & 1] = res[i & 1] * 10 + s[i] - '0';
        }
        return res[0] + res[1];
    }
};