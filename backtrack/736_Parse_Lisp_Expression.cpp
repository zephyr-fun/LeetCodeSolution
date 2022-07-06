// 2022.07.06
// ll(1)
class Solution {
private:
    unordered_map<string, vector<int>> scope;

public:
    int evaluate(string expression) {
        int start = 0;
        return innerEvaluate(expression, start);
    }

    int innerEvaluate(const string &expression, int &start) {
        if (expression[start] != '(') { // 非表达式，可能为：整数或变量
            if (islower(expression[start])) {
                string var = parseVar(expression, start); // 变量
                return scope[var].back();
            } else { // 整数
                return parseInt(expression, start);
            }
        }
        int ret;
        start++; // 移除左括号
        if (expression[start] == 'l') { // "let" 表达式
            start += 4; // 移除 "let "
            vector<string> vars;
            while (true) {
                if (!islower(expression[start])) {
                    ret = innerEvaluate(expression, start); // let 表达式的最后一个 expr 表达式的值
                    break;
                }
                string var = parseVar(expression, start);
                if (expression[start] == ')') {
                    ret = scope[var].back(); // let 表达式的最后一个 expr 表达式的值
                    break;
                }
                vars.push_back(var);
                start++; // 移除空格
                int e = innerEvaluate(expression, start);
                scope[var].push_back(e);
                start++; // 移除空格
            }
            for (auto var : vars) {
                scope[var].pop_back(); // 清除当前作用域的变量
            }
        } else if (expression[start] == 'a') { // "add" 表达式
            start += 4; // 移除 "add "
            int e1 = innerEvaluate(expression, start);
            start++; // 移除空格
            int e2 = innerEvaluate(expression, start);
            ret = e1 + e2;
        } else { // "mult" 表达式
            start += 5; // 移除 "mult "
            int e1 = innerEvaluate(expression, start);
            start++; // 移除空格
            int e2 = innerEvaluate(expression, start);
            ret = e1 * e2;
        }
        start++; // 移除右括号
        return ret;
    }

    int parseInt(const string &expression, int &start) { // 解析整数
        int n = expression.size();
        int ret = 0, sign = 1;
        if (expression[start] == '-') {
            sign = -1;
            start++;
        }
        while (start < n && isdigit(expression[start])) {
            ret = ret * 10 + (expression[start] - '0');
            start++;
        }
        return sign * ret;
    }

    string parseVar(const string &expression, int &start) { // 解析变量
        int n = expression.size();
        string ret;
        while (start < n && expression[start] != ' ' && expression[start] != ')') {
            ret.push_back(expression[start]);
            start++;
        }
        return ret;
    }
};

// lr(1) State Machine
enum ExprStatus {
    VALUE = 0, // 初始状态
    NONE,      // 表达式类型未知
    LET,       // let 表达式
    LET1,      // let 表达式已经解析了 vi 变量
    LET2,      // let 表达式已经解析了最后一个表达式 expr
    ADD,       // add 表达式
    ADD1,      // add 表达式已经解析了 e1 表达式
    ADD2,      // add 表达式已经解析了 e2 表达式
    MULT,      // mult 表达式
    MULT1,     // mult 表达式已经解析了 e1 表达式
    MULT2,     // mult 表达式已经解析了 e2 表达式
    DONE       // 解析完成
};

struct Expr {
    ExprStatus status;
    string var; // let 的变量 vi
    int value; // VALUE 状态的数值，或者 LET2 状态最后一个表达式的数值
    int e1, e2; // add 或 mult 表达式的两个表达式 e1 和 e2 的数值

    Expr(ExprStatus s) {
        status = s;
    }
};

