/*** 
 * Author: zephyr
 * Date: 2020-12-06 15:50:00
 * LastEditors: zephyr
 * LastEditTime: 2020-12-06 15:56:08
 * FilePath: \LeetCodeSolution\weekly\weekly-contest-218\5618_Max_Number_of_K-Sum_Pairs.cpp
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int maxOperations(vector<int>& nums, int k)
{
    int ans = 0;
    sort(nums.begin(),nums.end());
    int i = 0;
    int j = nums.size()-1;
    while(i<j)
    {
        if(nums[i]+nums[j]>k)
        {
            j--;
        }
        else if(nums[i]+nums[j]<k)
        {
            i++;
        }
        else
        {
            ans += 1;
            i++;
            j--;
        }
    }
    return ans;
}