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