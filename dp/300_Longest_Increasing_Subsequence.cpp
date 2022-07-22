/*** 
 * Author: zephyr
 * Date: 2020-11-29 16:02:29
 * LastEditors: zephyr
 * LastEditTime: 2020-11-29 20:17:38
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
//use this for 5559_minimum_number_of_removals_to_make_mountain_array
int lengthOfLIS3(vector<int>& nums)
{
    int len = 1;
    int n = nums.size();
    if(n == 0)
        return 0;
    vector<int> d(n+1, 0);
    vector<int> lm(n, 0);
    d[len] = nums[0];
    lm[0] = 1;
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
    return len;
}

// 2022.04.13
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int res = 1;
        if(nums.size() == 0){
            return dp[0];
        }
        for(int i = 1; i < nums.size(); i++){
            for(int j = 0; j <= i; j++){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};

// 2022.05.06
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = 1;
        int size = nums.size();
        if(size == 0) {
            return 0;
        }
        // d[len] refers to the minimum x of len subsequence
        vector<int> d(size + 1, 0);
        d[len] = nums[0];
        for(int i = 1; i < size; i++) {
            if(nums[i] > d[len]) {
                len++;
                d[len] = nums[i];
            }
            else {
                int left = 1;
                int right = len;
                int pos = 0;
                while(left <= right) {
                    int mid = left + (right - left) / 2;
                    if(d[mid] < nums[i]) {
                        pos = mid;
                        left = mid + 1;
                    }
                    else {
                        right = mid - 1;
                    }
                }
                d[pos + 1] = nums[i];
            }
        }
        return len;
    }
};

// 2022.07.22
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        vector<int> dp(n, 1);
        for(int i = 0; i < n; i++) {
            for(int j = i; j >= 0; j--) {
                if(nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        for(int i = 0; i < n; i++) {
            res = max(res, dp[i]);
        }
        return res;
    }
};

// optim nlogn
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        int len = 1;
        dp[len] = nums[0];
        for(int i = 1; i < n; i++) {
            if(nums[i] > dp[len]) {
                len++;
                dp[len] = nums[i];
            }
            else {
                int left = 1;
                int right = len;
                int pos = 0;
                while(left <= right) {
                    int mid = (left + right) >> 1;
                    if(dp[mid] < nums[i]) {
                        pos = mid;
                        left = mid + 1;
                    }
                    else {
                        right = mid - 1;
                    }
                }
                dp[pos + 1] = nums[i];
            }
        }
        return len;
    }
};