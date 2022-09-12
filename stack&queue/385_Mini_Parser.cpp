// 2022.09.12
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
// https://leetcode.cn/problems/mini-parser/solution/by-nehzil-r3av/
class Solution {
public:
    NestedInteger deserialize(string s) {
        /* 直接是一个数字字符串直接加入实例中即可 */
        if(s[0] != '[') return NestedInteger(stoi(s));
        /* 定义一个存储NestedInteger对象的栈 */
        stack<NestedInteger> st;
        int num = 0;
        bool flag = false;// 定义正负号的标志位
        for(int i = 0; i < s.size(); i++) {
            char c = s[i];
            /* 若检测到 - 号标志位置 1 */
            if (c == '-') flag = true;
            /* 如果是数字直接计算 */
            else if(isdigit(c)) num = num * 10 + c - '0';
            /* 检测到左括号向栈里添加对象 */
            else if(c == '[') st.emplace(NestedInteger());
            else if(c == ',' || c == ']') {
                if(isdigit(s[i - 1])) {
                    if (flag) num *= -1;
                    /* 向栈顶的NestedInteger添加值num */
                    st.top().add(NestedInteger(num));
                }
                /* 重新初始化 */
                num = 0;
                flag = false;
                /* 将栈里的NestedInteger(num)合并为一个对象列表 */
                if(c == ']' && st.size() > 1) {
                    NestedInteger numNestedInteger = st.top();
                    st.pop();
                    st.top().add(numNestedInteger);
                }
            }
        }
        return st.top();
    }
};