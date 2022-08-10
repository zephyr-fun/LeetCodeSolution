// 2022.08.10
class Solution {
public:
    string solveEquation(string equation) {
        int num = 0;
        int x = 0;
        int n = equation.size();
        int op = 1;
        for(int i = 0; i < n; i++) {
            if(equation[i] == '+') {
                op = 1;
            }
            else if(equation[i] == '-') {
                op = -1;
            }
            else if(equation[i] == '=') {
                num = -num;
                x = -x;
                op = 1;
            }
            else {
                int j = i;
                while(j < n && equation[j] != '+' && equation[j] != '-' && equation[j] != '=') {
                    j++;
                }
                if(equation[j - 1] == 'x') {
                    // cout << equation.substr(i, j - i - 1) << endl;
                    x += op * (j - i - 1 ? stoi(equation.substr(i, j - i - 1)) : 1);
                }
                else {
                    // cout << equation.substr(i, j - i) << endl;
                    num += op * stoi(equation.substr(i, j - i));
                }
                i = j - 1;
            }
        }
        if(x == 0) {
            return num == 0 ? "Infinite solutions" : "No solution";
        }
        return "x=" + to_string(num / (-x));
    }
};