class Solution {
private:
    unordered_map<string, vector<int>> scope;

public:
    int evaluate(string expression) {
        vector<vector<string>> vars;
        int start = 0, n = expression.size();
        stack<Expr> s;
        Expr cur(VALUE);
        while (start < n) {
            if (expression[start] == ' ') {
                start++; // 去掉空格
                continue;
            }
            if (expression[start] == '(') {
                start++; // 去掉左括号
                s.push(cur);
                cur = Expr(NONE);
                continue;
            }
            string token;
            if (expression[start] == ')') { // 本质上是把表达式转成一个 token
                start++; // 去掉右括号
                if (cur.status == LET2) {
                    token = to_string(cur.value);
                    for (auto var : vars.back()) { // 清除作用域
                        scope[var].pop_back();
                    }
                    vars.pop_back();
                } else if (cur.status == ADD2) {
                    token = to_string(cur.e1 + cur.e2);
                } else {
                    token = to_string(cur.e1 * cur.e2);
                }
                cur = s.top(); // 获取上层状态
                s.pop();
            } else {
                while (start < n && expression[start] != ' ' && expression[start] != ')') {
                    token.push_back(expression[start]);
                    start++;
                }
            }
            switch (cur.status) {
                case VALUE:
                    cur.value = stoi(token);
                    cur.status = DONE;
                    break;
                case NONE:
                    if (token == "let") {
                        cur.status = LET;
                        vars.emplace_back(); // 记录该层作用域的所有变量, 方便后续的清除
                    } else if (token == "add") {
                        cur.status = ADD;
                    } else if (token == "mult") {
                        cur.status = MULT;
                    }
                    break;
                case LET:
                    if (expression[start] == ')') { // let 表达式的最后一个 expr 表达式
                        cur.value = calculateToken(token);
                        cur.status = LET2;
                    } else {
                        cur.var = token;
                        vars.back().push_back(token); // 记录该层作用域的所有变量, 方便后续的清除
                        cur.status = LET1;
                    }
                    break;
                case LET1:
                    scope[cur.var].push_back(calculateToken(token));
                    cur.status = LET;
                    break;
                case ADD:
                    cur.e1 = calculateToken(token);
                    cur.status = ADD1;
                    break;
                case ADD1:
                    cur.e2 = calculateToken(token);
                    cur.status = ADD2;
                    break;
                case MULT:
                    cur.e1 = calculateToken(token);
                    cur.status = MULT1;
                    break;
                case MULT1:
                    cur.e2 = calculateToken(token);
                    cur.status = MULT2;
                    break;
            }
        }
        return cur.value;
    }

    int calculateToken(const string &token) {
        if (islower(token[0])) {
            return scope[token].back();
        } else {
            return stoi(token);
        }
    }
};

// 2022.07.06
typedef unordered_map<string, int> MPSI;
class Solution {
public:
    typedef unordered_map<string, int> MPSI;
    string s;
    int getRight(int left, int end) {
        int right = left;
        int score = 0;
        while(right <= end) {
            if(s[right] == '(') {
                score++;
                right++;
            }
            else if(s[right] == ')') {
                score--;
                right++;
            }
            else if(s[right] == ' ') {
                if(score == 0) {
                    break;
                }
                right++;
            }
            else {
                right++;
            }
        }
        return right;
    }

    int dfs(int l, int r, MPSI map) {
        if(s[l] == '(') {
            int idx = l;
            while(s[idx] != ' ') {
                idx++;
            }
            string opt = s.substr(l + 1, idx - l - 1);
            r--;
            // cout << opt << endl;
            if(opt == "let") {
                for(int i = idx + 1; i <= r; ) {
                    int j = getRight(i, r);
                    // cout << l << r << endl;
                    // cout << i << j << endl;
                    string key = s.substr(i, j - i);
                    if(j >= r) {
                        return dfs(i, j - 1, map);
                    }
                    j++;
                    i = j;
                    j = getRight(i, r);
                    int value = dfs(i, j - 1, map);
                    // cout << key << value << endl;
                    map[key] = value;
                    i = j + 1;
                }
            }
            else if(opt == "add") {
                int j = getRight(idx + 1, r);
                int a = dfs(idx + 1, j - 1, map);
                int b = dfs(j + 1, r, map);
                return a + b;
            }
            else {
                // opt == "mult"
                int j = getRight(idx + 1, r);
                int a = dfs(idx + 1, j - 1, map);
                int b = dfs(j + 1, r, map);
                return a * b;
            }
        }
        else {
            string cur = s.substr(l, r - l + 1);
            // cout << l << r << endl;
            // cout << cur << endl;
            if(map.find(cur) != map.end()) {
                return map[cur];
            }
            return stoi(cur);
        }
        return -1;
    }

    int evaluate(string expression) {
        s = expression;
        return dfs(0, s.size() - 1, MPSI());
    }
};