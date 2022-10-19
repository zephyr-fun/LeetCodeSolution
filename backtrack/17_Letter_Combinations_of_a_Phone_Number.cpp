// 2022.04.01
class Solution {
private: 
    const string letterMap[10] = {
        "",     //0
        "",     //1
        "abc",  //2
        "def",  //3
        "ghi",  //4
        "jkl",  //5
        "mno",  //6
        "pqrs", //7
        "tuv",  //8
        "wxyz"  //9
    };
    vector<string> res;
    string path;
public:
    void backtracking(string digits, int index){
        if(index == digits.size()){
            res.push_back(path);
            return ;
        }
        int digit = digits[index] - '0';
        string letters = letterMap[digit];
        for(int i = 0; i < letters.size(); i++){
            path.push_back(letters[i]);
            backtracking(digits, index + 1);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0){
            return res;
        }
        backtracking(digits, 0);
        return res;
    }
};

// 2022.04.04
class Solution {
public:
    const string letterMap[10] = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
    vector<string> res;
    string path;
    void backtracking(string& digits, int index){
        if(index == digits.size()){
            res.push_back(path);
            return ;
        }
        int digit = digits[index] - '0';
        string letters = letterMap[digit];
        for(int i = 0; i < letters.size(); i++){
            path.push_back(letters[i]);
            backtracking(digits, index + 1);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0){
            return res;
        }
        backtracking(digits, 0);
        return res;
    }
};

// 2022.06.22
class Solution {
public:
    const string letterMap[10] = {
        "",     //0
        "",     //1
        "abc",  //2
        "def",  //3
        "ghi",  //4
        "jkl",  //5
        "mno",  //6
        "pqrs", //7
        "tuv",  //8
        "wxyz"  //9
    };
    vector<string> res;
    string path;
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) {
            return res;
        }
        dfs(digits, 0);
        return res;
    }
    void dfs(string& digits, int startIndex) {
        int n = digits.size();
        if(startIndex == n) {
            res.emplace_back(path);
            return ;
        }
        int cur = stoi(digits.substr(startIndex, 1));
        for(int i = 0; i < letterMap[cur].size(); i++) {
            path += letterMap[cur][i];
            dfs(digits, startIndex + 1);
            path.pop_back();
        }
    }
};

// 2022.06.29
class Solution {
public:
    const string lettermap[10] = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
    void dfs(string& digits, int cur, string& path, vector<string>& res) {
        if(path.size() == digits.size()) {
            res.emplace_back(path);
            return ;
        }
        int temp = digits[cur] - '0';
        for(int i = 0; i < lettermap[temp].size(); i++) {
            path += lettermap[temp][i];
            dfs(digits, cur + 1, path, res);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.size() == 0) {
            return res;
        }
        string path = "";
        dfs(digits, 0, path, res);
        return res;
    }
};

// 2022.10.19
class Solution {
public:
    int n;
    string digits;
    vector<string> res;
    vector<string> digi= {"",
                      "",
                      "abc",
                      "def",
                      "ghi",
                      "jkl",
                      "mno",
                      "pqrs",
                      "tuv",
                      "wxyz"};
    
    void dfs(int cur, string s) {
        if(cur == n) {
            res.emplace_back(s);
            return ;
        }
        for(auto& c : digi[digits[cur] - '0']) {
            dfs(cur + 1, s + c);
        }
    }

    vector<string> letterCombinations(string digits_) {
        if(digits_.size() == 0) {
            return res;
        }
        digits = digits_;
        n = digits.size();
        dfs(0, "");
        return res;
    }
};