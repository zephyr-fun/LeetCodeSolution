/*** 
 * Author: zephyr
 * Date: 2020-12-06 15:50:00
 * LastEditors: zephyr
 * LastEditTime: 2020-12-06 15:54:29
 * FilePath: \LeetCodeSolution\weekly\weekly-contest-218\5617_Goal_Parser_Interpretation.cpp
 */
#include <iostream>
#include <string>
using namespace std;

string interpret(string command)
{
    string res ;
    for(int i = 0; i<command.size(); i++)
    {
        if(command[i] == '(' && command[i+1] == ')' && i+1<command.size())
            res.push_back('o'); 
        else if(command[i] == '(' || command[i] == ')')
            continue;
        else
            res.push_back(command[i]);
    }
    return res;
}