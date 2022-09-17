// 2022.09.17
// https://leetcode.cn/problems/basic-calculator/solution/shuang-zhan-jie-jue-tong-yong-biao-da-sh-olym/
class Solution {
public:
    void replace(string& s, string source, string target) {
        int n = source.size();
        int pos = s.find(source);
        while(pos != -1) {
            s.replace(pos, n, target);
            pos = s.find(source);
        }
    }
    int calculate(string s) {
        stack<int> nums;
        stack<char> opt;
        nums.push(0);
        replace(s, " ", "");
        int n = s.size();
        for(int i = 0; i < n; i++) {
            char c = s[i];
            if(c == '(') {
                opt.push(c);
            }
            else if(c == ')'){
                while(!opt.empty()) {
                    char op = opt.top();
                    if(op != '(') {
                        calc(nums, opt);
                    }
                    else {
                        opt.pop();
                        break;
                    }
                }
            }
            else {
                if(c >= '0' && c <= '9') {
                    int cur_num = 0;
                    int j = i;
                    while(j < n && s[j] >= '0' && s[j] <= '9') {
                        cur_num = cur_num * 10 + (s[j] - '0');
                        j++;
                    }
                    nums.push(cur_num);
                    i = j - 1;
                }
                else {
                    if(i > 0 && (s[i - 1] == '+' || s[i - 1] == '-' || s[i - 1] == '(')) {
                        nums.push(0);
                    }
                    while(!opt.empty() && opt.top() != '(') {
                        calc(nums, opt);
                    }
                    opt.push(c);
                }
            }
        }
        while(!opt.empty()) {
            calc(nums, opt);
        }
        return nums.top();
    }
    void calc(stack<int>& nums, stack<char>& opt) {
        if(nums.size() < 2 || opt.empty()) {
            return ;
        }
        int b = nums.top();
        nums.pop();
        int a = nums.top();
        nums.pop();
        char op = opt.top();
        opt.pop();
        nums.push(op == '+' ? a + b : a - b);
    }
};