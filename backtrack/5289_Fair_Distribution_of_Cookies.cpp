// 2022.06.12
// dfs, backtrack
class Solution {
public:
    int res = 0x3f3f3f3f;
    int child[10];
    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();
        dfs(0, n, cookies, k);
        return res;
    }
    void dfs(int x, int n, vector<int>& cookies, int k) {
        if(x == n) {
            int maxVal = 0;
            for(int i = 0; i < k; i++) {
                maxVal = max(maxVal, child[i]);
            }
            res = min(res, maxVal);
        }
        else {
            for(int i = 0; i < k; i++) {
                child[i] += cookies[x];
                dfs(x + 1, n, cookies, k);
                child[i] -= cookies[x];
            }
        }
    }
};

// dp
class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        
    }
};