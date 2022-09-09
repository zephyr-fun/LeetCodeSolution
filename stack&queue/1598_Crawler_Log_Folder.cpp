// 2022.09.09
class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> stk;
        for(auto log : logs) {
            if(log == "./") {
                continue;
            }
            if(log == "../") {
                if(!stk.empty()) {
                    stk.pop();
                }
            }
            else {
                stk.push(log);
            }
        }
        return stk.size();
    }
};

// optim space
class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth = 0;
        for(auto log : logs) {
            if(log == "../") {
                depth = max(depth - 1, 0);
            }
            else if(log != "./") {
                depth++;
            }
        }
        return depth;
    }
};