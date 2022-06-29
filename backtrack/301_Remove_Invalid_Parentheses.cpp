// 2022.06.24
// 合法括号的两个性质
// 1.左括号数量 == 右括号数量
// 2.合法序列的任意前缀，左括号数量大于等于右括号数量
// left bracket count 1 score, right bracket count -1 score
class Solution {
public:
    unordered_set<string> set;
    string path;
    string s;
    int n;
    int maxVal;
    int len;
    vector<string> removeInvalidParentheses(string s_) {
        s = s_;
        n = s.size();
        int l = 0;
        int r = 0;
        len = 0;
        for(auto c : s) {
            if(c == '(') {
                l++;
            }
            else if(c == ')') {
                r++;
            }
        }
        maxVal = min(l, r);
        dfs(0, "", 0);
        return vector<string>(set.begin(), set.end());
    }
    void dfs(int u, string cur, int score) {
        if(score < 0 || score > maxVal) {
            return ;
        }
        if(u == n) {
            if(score == 0 && cur.size() >= len) {
                if(cur.size() > len) {
                    len = cur.size();
                    set.clear();
                }
                set.insert(cur);
            }
            return ;
        }
        if(s[u] == '(') {
            dfs(u + 1, cur + '(', score + 1);
            dfs(u + 1, cur, score);
        }
        else if(s[u] == ')') {
            dfs(u + 1, cur + ')', score - 1);
            dfs(u + 1, cur, score);
        }
        else {
            dfs(u + 1, cur + s[u], score);
        }
    }
};

// change the defination of l, r, and add extra cut 
// 用优先级保证了括号分段的删除处理
// 举例：())(()
// l: 1 0 0 1 2 1
// r: 0 0 1 1 1 1
class Solution {
public:
    unordered_set<string> set;
    string path;
    string s;
    int n;
    int maxVal;
    int len;
    vector<string> removeInvalidParentheses(string s_) {
        s = s_;
        n = s.size();
        int left = 0; // left bracket cnt
        int right = 0;// right bracket cnt
        int l = 0; // left - right
        int r = 0; // right needs to be removed
        for(auto c : s) {
            if(c == '(') {
                l++;
                left++;
            }
            else if(c == ')') {
                if(l == 0) {
                    r++;
                }
                else {
                    l--;
                }
                right++;
            }
        }
        len = n - l - r;
        maxVal = min(left, right);
        dfs(0, "", l, r, 0);
        return vector<string>(set.begin(), set.end());
    }
    void dfs(int u, string cur, int l, int r, int score) {
        if(l < 0 || r < 0 || score < 0 || score > maxVal) {
            return ;
        }
        if(l == 0 && r == 0) {
            if(cur.size() == len) {
                set.insert(cur);
                return ;
            }
        }
        if(u == n) {
            return ;
        }
        if(s[u] == '(') {
            dfs(u + 1, cur + '(', l, r, score + 1);
            dfs(u + 1, cur, l - 1, r, score);
        }
        else if(s[u] == ')') {
            dfs(u + 1, cur + ')', l, r, score - 1);
            dfs(u + 1, cur, l, r - 1, score);
        }
        else {
            dfs(u + 1, cur + s[u], l, r, score);
        }
    }
};

