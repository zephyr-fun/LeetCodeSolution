/*** 
 * Author: zephyr
 * Date: 2020-11-29 14:40:36
 * LastEditors: zephyr
 * LastEditTime: 2020-12-06 16:17:06
 * FilePath: \LeetCodeSolution\weekly\weekly-contest-218\5620_Concatenation_of_Consecutive_Binary_Numbers.cpp
 */
#include <iostream>
#include <vector>
using namespace std;
// way1 O(nlogn)
int concatenatedBinary(int n)
{
    int res = 0;
    int x = 1;
    int mod = 1000000007;
    for(int i = n; i>0; i--)
        for(int j = i; j>0; j/=2, x=x*2 % mod)
        {
            if(j % 2)
                res = (res % mod +x % mod) % mod;
        }
    return res;
}

// way2 O(n)
static constexpr int mod = 1000000007;
int concatenatedBinary2(int n)
{
    int res = 0;
    int shift = 0;
    for(int i = 1; i<=n; i++)
    {
        if(!(i&(i-1)))
            shift++;
        res = ((static_cast<long long>(res) << shift ) + i) % mod;
    }
    return res;
}