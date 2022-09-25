/*** 
 * Author: zephyr
 * Date: 2020-12-25 10:15:41
 * LastEditors: zephyr
 * LastEditTime: 2021-01-02 10:06:53
 * FilePath: \tree\96_Unique_Binary_Search_Trees.cpp
 */
#include <iostream>
#include <vector>
using namespace std;

// way 1 dp(kind of recursion way)
// $G(n) = \sum^n_{i = 1}{F(i, n)}$
// $G(0) = 1 G(1) = 1$
// $F(i, n) = G(i - 1)*G(n - i)$
// $G(n) = \sum^n_{i = 1}{G(i - 1)*G(n - i)}$
int numTrees(int n) {
    vector<int> G(n+1, 0);
    G[0] = 1;
    G[1] = 1;
    for(int length = 2; length <= n; length++)
    {
        for(int root = 1; root <= length; root++)
        {
            G[length] += G[root - 1] * G[length - root];
        }
    }
    return G[n];
}

// way 2 明安图数
// $res_0 = 1$
// $res_n = res_{n - 1}*\frac{2(2n + 1)}{n + 2}$
int numTrees2(int n)
{
    long long res = 1;
    for(int length = 0; length < n; length++)
    {
        res = res * 2 * (2 * length + 1) / (length + 2);
    }
    return res;
}

// 2022.09.25
class Solution {
public:
    int numTrees(int n) {
        if(n <= 1) {
            return 1;
        }
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; i++) {
            for(int j = 1; j <= i; j++) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};