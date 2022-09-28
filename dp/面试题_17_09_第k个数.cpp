// 2022.09.28
// priority_queue
// c++ default less
class Solution {
public:
    int getKthMagicNumber(int k) {
        priority_queue<long, vector<long>, greater<long>> pque;
        pque.push(1L);
        unordered_set<long> set;
        set.insert(1L);
        int candidate[3] = {3, 5, 7};
        long res = 0;
        while(k) {
            res = pque.top();
            pque.pop();
            for(int i = 0; i < 3; i++) {
                long temp = candidate[i] * res;
                if(!set.count(temp)) {
                    pque.push(temp);
                    set.insert(temp);
                }
            }
            k--;
        }
        return (int)res;
    }
};

// dp
class Solution {
public:
    int getKthMagicNumber(int k) {
        vector<int> dp(k + 1, 0);
        dp[1] = 1;
        int p3 = 1;
        int p5 = 1;
        int p7 = 1;
        for(int i = 2; i <= k; i++) {
            int num3 = dp[p3] * 3;
            int num5 = dp[p5] * 5;
            int num7 = dp[p7] * 7;
            dp[i] = min(num3, min(num5, num7));
            // 涉及重复值
            // 比如3 * 5 = 15时，实际上5 * 3 = 15，但显然不能再出现
            // if(dp[i] == num3) {
            //     p3++;
            // }
            // else if(dp[i] == num5) {
            //     p5++;
            // }
            // else {
            //     p7++;
            // }
            if(dp[i] == num3) {
                p3++;
            }
            if(dp[i] == num5) {
                p5++;
            }
            if(dp[i] == num7) {
                p7++;
            }
        }
        return dp[k];
    }
};