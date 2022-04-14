// 2022.04.14
// dp
class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int res = 0;
        for(int i = s.size() - 1; i >= 0; i--){
            for(int j = i; j < s.size(); j++){
                if(s[i] == s[j]){
                    if(j - i <= 1){
                        dp[i][j] = true;
                        res++;
                    }
                    else if(dp[i + 1][j - 1]){
                        dp[i][j] = true;
                        res++;
                    }
                }
            }
        }
        return res;
    }
};

// so fast 100% & 95.84%
// double pointers
class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        for(int i = 0; i < s.size(); i++){
            res += extend(s, i, i, s.size());
            res += extend(s, i, i + 1, s.size());
        }
        return res;
    }
    int extend(string& s, int left, int right, int size){
        int res = 0;
        while(left >= 0 && right < size && s[left] == s[right]){
            res++;
            left--;
            right++;
        }
        return res;
    }
};