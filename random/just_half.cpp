/*** 
 * Author: zephyr
 * Date: 2020-11-25 09:21:48
 * LastEditors: zephyr
 * LastEditTime: 2020-11-25 21:21:57
 * FilePath: \LeetCodeSolution\random\just_half.cpp
 */
#include <iostream>
using namespace std;
int majorityElement(int* data,int nums) 
{
    int count = 1, cur = data[0];
    for(int i = 1; i < nums; i++) 
    {
        if(cur != data[i]) 
        {
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
int discriminator(int* data,int nums)
{
    int count = 1, cur = data[0];
    for(int i = 1; i<nums; i++)
    {
        if(cur == data[i])
        {
            count += 1;
        }
        else
        {
            count -= 1;
        }
        
    }
    if(count == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}
int main()
{
    int data[16] = {1,2,3,2,5,2,7,2,8,2,2,9,2,0,2,4};
    int num = 16;
    if(discriminator(data, 16) == 1)
        cout << data[0] << endl;
    else
        cout << majorityElement(data+1, num-1) << endl;
    
    
    return 0;
}

