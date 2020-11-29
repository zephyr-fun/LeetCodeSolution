/*** 
 * Author: zephyr
 * Date: 2020-11-29 12:00:56
 * LastEditors: zephyr
 * LastEditTime: 2020-11-29 15:27:38
 * FilePath: \LeetCodeSolution\weekly\biweekly-contest-40\5557_Maximum_Repeating_Substring.cpp
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int maxRepeating(string sequence, string word) {
    int ans=-1;
    for(int i=0;i<sequence.size();i++)
    {
        for(int j=0;i+j<sequence.size();j++)
        {   if(sequence[i+j]!=word[j%word.size()])
                break;
            ans=ans>j?ans:j;
        }
    }
    return (ans+1)/word.size();
}
int maxRepeating2(string sequence, string word) {
        int n=sequence.size(),m=word.size(),i,j,ans=-1;
        for(i=0;i<n;i++)
        {
            for(j=0;i+j<n;j++)
                if(sequence[i+j]!=word[j%m])
                    break;
            ans=ans>j?ans:j;
        }
        return ans/m;
    }