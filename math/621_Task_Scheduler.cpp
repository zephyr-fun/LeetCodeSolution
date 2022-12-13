// 2022.08.07
class Solution {
public:
    int leastInterval(vector<char>& tasks, int len) {
        int n = tasks.size();
        int len1 = n;
        unordered_map<char, int> map;
        for(int i = 0; i < n; i++) {
            map[tasks[i]]++;
        }
        int maxVal = 0;
        int cnt = 0;
        for(auto [k, v] : map) {
            if(v > maxVal) {
                maxVal = v;
                cnt = 1;
            }
            else if(v == maxVal) {
                cnt++;
            }
        }
        int len2 = (maxVal - 1) * (len + 1) + cnt;
        return max(len1, len2);
    }
};

// 2022.10.24
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int maxVal = 0;
        int cnt = 0;
        unordered_map<char, int> map;
        int len1 = tasks.size();
        for(auto& t : tasks) {
            map[t]++;
            if(map[t] > maxVal) {
                maxVal = map[t];
                cnt = 1;
            }
            else if(map[t] == maxVal) {
                cnt++;
            }
        }
        int len2 = (maxVal - 1) * (n + 1) + cnt;
        return max(len1, len2);
    }
};

// 2022.10.26
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int m = tasks.size();
        int len1 = m;
        int len2 = 0;
        unordered_map<int, int> map;
        int cnt = 0;
        int tot = 1;
        for(int i = 0; i < m; i++) {
            map[tasks[i]]++;
            if(map[tasks[i]] > cnt) {
                cnt = map[tasks[i]];
                tot = 1;
            }
            else if(map[tasks[i]] == cnt) {
                tot++;
            }
        }
        len2 = (cnt - 1) * (n + 1) + tot;
        return max(len1, len2);
    }
};

// 2022.12.13
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int maxFrq = 0;
        int cnt = 0;
        int frq[26];
        memset(frq, 0, sizeof(frq));
        int candiLen = tasks.size();
        for(auto& c : tasks) {
            frq[c - 'A']++;
            if(frq[c - 'A'] > maxFrq) {
                maxFrq = frq[c - 'A'];
                cnt = 1;
            }
            else if(frq[c - 'A'] == maxFrq) {
                cnt++;
            }
        }
        return max((maxFrq - 1) * (n + 1) + cnt, candiLen);
    }
};