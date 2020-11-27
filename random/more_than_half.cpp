/*** 
 * Author: zephyr
 * Date: 2020-11-25 09:21:22
 * LastEditors: zephyr
 * LastEditTime: 2020-11-27 14:51:46
 * FilePath: \LeetCodeSolution\random\more_than_half.cpp
 */

#include <iostream>
#include <vector>
using namespace std;
int majorityElement(int* data,int nums) 
{
    int count = 1, cur = data[0];
    for(int i = 1; i < nums; i++) {
        if(cur != data[i]) {
            --count;
            if(count < 0) {
                cur = data[i];
                count = 1;
            }
        }
        else ++count;
    }
    return cur;
}
int majorityElement2(vector<int>& nums)
{
    int votes = 0;
    int cur = 0;
    for(int num : nums)
    {
        if(votes == 0)
            cur = num;
        votes += cur==num ? 1:-1;
    }
    return cur;
}
int main()
{
    int data[15] = {1,2,3,2,5,2,7,2,8,2,2,9,2,0,2};
    int num = 15;
    vector<int> datav(data,data+15);
    // cout << majorityElement(data, num) << endl;
    cout << majorityElement2(datav) << endl;
    return 0;
}