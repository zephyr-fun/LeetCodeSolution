// 2022.04.11
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX - 1);
        dp[0] = 0;
        for(int i = 0; i <= n; i++){
            for(int j = 1; j * j <= i; j++){
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};

// another order
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX - 1);
        dp[0] = 0;
        for(int i = 0; i * i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(j - i * i >= 0){
                    dp[j] = min(dp[j], dp[j - i * i] + 1);
                }
            }
        }
        return dp[n];
    }
};

// 2022.05.03
// bag first
// item second
class Solution {
public:
    int numSquares(int n) {
        // dp[i] refers to the minimum of breaking i in to psn
        vector<int> dp(n + 1, 0x3f3f3f3f);
        dp[0] = 0;
        for(int i = 0; i <= n; i++) {
            for(int j = 1; j * j <= i; j++) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};

// item first
// bag second
class Solution {
public:
    int numSquares(int n) {
        // dp[i] refers to the minimum of breaking i in to psn
        vector<int> dp(n + 1, 0x3f3f3f3f);
        dp[0] = 0;
        for(int j = 1; j * j <= n; j++) {
            for(int i = 0; i <= n; i++) {
                if(i >= j * j){
                    dp[i] = min(dp[i], dp[i - j * j] + 1);
                }
            }
        }
        return dp[n];
    }
};

// 2022.05.06
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, 0x3f3f3f3f);
        dp[0] = 0;
        for(int i = 1; i * i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(j >= i * i) {
                    dp[j] = min(dp[j], dp[j - i * i] + 1);
                }
            }
        }
        return dp[n];
    }
};

// 2022.10.08
class Solution {
public:
    int numSquares(int n) {
        vector<int> item;
        int idx = 1;
        while(idx * idx <= n) {
            item.emplace_back(idx * idx);
            idx++;
        }
        vector<int> dp(n + 1, 0x3f3f3f3f);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 0; i < item.size(); i++) {
            for(int j = item[i]; j <= n; j++) {
                dp[j] = min(dp[j], dp[j - item[i]] + 1);
            }
        }
        return dp[n];
    }
};

// bfs
class Solution {
public:
    int numSquares(int n) {
        queue<pair<int, int>> que;
        que.push(make_pair(0, 0));
        unordered_set<int> set;
        while(!que.empty()) {
            auto [cur, step] = que.front();
            que.pop();
            if(cur == n) {
                return step;
            }
            for(int i = 1; i * i <= n - cur; i++) {
                int next = cur + i * i;
                if(set.count(next)) {
                    continue;
                }
                que.push(make_pair(next, step + 1));
                set.insert(next);
            }
        }
        return -1;
    }
};

// Lagrange's four-square theorem
class Solution {
public:
    // 判断是否为完全平方数
    bool isPerfectSquare(int x) {
        int y = sqrt(x);
        return y * y == x;
    }

    // 判断是否能表示为 4^k*(8m+7)
    bool checkAnswer4(int x) {
        while (x % 4 == 0) {
            x /= 4;
        }
        return x % 8 == 7;
    }

    int numSquares(int n) {
        if (isPerfectSquare(n)) {
            return 1;
        }
        if (checkAnswer4(n)) {
            return 4;
        }
        for (int i = 1; i * i <= n; i++) {
            int j = n - i * i;
            if (isPerfectSquare(j)) {
                return 2;
            }
        }
        return 3;
    }
};