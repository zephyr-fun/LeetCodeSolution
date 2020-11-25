/*
 * @Author: zephyr
 * @Date: 2020-11-25 09:21:22
 * @LastEditTime: 2020-11-25 16:47:33
 * @LastEditors: zephyr
 * @Description: In User Settings Edit
 * @FilePath: \LeetCodeSolution\random\more_than_half.cpp
 */
#include <iostream>
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
int main()
{
    int data[15] = {1,2,3,2,5,2,7,2,8,2,2,9,2,0,2};
    int num = 15;
    cout << majorityElement(data, num) << endl;
    return 0;
}