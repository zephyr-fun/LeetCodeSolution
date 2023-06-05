// 2022.05.13
// string hash + dp
class Solution {
public:
    int P = 131, OFFSET = 128;
    unordered_set<unsigned long long> set;
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        int size = words.size();
        // preprocess string to a hash set
        for(int i = 0; i < size; i++) {
            unsigned long long hash = 0;
            for(auto& letter : words[i]) {
                hash = hash * P + (letter - 'a') + OFFSET;
            }
            set.insert(hash);
        }
        vector<string> res;
        // for each word, use dp to process it
        for(auto word : words) {
            if(check(word)) {
                res.push_back(word);
            }
        }
        return res;
    }
    bool check(string word) {
        int size = word.size();
        // dp[j], considering the first j chars, the maximum ways to get item
        vector<int> dp(size + 1, -1);
        dp[0] = 0;
        for(int i = 0; i <= size; i++) {
            if(dp[i] == -1) {
                continue;
            }
            unsigned long long cur = 0;
            // i->j form a word in set
            for(int j = i + 1; j <= size; j++) {
                cur = cur * P + (word[j - 1] - 'a') + OFFSET;
                if(set.count(cur)) {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
            cout << "i:" << i << endl;
            for(int k = 0; k <= size; k++) {
                cout << dp[k];
            }
            cout << endl;
            if(dp[size] > 1) {
                    return true;
            }
        }
        return false;
    }
};


// ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]

// ["catsdogcats","dogcatsdog","ratcatdogcat"]

// i:0
// 0,-1,-1,1,
// i:3
// 0,-1,-1,1,

// i:0
// 0,-1,-1,1,1,
// i:3
// 0,-1,-1,1,1,
// i:4
// 0,-1,-1,1,1,

// i:0
// 0,-1,-1,1,1,-1,-1,-1,-1,-1,-1,1,
// i:3
// 0,-1,-1,1,1,-1,-1,-1,-1,-1,-1,1,
// i:4
// 0,-1,-1,1,1,-1,-1,2,-1,-1,-1,1,
// i:7
// 0,-1,-1,1,1,-1,-1,2,-1,-1,3,3,

// i:0
// 0,-1,-1,1,
// i:3
// 0,-1,-1,1,
// i:0
// 0,-1,-1,1,-1,-1,-1,-1,-1,-1,1,
// i:3
// 0,-1,-1,1,-1,-1,2,2,-1,-1,1,
// i:6
// 0,-1,-1,1,-1,-1,2,2,-1,-1,1,
// i:7
// 0,-1,-1,1,-1,-1,2,2,-1,-1,3,
// i:0
// 0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,
// i:14
// 0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,
// i:0
// 0,-1,-1,1,
// i:3
// 0,-1,-1,1,
// i:0
// 0,-1,-1,1,-1,-1,-1,-1,-1,-1,-1,-1,1,
// i:3
// 0,-1,-1,1,-1,-1,2,-1,-1,-1,-1,-1,1,
// i:6
// 0,-1,-1,1,-1,-1,2,-1,-1,3,-1,-1,1,
// i:9
// 0,-1,-1,1,-1,-1,2,-1,-1,3,-1,-1,4,

// 2022.06.14
// hash + dp
class Solution {
public:
    // 13, 131, 1313, 13131......
    int P = 131, OFFSET = 128;
    unordered_set<unsigned long long> set;
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        int size = words.size();
        // preprocess string to a hash set
        for(int i = 0; i < size; i++) {
            unsigned long long hash = 0;
            for(auto& letter : words[i]) {
                hash = hash * P + (letter - 'a') + OFFSET;
            }
            set.insert(hash);
        }
        vector<string> res;
        // for each word, use dp to process it
        for(auto word : words) {
            if(check(word)) {
                res.push_back(word);
            }
        }
        return res;
    }
    bool check(string word) {
        int size = word.size();
        // dp[j], considering the first j chars, the maximum ways to get item
        vector<int> dp(size + 1, -1);
        dp[0] = 0;
        for(int i = 0; i <= size; i++) {
            if(dp[i] == -1) {
                continue;
            }
            unsigned long long cur = 0;
            // i->j form a word in set
            for(int j = i + 1; j <= size; j++) {
                cur = cur * P + (word[j - 1] - 'a') + OFFSET;
                if(set.count(cur)) {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
            if(dp[size] > 1) {
                    return true;
            }
        }
        return false;
    }
};

// 2022.06.28
// dfs
class Solution {
public:
    vector<string> res;
    unordered_set<string> set;
    unordered_set<string> resSet;
    void dfs(string& word, int idx, int cnt) {
        if(idx == word.size() && cnt != 1) {
            resSet.insert(word);
        }
        for(int i = idx; i < word.size(); i++) {
            if(set.count(word.substr(idx, i - idx + 1))) {
                dfs(word, i + 1, cnt + 1);
            }
        }
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        for(auto word : words) {
            set.insert(word);
        }
        for(auto word : words) {
            dfs(word, 0, 0);
        }
        for(auto rs : resSet) {
            res.emplace_back(rs);
        }
        return res;
    }
};

// 2022.11.22
class Solution {
public:
    unordered_set<string> set;
    unordered_set<string> resSet;
    void dfs(string word, int idx, int cnt) {
        if(idx == word.size() && cnt != 1) {
            resSet.insert(word);
            return ;
        }
        for(int i = idx; i < word.size(); i++) {
            if(set.count(word.substr(idx, i - idx + 1))) {
                dfs(word, i + 1, cnt + 1);
            }
        }
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        for(auto& word : words) {
            set.insert(word);
        }
        for(auto& word : words) {
            dfs(word, 0, 0);
        }
        vector<string> res;
        for(auto& r : resSet) {
            res.emplace_back(r);
        }
        return res;
    }
};

// 2023.06.05
typedef unsigned long long ULL;
const int N = 1010, p = 13331;
int f[N];

class Solution {
public:
    unordered_set<ULL> hs;
    bool check(const string &s) {
        int n = s.size();
        memset(f, -1, sizeof(int) * (n + 1));
        f[0] = 0;
        for (int i = 0; i < n; ++i) {
            if (f[i] == -1) continue;
            ULL curr = 0;
            for (int j = i + 1; j <= n; ++j) {
                curr = curr * p + s[j - 1] - '0';
                if (hs.count(curr)) f[j] = max(f[j], f[i] + 1);
            }   
            if (f[n] > 1) return true;
        }
        return false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        int n = words.size();
        vector<string> res;
        // 先预处理出words[]中所有字符串的哈希值
        for (auto &s : words) {
            ULL curr = 0;
            for (auto x : s) {
                curr = curr * p + x - '0';
            }
            hs.insert(curr);
        }
        for (auto &s : words) {
            if (check(s)) res.push_back(s);
        }
        return res;
    }
};