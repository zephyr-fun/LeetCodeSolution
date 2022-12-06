class Solution {
public:
    vector<vector<string>> res;
    vector<string> path;
    bool palindrome(string& s, int start, int end){
        for(int left = start, right = end; left < right; left++, right--){
            if(s[left] != s[right]){
                return false;
            }
        }
        return true;
    }
    void backtracking(string& s, int startIndex){
        if(startIndex >= s.size()){
            res.push_back(path);
            return ;
        }
        for(int i = startIndex; i < s.size(); i++){
            if(palindrome(s, startIndex, i)){
                string temp = s.substr(startIndex, i - startIndex + 1);
                path.push_back(temp);
                backtracking(s, i + 1);
                path.pop_back();
            }
            else{
                continue;
            }
        }
    }
    vector<vector<string>> partition(string s) {
        backtracking(s, 0);
        return res;
    }
};

// 2022.04.04
class Solution {
public:
    vector<vector<string>> res;
    vector<string> path;
    bool palindrome(string& s, int start, int end){
        for(int left = start, right = end; left < right; left++, right--){
            if(s[left] != s[right]){
                return false;
            }
        }
        return true;
    }
    void backtracking(string& s, int startIndex){
        if(startIndex >= s.size()){
            res.push_back(path);
            return ;
        }
        for(int i = startIndex; i < s.size(); i++){
            if(palindrome(s, startIndex, i)){
                string temp = s.substr(startIndex, i - startIndex + 1);
                path.push_back(temp);
                backtracking(s, i + 1); // actually startIndex and i form the left and right bounder of a sliding window
                path.pop_back();
            }
            else{
                continue;
            }
        }
    }
    vector<vector<string>> partition(string s) {
        backtracking(s, 0);
        return res;
    }
};

// 2022.06.22
// backtracking
class Solution {
public:
    vector<vector<string>> res;
    vector<string> path;
    bool palindrome(string& s, int start, int end) {
        for(int i = start, j = end; i <= j; i++, j--) {
            if(s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }
    void backtracking(string& s, int startIndex) {
        if(startIndex >= s.size()) {
            res.emplace_back(path);
            return ;
        }
        for(int i = startIndex; i < s.size(); i++) {
            if(palindrome(s, startIndex, i)) {
                string temp = s.substr(startIndex, i - startIndex + 1);
                path.emplace_back(temp);
                backtracking(s, i + 1);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        backtracking(s, 0);
        return res;
    }
};

// dp
class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        // use dp to "preprocess" if(s[i] to s[j]) is a palindrome
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int j = 0; j < n; j++) {
            for(int i = j; i >= 0; i--) {
                if(i == j) {
                    dp[i][j] = true;
                }
                else if(j - i + 1 == 2) {
                    dp[i][j] = s[i] == s[j];
                }
                else {
                    dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
                }
            }
        }
        vector<vector<string>> res;
        vector<string> path;
        dfs(s, 0, res, path, dp);
        return res;

    }
    void dfs(string& s, int startIndex, vector<vector<string>>& res, vector<string>& path, vector<vector<bool>>& dp) {
        int n = s.size();
        if(startIndex == n) {
            res.emplace_back(path);
            return;
        }
        for(int i = startIndex; i < n; i++) {
            if(dp[startIndex][i]) {
                path.emplace_back(s.substr(startIndex, i - startIndex + 1));
                dfs(s, i + 1, res, path, dp);
                path.pop_back();
            }
        }
    }
};

// 2022.06.29
class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int j = 0; j < n; j++) {
            for(int i = j; i >= 0; i--) {
                if(i == j) {
                    dp[i][j] = true;
                }
                else if(j - i + 1 == 2) {
                    dp[i][j] = s[i] == s[j];
                }
                else {
                    dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j];
                }
            }
        }
        vector<vector<string>> res;
        vector<string> path;
        dfs(s, 0, res, path, dp);
        return res;
    }
    void dfs(string& s, int startIdx, vector<vector<string>>& res, vector<string>& path, vector<vector<bool>>& dp) {
        if(startIdx == s.size()) {
            res.emplace_back(path);
            return ;
        }
        for(int i = startIdx; i < s.size(); i++) {
            if(dp[startIdx][i]) {
                path.emplace_back(s.substr(startIdx, i - startIdx + 1));
                dfs(s, i + 1, res, path, dp);
                path.pop_back();
            }
        }
    }
};

// 2022.12.06
class Solution {
public:
    string s;
    vector<vector<string>> res;
    vector<string> path;
    bool isPalindrome2(int start, int end) {
        int l = start;
        int r = end;
        while(l < r) {
            if(s[l] == s[r]) {
                l++;
                r--;
            }
            else {
                return false;
            }
        }
        return true;
    }
    bool isPalindrome(string temp) {
        int n = temp.size();
        int l = 0;
        int r = n - 1;
        while(l < r) {
            if(temp[l] == temp[r]) {
                l++;
                r--;
            }
            else {
                return false;
            }
        }
        return true;
    }
    void dfs(int cur) {
        if(cur == s.size()) {
            res.emplace_back(path);
            return ;
        }
        for(int i = cur; i < s.size(); i++) {
            if(isPalindrome(cur, i)) {
                path.emplace_back(s.substr(cur, i - cur + 1));
                dfs(i + 1);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s_) {
        s = s_;
        dfs(0);
        return res;
    }
};