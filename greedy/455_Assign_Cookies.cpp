/*
 * @Author: zephyr
 * @Date: 2021-02-01 21:48:48
 * @LastEditTime: 2021-02-07 22:09:37
 * @LastEditors: zephyr
 * @FilePath: \greedy\455_Assign_Cookies.cpp
 * @Description: 455 assign cookies
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int child_index = 0;
    int cookie_index = 0;
    while(child_index < g.size() && cookie_index < s.size())
    {
        if(g[child_index] <= s[cookie_index])
            child_index += 1;
        cookie_index += 1;
    }
    return child_index;
}