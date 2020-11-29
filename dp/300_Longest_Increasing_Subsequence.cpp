/*** 
 * Author: zephyr
 * Date: 2020-11-29 16:02:29
 * LastEditors: zephyr
 * LastEditTime: 2020-11-29 16:56:17
 * FilePath: \LeetCodeSolution\dp\300_Longest_Increasing_Subsequence.cpp
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int lengthOfLIS(vector<int>& nums)
{
    int n = nums.size();
    int max = 0;
    if(n = 0)
        return 0;
    vector<int> dp(n, 0);
    for(int i = 0; i<n; i++)
    {
        dp[i] = 1;
        for(int j = 0; j<i; j++)
        {
            if(nums[j]<nums[i])
                dp[i] = dp[i]>(dp[j]+1)?dp[i]:(dp[j]+1);
        }
    }
    for(int i = 0; i<nums.size(); i++)
    {
        max = max>dp[i]?max:dp[i];
    }
    return max;
}

int lengthOfLIS2(vector<int>& nums)
{
    int len = 1;
    int n = nums.size();
    if(n == 0)
        return 0;
    vector<int> d(n+1, 0);
    d[len] = nums[0];
    for(int i = 1; i<n; i++)
    {
        if(nums[i]>d[len])
            d[++len] = nums[i];
        else
        {
            int l = 1;
            int r = len;
            int pos = 0;
            while(l <= r)
            {
                int mid = (l+r) >> 1;
                if(nums[i]>d[mid])
                {
                    pos = mid;
                    l = mid+1;
                }
                else
                {
                    r = mid-1;
                }
                
            }
            d[pos+1] = nums[i];

        }
        
    }
    return len;
}