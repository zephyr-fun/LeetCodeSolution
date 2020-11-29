/*** 
 * Author: zephyr
 * Date: 2020-11-29 12:02:23
 * LastEditors: zephyr
 * LastEditTime: 2020-11-29 15:03:20
 * FilePath: \LeetCodeSolution\weekly\biweekly-contest-40\5558_Merge_In_Between_Linked_Lists.cpp
 */
#include <iostream>
#include <vector>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2)
{
    ListNode* start1 = list1;
    ListNode* end1 = list1;
    ListNode* end2 = list2;
    for(int i = 1; i<a; i++)
    {
        start1 = start1->next;
    }
    for(int i = 0; i<=b; i++)
    {
        end1 = end1->next;
    }
    while(end2->next != NULL)
    {
        end2 = end2->next;
    }
    start1->next = list2;
    end2->next = end1;
    return list1;
}