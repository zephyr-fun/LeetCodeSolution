// 2022.04.02
class Solution {
public:
    vector<string> res;
    bool isValid(string& s, int start, int end){
        if(start > end){
            return false;
        }
        if(s[start] == '0' && start != end){
            return false;
        }
        int temp_num = 0;
        for(int i = start; i <= end; i++){
            if(s[i] > '9' || s[i] < '0'){
                return false;
            }
            temp_num = temp_num * 10 + (s[i] - '0');
            if(temp_num > 255){
                return false;
            }
        }
        return true;
    }
    void backtracking(string& s, int startIndex, int num_point){
        if(num_point == 3){
            if(isValid(s, startIndex, s.size() - 1)){
                res.push_back(s);
            }
            return ;
        }
        for(int i = startIndex; i < s.size(); i++){
            if(isValid(s, startIndex, i)){
                s.insert(s.begin() + i + 1, '.');
                num_point++;
                backtracking(s, i + 2, num_point);
                s.erase(s.begin() + i + 1);
                num_point--;
            }
            else{
                break;
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        if(s.size() > 12){
            return res;
        }
        backtracking(s, 0, 0);
        return res;
    }
};

// 2022.04.04
class Solution {
public:
    vector<string> res;
    bool isValid(string& s, int start, int end){
        if(start > end){
            return false;
        }
        if(s[start] == '0' && start != end){ // notice '0' not 0
            return false;
        }
        int temp_num = 0;
        for(int i = start; i <= end; i++){
            if(s[i] < '0' || s[i] > '9'){
                return false;
            }
            temp_num = temp_num * 10 + (s[i] - '0');
            if(temp_num > 255){
                return false;
            }
        }
        return true;
    }
    void backtracking(string& s, int startIndex, int num_points){
        if(num_points == 3){
            if(isValid(s, startIndex, s.size() - 1)){
                res.push_back(s);
            }
            return ;
        }
        for(int i = startIndex; i < s.size(); i++){
            if(isValid(s, startIndex, i)){
                s.insert(s.begin() + i + 1, '.');
                num_points++;
                backtracking(s, i + 2, num_points); // notice i+2, cause insert a '.'
                s.erase(s.begin() + i + 1);
                num_points--;
            }
            else{
                break; // isVaild has Monotonicity
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        if(s.size() > 12){
            return res;
        }
        backtracking(s, 0, 0);
        return res;
    }
};

// 2022.07.06
class Solution {
public:
    vector<string> res;
    bool isValid(string& s, int start, int end) {
        if(start > end) {
            return false;
        }
        if(s[start] == '0' && start != end) {
            return false;
        }
        int sum = 0;
        for(int i = start; i <= end; i++) {
            if(s[i] < '0' || s[i] > '9') {
                return false;
            }
            sum *= 10;
            sum += s[i] - '0';
            if(sum > 255) {
                return false;
            }
        }
        return true;
    }

    void dfs(string s, int start, int cnt) {
        if(cnt == 3) {
            if(isValid(s, start, s.size() - 1)) {
                res.emplace_back(s);
            }
            return ;
        }
        for(int i = start; i < s.size(); i++) {
            if(isValid(s, start, i)) {
                s.insert(s.begin() + i + 1, '.');
                dfs(s, i + 2, cnt + 1);
                s.erase(s.begin() + i + 1);
            }
            else {
                break;
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        if(s.size() > 12) {
            return res;
        }
        dfs(s, 0, 0);
        return res;
    }
};

// 2022.07.09
class Solution {
public:
    vector<string> res;
    bool isValid(string s, int start, int end) {
        int cur = 0;
        if(start > end) {
            return false;
        }
        if(s[start] == '0' && start != end) {
            return false;
        }
        for(int i = start; i <= end; i++) {
            if(s[i] > '9' || s[i] < '0') {
                return false;
            }
            cur = cur * 10 + s[i] - '0';
            if(cur > 255) {
                return false;
            }
        }
        return true;
    }
    void dfs(string s, int cur, int cnt) {
        if(cnt == 3) {
            if(isValid(s, cur, s.size() - 1)) {
                res.emplace_back(s);
            }
            return ;
        }
        for(int i = cur; i < s.size(); i++) {
            if(isValid(s, cur, i)) {
                s.insert(s.begin() + i + 1, '.');
                dfs(s, i + 2, cnt + 1);
                s.erase(s.begin() + i + 1);
            }
            else {
                break;
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        if(s.size() > 12) {
            return res;
        }
        dfs(s, 0, 0);
        return res;
    }
};