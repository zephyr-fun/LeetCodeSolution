// 2022.09.04
int son[40020][26];
int cnt[40020];
class StreamChecker {
public:
    string cur;
    int idx;
    void insert(string& s) {
        int p = 0;
        for(auto c : s) {
            int u = c - 'a';
            if(!son[p][u]) {
                idx++;
                son[p][u] = idx;
            }
            p = son[p][u];
        }
        cnt[p]++;
    }

    StreamChecker(vector<string>& words) {
        idx = 0;
        cur = "";
        // son.resize(1e6 + 7, vector<int>(26, 0));
        // cnt.resize(1e6 + 7, 0);
        memset(son, 0, sizeof(son));
        memset(cnt, 0, sizeof(cnt));
        for(auto word : words) {
            reverse(word.begin(), word.end());
            insert(word);
        }
    }
    
    bool query(char letter) {
        cur += letter; // TLE for cur = cur + letter
        int p = 0;
        for(int i = cur.size() - 1; i >= 0; i--) {
            int u = cur[i] - 'a';
            if(!son[p][u]) {
                return false;
            }
            p = son[p][u];
            if(cnt[p]) {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */

// 2022.09.25
int son[40020][26];
int cnt[40020];
class StreamChecker {
public:
    string cur;
    int idx;
    StreamChecker(vector<string>& words) {
        cur = "";
        idx = 0;
        memset(son, 0, sizeof(son));
        memset(cnt, 0, sizeof(cnt));
        for(auto& word : words) {
            insert(word);
        }
    }
    
    void insert(string& s) {
        int p = 0;
        for(int i = s.size() - 1; i >= 0; i--) {
            int u = s[i] - 'a';
            if(!son[p][u]) {
                idx++;
                son[p][u] = idx;
            }
            p = son[p][u];
        }
        cnt[p]++;
    }

    bool query(char letter) {
        cur += letter; // TLE for cur = cur + letter, again
        int p = 0;
        for(int i = cur.size() - 1; i >= 0; i--) {
            int u = cur[i] - 'a';
            if(!son[p][u]) {
                return false;
            }
            p = son[p][u];
            if(cnt[p]) {
                return true;
            }
        }
        return false;
    }
};

// 2023.03.24
static int son[40007][26];
static int cnt[40007];
class StreamChecker {
public:
    int idx;
    string cur;
    void insert(string s) {
        int p = 0;
        for(int i = s.size() - 1; i >= 0; i--) {
            int v = s[i] - 'a';
            if(!son[p][v]) {
                son[p][v] = ++idx;
            }
            p = son[p][v];
        }
        cnt[p]++;
    }
    StreamChecker(vector<string>& words) {
        idx = 0;
        cur = "";
        memset(son, 0, sizeof(son));
        memset(cnt, 0, sizeof(cnt));
        for(auto& word : words) {
            insert(word);
        }
    }
    
    bool query(char letter) {
        cur += letter;
        int p = 0;
        for(int i = cur.size() - 1; i >= 0; i--) {
            int u = cur[i] - 'a';
            if(!son[p][u]) {
                return false;
            }
            p = son[p][u];
            if(cnt[p]) {
                return true;
            }
        }
        return false;
    }
};

// 2023.05.11
static int son[40007][26];
static int cnt[40007];
class StreamChecker {
public:
    string cur;
    int idx;
    void insert(string& word) {
        int p = 0;
        for(int i = word.size() - 1; i >= 0; i--) {
            int u = word[i] - 'a';
            if(!son[p][u]) {
                son[p][u] = ++idx;
            }
            p = son[p][u];
        }
        cnt[p]++;
    }

    StreamChecker(vector<string>& words) {
        idx = 0;
        memset(son, 0, sizeof(son));
        memset(cnt, 0, sizeof(cnt));
        for(auto& word : words) {
            insert(word);
        }
    }
    
    bool query(char letter) {
        cur += letter;
        int p = 0;
        for(int i = cur.size() - 1; i >= 0; i--) {
            int u = cur[i] - 'a';
            if(!son[p][u]) {
                return false;
            }
            p = son[p][u];
            if(cnt[p]) {
                break; // optim
            }
        }
        return cnt[p];
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */