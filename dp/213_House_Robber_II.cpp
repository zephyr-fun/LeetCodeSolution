/*** 
 * Author: zephyr
 * Date: 2020-12-21 16:41:44
 * LastEditors: zephyr
 * LastEditTime: 2020-12-21 16:53:38
 * FilePath: \undefinedd:\GithubWorkSpace\LeetCodeSolution\dp\213_House_Robber_II.cpp
 */
#include <iostream>
#include <vector>
using namespace std;
// version 1
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
    if(size == 2)
    {
        return max(nums[0], nums[1]);
    }
    int v1 = dynamic(nums, 0, size -1);
    int v2 = dynamic(nums, 1, size);
    return max(v1, v2);
}
int dynamic(vector<int>& nums, int start, int end)
{
    vector<int> dp = vector<int>(nums.size(), 0);
    dp[start] = nums[start];
    dp[start+1] = max(nums[start], nums[start+1]);
    for(int i = start + 2; i < end; i++)
    {
        dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
    }
    return dp[end-1];
}
