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