// yxc version
class Solution {
public:
    vector<string> res;
    vector<string> removeInvalidParentheses(string s) {
        int l = 0;
        int r = 0;
        for(auto c : s) {
            if(c == '(') {
                l++;
            }
            else if(c == ')') {
                if(l == 0) {
                    r++;
                }
                else {
                    l--;
                }
            }
        }
        dfs(s, 0, "", 0, l, r);
        return res;
    }
    void dfs(string& s, int u, string path, int cnt, int l, int r) {
        if(u == s.size()) {
            if(!cnt) {
                res.push_back(path);
            }
            return ;
        }
        if(s[u] != '(' && s[u] != ')') {
            dfs(s, u + 1, path + s[u], cnt, l ,r);
        }
        else if(s[u] == '(') {
            int k = u;
            while(k < s.size() && s[k] == '(') {
                k++;
            }
            l -= k - u;
            for(int i = k - u; i >= 0; i--) {
                if(l >= 0) {
                    dfs(s, k, path, cnt, l, r);
                }
                path += '(';
                cnt++;
                l++;
            }
        }
        else if(s[u] == ')') {
            int k = u;
            while(k < s.size() && s[k] == ')') {
                k++;
            }
            r -= k - u;
            for(int i = k - u; i >= 0; i--) {
                if(cnt >= 0 && r >= 0) {
                    dfs(s, k, path, cnt, l, r);
                }
                path += ')';
                cnt--;
                r++;
            }
        }
    }
};

// 2022.06.29
// reason why we use set is as following
// ()()(()
// delete 4/5 results in the same string ()()()
class Solution {
public:
    unordered_set<string> set;
    string s;
    int maxVal;
    int n;
    int len;
    vector<string> removeInvalidParentheses(string s_) {
        s = s_;
        n = s.size();
        int l = 0;
        int r = 0;
        int left = 0;
        int right = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                l++;
                left++;
            }
            else if(s[i] == ')'){
                if(l > 0) {
                    l--;
                }
                else {
                    r++;
                }
                right++;
            }
        }
        len = n - l - r;
        maxVal = min(left, right);
        dfs(0, "", l, r, 0);
        return vector<string>(set.begin(), set.end());
    }
    void dfs(int cur, string path, int l, int r, int score) {
        if(l < 0 || r < 0 || score < 0 || score > maxVal) {
            return ;
        }
        if(l == 0 && r == 0) {
            if(path.size() == len) {
                set.insert(path);
                return ;
            }
        }
        if(cur == n) {
            return ;
        }
        if(s[cur] == '(') {
            dfs(cur + 1, path + '(', l, r, score + 1);
            dfs(cur + 1, path, l - 1, r, score);
        }
        else if(s[cur] == ')') {
            dfs(cur + 1, path + ')', l, r, score - 1);
            dfs(cur + 1, path, l, r - 1, score);
        }
        else {
            dfs(cur + 1, path + s[cur], l, r, score);
        }
    }
};

// yxc version
class Solution {
public:
    string s;
    vector<string> res;
    vector<string> removeInvalidParentheses(string s_) {
        s = s_;
        int n = s.size();
        int l = 0;
        int r = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                l++;
            }
            else if(s[i] == ')'){
                if(l > 0) {
                    l--;
                }
                else {
                    r++;
                }
            }
        }
        dfs(0, "", 0, l, r);
        return res;
    }
    void dfs(int cur, string path, int cnt, int l, int r) { // cnt means left - right, which can't be negative in a legal prefix
        if(cur == s.size()) {
            if(!cnt) {
                res.emplace_back(path);
            }
            return ;
        }
        if(s[cur] != '(' && s[cur] != ')') {
            dfs(cur + 1, path + s[cur], cnt, l, r);
        }
        else if(s[cur] == '(') {
            int k = cur;
            while(k < s.size() && s[k] == '(') {
                k++;
            }
            l -= k - cur;
            for(int i = k - cur; i >= 0; i--) {
                if(l >= 0) { // l ensures that no more than 'at least num' left brackets are removed
                    dfs(k, path, cnt, l, r);
                }
                path += '(';
                l++;
                cnt++;
            }
        }
        else if(s[cur] == ')'){
            int k = cur;
            while(k < s.size() && s[k] == ')') {
                k++;
            }
            r -= k - cur;
            for(int i = k - cur; i >= 0; i--) {
                if(cnt >= 0 && r >= 0) { // r ensures that no more than 'at least num' left brackets are removed
                    dfs(k, path, cnt, l, r);
                }
                path += ')';
                r++;
                cnt--;
            }
        }
    }
};