/*** 
 * Author: zephyr
 * Date: 2020-11-25 09:04:01
 * LastEditors: zephyr
 * LastEditTime: 2020-11-25 17:10:34
 * FilePath: \LeetCodeSolution\random\Step_up_dp.cpp
 */

#include <iostream>
using namespace std;
int countDPStages(int n)
{
    
    if(n == 1)
        return 1;
    
    if(n == 2)
        return 2;
    
    if(n == 3)
        return 4;
    
    int a=1;
    int b=2;
    int c=4;
    int temp = 0;
    
    for (int i = 4; i<=n; ++i)
    {
        temp = a+b+c;
        a = b;
        b = c;
        c = temp;
    }
    
    return temp;

}
int main()
{
    int num = 0;
    cin >> num;
    cout << countDPStages(num) << endl;
    return 0;
}