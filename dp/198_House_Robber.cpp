/*** 
 * Author: zephyr
 * Date: 2020-12-21 09:00:27
 * LastEditors: zephyr
 * LastEditTime: 2020-12-21 21:18:52
 * FilePath: \dp\198_House_Robber.cpp
 */
// dp
#include <iostream>
#include <vector>
using namespace std;
int rob(vector<int>& nums) {
    if(nums.empty())
    {
        return 0;
    }
    int size = nums.size();
    if(size == 1)
    {
        return nums[0];
    }
    vector<int> dp = vector<int>(size, 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for(int i = 2; i < size; i++)
    {
        dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
    }
    return dp[size-1];
}

// less space
int rob(vector<int>& nums)
{
    if(nums.empty())
    {
        return 0;
    }
    int size = nums.size();
    if(size == 1)
    {
        return nums[0];
    }
    int first = nums[0], second = max(nums[0], nums[1]);
    for(int i = 2; i < size; i++)
    {
        int temp = second;
        second = max(first + nums[i], second);
        first = temp;
    }
    return second;
}