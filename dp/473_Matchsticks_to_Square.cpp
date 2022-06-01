// 2022.06.01
// still need to think
class Solution {
public:
    int n;
    bool makesquare(vector<int>& matchsticks) {
        n = matchsticks.size();
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += matchsticks[i];
        }
        int len = 0;
        if(sum % 4 != 0) {
            return false;
        }
        else {
            len = sum / 4;
        }
        vector<bool> state(n, false);
        sort(matchsticks.begin(), matchsticks.end());
        reverse(matchsticks.begin(), matchsticks.end());
        for(auto m : matchsticks) {
            if(m > len) {
                return false;
            }
        }
        return dfs(0, state, 0, 0, len, matchsticks, 0);
    }
    bool dfs(int idx, vector<bool>& state, int curNum, int curLen, int len, vector<int>& matchsticks, int cnt) {
        if(curLen == len) {
            return dfs(0, state, curNum + 1, 0, len, matchsticks, cnt);
        }
        if(cnt >= n) {
            if(curNum == 4 && curLen == 0) {
                return true;
            }
            return false;
        }
        for(int i = idx; i < n; i++) {
            if(state[i] || curLen + matchsticks[i] > len) {
                continue;
            }
            state[i] = true;
            if(dfs(idx + 1, state, curNum, curLen + matchsticks[i], len, matchsticks, cnt + 1)) {
                return true;
            }
            state[i] = false;
            if(!curLen || curLen + matchsticks[i] == len) {
                return false;
            }
            int j = i;
            while(j < n && matchsticks[j] == matchsticks[i]) {
                j++;
            }
            i = j - 1;
        }
        return false;
    }
};