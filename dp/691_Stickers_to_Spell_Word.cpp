// 2022.05.14
// memory search + dfs
class Solution {
    static const int M = 1 << 17;
    int INF = 50;
    // vector<int> dp(M, 0); // array fast
    int dp[M];
    vector<string> ss;
    string t;
public:
    int minStickers(vector<string>& stickers, string target) {
        ss = stickers;
        t = target;
        memset(dp, -1, sizeof(dp));
        int res = dfs(0);
        return res == INF ? -1 : res;
    }
    int dfs(int state) {
        int size = t.size();
        if(state == (1 << size) - 1) { // current state is full
            return 0;
        }
        if(dp[state] != -1) { // memory
            return dp[state];
        }
        int res = INF;
        for(auto s : ss) { // inf use of each ss
            int nextState = state;
            for(auto c : s) {
                for(int i = 0; i < size; i++) {
                    if(c == t[i] && ((nextState >> i) & 1) == 0) {
                        nextState |= (1 << i);
                        break;
                    }
                }
            }
            if(nextState != state) {
                res = min(res, dfs(nextState) + 1);
            }
        }
        dp[state] = res;
        return res;
    }
};