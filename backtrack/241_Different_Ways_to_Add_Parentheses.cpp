// 2022.07.01
// dfs
class Solution {
public:
    string s;
    vector<int> dfs(int left, int right) {
        vector<int> res;
        for(int i = left; i <= right; i++) {
            if(s[i] >= '0' && s[i] <= '9') {
                continue;
            }
            vector<int> leftRes = dfs(left, i - 1);
            vector<int> rightRes = dfs(i + 1, right);
            for(auto a : leftRes) {
                for(auto b : rightRes) {
                    int cur = 0;
                    if(s[i] == '+') {
                        cur = a + b;
                    }
                    else if(s[i] == '-') {
                        cur = a - b;
                    }
                    else {
                        cur = a * b;
                    }
                    res.emplace_back(cur);
                }
            }
        }
        if(res.empty()) { // 没有运算符的时候应该返回这个数
            int cur = 0;
            for(int i = left; i <= right; i++) {
                cur = cur * 10 + s[i] - '0';
            }
            res.emplace_back(cur);
        }
        return res;
    }
    vector<int> diffWaysToCompute(string expression) {
        s = expression;
        return dfs(0, s.size() - 1);
    }
};