// 2022.08.29
class Solution {
public:
    string countOfAtoms(string formula) {
        map<string, int> map;
        int n = formula.size();
        string res = "";
        string num = ""; // brilliant
        string form = "";
        int cnt = 1;
        stack<int> st;
        for(int i = n - 1; i >= 0; i--) {
            if(isdigit(formula[i])) {
                num = formula[i] + num;
            }
            else if(formula[i] == ')') {
                int v = num == "" ? 1 : stoi(num);
                num = "";
                cnt *= v;
                st.push(v);
            }
            else if(formula[i] == '(') {
                cnt /= st.top();
                st.pop();
            }
            else {
                form = formula[i] + form;
                if(formula[i] >= 'A' && formula[i] <= 'Z') {
                    map[form] += (num == "" ? 1 : stoi(num)) * cnt;
                    form = "";
                    num = "";
                }
            }
        }
        for(auto& [k, v] : map) {
            res += k;
            if(v > 1) {
                res += to_string(v);
            }
        }
        return res;
    }
};