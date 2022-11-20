// 2022.04.11
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for(int j = 0; j <= s.size(); j++){
            for(int i = 0; i < j; j++){
                string word = s.substr(i, j - i);
                if(wordDict.find(word) != wordDict.end() && dp[i]){
                    dp[j] = true;
                }
            }
        }
        return dp[s.size()];
    }
};

// 2022.11.20
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        unordered_set<string> set;
        for(auto& word : wordDict) {
            set.insert(word);
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= i && !dp[i]; j++) {
                string temp = s.substr(j - 1, i - j + 1);
                if(set.count(temp)) {
                    dp[i] = dp[j - 1];
                }
            }
        }
        return dp[n];
    }
};