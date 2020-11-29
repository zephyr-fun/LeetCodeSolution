/*** 
 * Author: zephyr
 * Date: 2020-11-29 12:02:25
 * LastEditors: zephyr
 * LastEditTime: 2020-11-29 17:25:35
 * FilePath: \LeetCodeSolution\weekly\biweekly-contest-40\5559_Minimum_Number_of_Removals_to_Make_Mountain_Array.cpp
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int minimumMountainRemovals(vector<int>& nums)
{
    vector<int> left(nums.size(), 1), right(nums.size(), 1);
    int res = nums.size();
    for(int i = 0; i<nums.size(); i++)
    {
        for(int j = 0; j<i; j++)
        {
            if(nums[i]>nums[j])
                left[i] = left[i]>(left[j]+1)?left[i]:(left[j]+1);
        }
    }
    for(int i = nums.size()-1; i>=0; i--)
    {
        for(int j = nums.size()-1; j>i; j--)
        {
            if(nums[i]>nums[j])
                right[i] = right[i]>(right[j]+1)?right[i]:(right[j]+1);
        }
    }
    for(int i = 1; i<nums.size()-1; i++)
    {
        int leftnum = left[i]-1;
        int rightnum = right[i]-1;
        int temp = 0;
        temp = nums.size()-leftnum-rightnum-1;
        res = res<temp?res:temp;
    }
    return res;
}