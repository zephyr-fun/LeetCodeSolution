// 2023.02.26
class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int res = 0;
        int n = words.size();
        int cnt[26];
        memset(cnt, 0, sizeof(cnt));
        for(auto& letter : letters) {
            cnt[letter - 'a']++;
        }
        function<void(int, int)> dfs = [&] (int i, int total) {
            if(i < 0) {
                res = max(res, total);
                return ;
            }
            dfs(i - 1, total);
            bool ok = true;
            int sumup = 0;
            for(auto& c : words[i]) {
                if(cnt[c - 'a']-- == 0) {
                    ok = false;
                }
                sumup += score[c - 'a'];
            }
            if(ok) {
                dfs(i - 1, total + sumup);
            }
            for(auto& c : words[i]) {
                cnt[c - 'a']++;
            }
        };
        dfs(n - 1, 0);
        return res;
    }
};