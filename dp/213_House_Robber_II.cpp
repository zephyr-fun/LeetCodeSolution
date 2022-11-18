/*** 
 * Author: zephyr
 * Date: 2020-12-21 16:41:44
 * LastEditors: zephyr
 * LastEditTime: 2020-12-21 16:54:31
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
// version 2
int dynamic(vector<int>& nums, int start, int end)
{
    int first = nums[start];
    int second = max(nums[start], nums[start+1]);
    for(int i = start + 2; i < end; i++)
    {
        int temp = second;
        second = max(first + nums[i], second);
        first = temp;
    }
    return second;
}

// 2022.04.12
class Solution {
public:
    int rob(vector<int>& nums){
        if(nums.size() == 0){
            return 0;
        }
        if(nums.size() == 1){
            return nums[0];
        }
        int situation1 = robRange(nums, 0, nums.size() - 2);
        int situation2 = robRange(nums, 1, nums.size() - 1);
        return max(situation1, situation2);
    }
    int robRange(vector<int>& nums, int start, int end){
        if(start == end){
            return nums[start];
        }
        vector<int> dp(nums.size(), 0);
        dp[start] = nums[start];
        dp[start + 1] = max(nums[start], nums[start + 1]);
        for(int i = start + 2; i <= end; i++){
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[end];
    }
};

// 2022.11.18
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        if(nums.size() == 1) {
            return nums[0];
        }
        int res1 = robRange(nums, 0, nums.size() - 2);
        int res2 = robRange(nums, 1, nums.size() - 1);
        return max(res1, res2);
    }
    int robRange(vector<int>& nums, int start, int end) {
        if(start == end) {
            return nums[start];
        }
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[start] = nums[start];
        dp[start + 1] = max(nums[start], nums[start + 1]);
        for(int i = start + 2; i <= end; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[end];
    }
};