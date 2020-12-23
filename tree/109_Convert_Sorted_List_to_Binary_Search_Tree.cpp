/*** 
 * Author: zephyr
 * Date: 2020-12-23 10:57:27
 * LastEditors: zephyr
 * LastEditTime: 2020-12-23 11:07:00
 * FilePath: \undefinedd:\GithubWorkSpace\LeetCodeSolution\tree\109_Convert_Sorted_List_to_Binary_Search_Tree.cpp
 */
#include <iostream>
#include <vector>
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
ListNode* getMid(ListNode* left, ListNode* right)
{
    ListNode* fast = left;
    ListNode* slow = left;
    while(fast != right && fast->next != right)
    {
        fast = fast->next;
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}
TreeNode* dfs(ListNode* left, ListNode* right)
{
    if(left == right)
        return nullptr;
    ListNode* mid = getMid(left, right);
    TreeNode* root = new TreeNode(mid->val);
    root->left = dfs(left, mid);
    root->right = dfs(mid->next, right);
    return root;
}
TreeNode* sortedListToBST(ListNode* head)
{
    if(!head)
        return nullptr;
    TreeNode* root = dfs(head, nullptr);
    return root;
}