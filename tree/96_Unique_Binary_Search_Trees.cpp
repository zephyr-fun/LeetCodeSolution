/*** 
 * Author: zephyr
 * Date: 2020-12-25 10:15:41
 * LastEditors: zephyr
 * LastEditTime: 2020-12-25 10:20:59
 * FilePath: \MovieRatingPredictiond:\GithubWorkSpace\LeetCodeSolution\tree\96_Unique_Binary_Search_Trees.cpp
 */
#include <iostream>
#include <vector>
using namespace std;
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