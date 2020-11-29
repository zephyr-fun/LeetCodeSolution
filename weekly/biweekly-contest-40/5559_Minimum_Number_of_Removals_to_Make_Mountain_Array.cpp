/*** 
 * Author: zephyr
 * Date: 2020-11-29 12:02:25
 * LastEditors: zephyr
 * LastEditTime: 2020-11-29 20:13:23
 * FilePath: \LeetCodeSolution\weekly\biweekly-contest-40\5559_Minimum_Number_of_Removals_to_Make_Mountain_Array.cpp
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
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
vector<int> lengthOfLIS(vector<int>& nums, int start, int end)
{
    int len = 1;
    int n = nums.size();
    vector<int> d(n+1, 0);
    vector<int> lm(n, 0);
    d[len] = nums[start];
    lm[0] = 1;
    if(start>end)
    {
        reverse(nums.begin(), nums.end());
    }
    for(int i = 1; i<n; i++)
    {
        if(nums[i]>d[len])
        {   
            d[++len] = nums[i];
            lm[i] = len;
        }
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
            lm[i] = pos+1;

        }
        
    }
    return lm;
}
int minimumMountainRemovals2(vector<int>& nums)
{
    int res = nums.size();
    if(nums.size() == 0)
        return 0;
    vector<int> left = lengthOfLIS(nums, 0, nums.size()-1);
    vector<int> right = lengthOfLIS(nums, nums.size()-1, 0);
    for(int i = 1; i<nums.size()-1; i++)
    {
        int leftnum = left[i]-1;
        int rightnum = right[nums.size()-i-1]-1;
        int temp = 0;
        temp = nums.size()-leftnum-rightnum-1;
        res = res<temp?res:temp;
    }
    return res;
}
int main()
{
    // int a[8]={4,3,2,1,1,2,3,1};
    // vector<int> test(a,a+8);
    vector<int> test({1,3,1});
    vector<int> left = lengthOfLIS(test, 0, test.size()-1);
    vector<int> right = lengthOfLIS(test, test.size()-1, 0);
    for(int num : left)
    {
        cout << num << endl;
    }
    cout << endl;
    for(int num : right)
    {
        cout << num << endl;
    }
    cout << endl;
}