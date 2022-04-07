/*** 
 * Author: zephyr
 * Date: 2021-02-08 21:15:52
 * LastEditTime: 2021-02-08 21:17:50
 * LastEditors: zephyr
 * FilePath: \greedy\435_Non-overlapping_Intervals.cpp
 * Description: 
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int eraseOverlapIntervals(vector<vector<int>>& intervals)
{
    if(intervals.empty())
        return 0;
    int num = intervals.size();
    sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b)
    {
        return a[1] < b[1];
    });
    int total = 0, prev = intervals[0][1];
    for (int i = 1; i < num; ++i)
    {
        if (intervals[i][0] < prev) 
        {
            ++total;
        } 
        else 
        {
            prev = intervals[i][1];
        }
    }
    return total;
}

// 2022.04.07
class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() == 0){
            return 0;
        }
        sort(intervals.begin(), intervals.end(), cmp);
        int count = 1;
        int end = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++){
            if(end <= intervals[i][0]){
                end = intervals[i][1]; // right bounder min, cause already sorted
                count++;
            }
        }
        return intervals.size() - count;
    }
};