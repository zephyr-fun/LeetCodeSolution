// 2022.11.22
class Solution {
public:
    int res = 0;
    void dfs(int n) {
        if(n == 2) {
            res += 1;
            return ;
        }
        res += n / 2;
        int temp = n % 2 == 0 ? n / 2 : n / 2 + 1;
        dfs(temp);
    }
    int numberOfMatches(int n) {
        if(n == 1) {
            return 0;
        }
        dfs(n);
        return res;
    }
};

// trick
class Solution {
public:
    int numberOfMatches(int n) {
        return n - 1;
    }
};