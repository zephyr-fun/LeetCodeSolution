/*** 
 * Author: zephyr
 * Date: 2020-12-24 09:31:25
 * LastEditors: zephyr
 * LastEditTime: 2020-12-24 09:33:19
 * FilePath: \undefinedd:\GithubWorkSpace\LeetCodeSolution\random\cut_up_stick.cpp
 */
#include <iostream>
using namespace std;
// cut up stick
int sum = 0;
void dfs(int people, int count, int current)
{
    if(current >= count)
        return ;
    if(current >= people)
    {
        sum++;
        dfs(people, count, current + people);
    }
    else
    {
        sum++;
        dfs(people, count, current*2);
    }
        
}
int main() {
    int people = 3;
    int count = 8;
    int current = 1;
    cin >> people >> count;
    dfs(people, count, current);
    cout << sum;
    return 0;
}