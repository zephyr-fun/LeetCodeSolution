/*** 
 * Author: zephyr
 * Date: 2020-11-29 14:40:36
 * LastEditors: zephyr
 * LastEditTime: 2020-12-05 11:03:12
 * FilePath: \LeetCodeSolution\weekly\weekly-contest-217\5613_Richest_Customer_Wealth.cpp
 */
#include <iostream>
#include <vector>
using namespace std;
// 3 points
int maximumWealth(vector<vector<int>>& accounts) {
    int max = 0;
    for(int i = 0; i<accounts.size(); i++)
    {
        int temp = 0;
        for(int j = 0; j<accounts[i].size(); j++)
        {
            temp += accounts[i][j];
        }
        if(temp > max)
            max = temp;
    }
    return max;   
}