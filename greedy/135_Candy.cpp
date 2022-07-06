/*** 
 * Author: zephyr
 * Date: 2021-02-07 21:34:16
 * LastEditTime: 2021-02-07 22:26:33
 * LastEditors: zephyr
 * FilePath: \greedy\135_Candy.cpp
 * Description: 135 candy
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
int candy(vector<int>& ratings) {
    int size = ratings.size();
    if(size < 2)
    {
        return size;
    }
    vector<int> num(size, 1);
    for(int i = 1; i < size; i++)
    {
        if(ratings[i] > ratings[i-1])
        {
            num[i] = num[i-1] + 1;
        }
    }
    for(int i = size-1; i > 0; i--)
    {
        if(ratings[i] < ratings[i-1])
        {
            num[i-1] = max(num[i]+1, num[i-1]);
        }
    }
    return accumulate(num.begin(), num.end(), 0);
}

// 2022.04.06
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candyVec(ratings.size(), 1);
        for(int i = 1; i < ratings.size(); i++){
            if(ratings[i] > ratings[i - 1]){
                candyVec[i] = candyVec[i - 1] + 1;
            }
        }
        for(int i = ratings.size() - 2; i >= 0; i--){
            if(ratings[i] > ratings[i + 1]){
                candyVec[i] = max(candyVec[i], candyVec[i + 1] + 1); // max(candyVec[i], candyVec[i + 1] + 1)
            }
        }
        int res = 0;
        for(int i = 0; i < ratings.size(); i++){
            res += candyVec[i];
        }
        return res;
    }
};

// 2022.07.06
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int res = 0;
        vector<int> vis(n, 1);
        for(int i = 1; i < n; i++) {
            if(ratings[i] > ratings[i - 1]) {
                vis[i] = vis[i - 1] + 1;
            }
        }
        for(int i = n - 2; i >= 0; i--) {
            if(ratings[i] > ratings[i + 1]) {
                vis[i] = max(vis[i], vis[i + 1] + 1);
            }
        }
        for(int i = 0; i < n; i++) {
            res += vis[i];
        }
        return res;
    }
};