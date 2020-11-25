/*
 * @Author: zephyr
 * @Date: 2020-11-24 16:31:05
 * @LastEditors: zephyr
 * @LastEditTime: 2020-11-25 16:48:25
 * @FilePath: \LeetCodeSolution\random\Step_up_recursion.cpp
 */

#include <iostream>
using namespace std;
int func(int n)
{
    if(n<=0)
        return 0;
    else if(n==1)
        return 1;
    else if(n==2)
        return 2;
    else if(n==3)
        return 4;
    else 
        return func(n-1)+func(n-2)+func(n-3);
}
int main()
{
    int num = 0;
    cin >> num;
    cout << func(num) << endl;
    return 0;
} // namespace std
