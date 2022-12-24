// 2022.09.29
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int pn = primes.size();
        vector<int> po(pn, 1);
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        for(int i = 2; i <= n; i++) {
            int temp = INT_MAX;
            vector<int> plus;
            for(int j = 0; j < pn; j++) {
                if((long long)primes[j] * (long long)dp[po[j]] < temp) {
                    temp = primes[j] * dp[po[j]];
                    plus.clear();
                    plus.emplace_back(j);
                }
                else if((long long)primes[j] * (long long)dp[po[j]] == temp) {
                    plus.emplace_back(j);
                }
            }
            dp[i] = temp;
            for(auto& p : plus) {
                po[p]++;
            }
        }
        return dp[n];
    }
};

// 2022.11.30
// priority_queue
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<int, vector<int>, greater<int>> que;
        que.push(1);
        while(n-- > 0) {
            int x = que.top();
            que.pop();
            if(n == 0) {
                return x;
            }
            for(auto p : primes) {
                if(p <= INT_MAX / x) {
                    que.push(x * p);
                }
                if(x % p == 0) {
                    break;
                }
            }
        }
        return -1;
    }
};

// 2022.12.24
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<int, vector<int>, greater<int>> pque;
        pque.push(1);
        while(n-- > 0) {
            int x = pque.top();
            pque.pop();
            if(n == 0) {
                return x;
            }
            for(auto& prime : primes) {
                if(prime <= INT_MAX / x) {
                    pque.push(x * prime);
                }
                if(x % prime == 0) {
                    break;
                }
            }
        }
        return -1;
    }
};