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

// 2022.11.29
int N = 20;
int M = 1 << 20;
int INF = 50;
int dp[1 << 20];
class Solution {
public:
    vector<string> ss;
    string t;
    int dfs(int state) {
        int n = t.size();
        if(state == ((1 << n)) - 1) {
            return 0;
        }
        if(dp[state] != -1) {
            return dp[state];
        }
        int res = INF;
        for(auto s : ss) {
            int nstate = state;
            for(auto c : s) {
                for(int i = 0; i < n; i++) {
                    if(t[i] == c && ((nstate >> i) & 1) == 0) {
                        nstate |= (1 << i);
                        break;
                    }
                }
            }
            if(nstate != state) {
                res = min(res, dfs(nstate) + 1);
            }
        }
        dp[state] = res;
        return res;
    }
    int minStickers(vector<string>& stickers, string target) {
        memset(dp, -1, sizeof(dp));
        ss = stickers;
        t = target;
        int res = dfs(0);
        return res == INF ? -1 : res;
    }
};

// dp
class Solution {
public:
    int minStickers(vector<string>& ss, string t) {
        int INF = 20;
        int n = ss.size();
        int m = t.size();
        int mask = 1 << m;
        vector<int> dp(mask, INF);
        dp[0] = 0;
        for(int state = 0; state < mask; state++) {
            if(dp[state] == INF) {
                continue;
            }
            for(auto s : ss) {
                int nstate = state;
                int len = s.size();
                for(int i = 0; i < len; i++) {
                    int c = s[i] - 'a';
                    for(int j = 0; j < m; j++) {
                        if(t[j] - 'a' == c && ((nstate >> j) & 1) == 0) {
                            nstate |= (1 << j);
                            break;
                        }
                    }
                }
                dp[nstate] = min(dp[nstate], dp[state] + 1);
            }
        }
        return dp[mask - 1] == INF ? -1 : dp[mask - 1];
    }
};