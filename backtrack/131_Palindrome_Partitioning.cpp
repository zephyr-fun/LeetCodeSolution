class Solution {
public:
    vector<vector<string>> res;
    vector<string> path;
    bool palindrome(string& s, int start, int end){
        for(int left = start, right = end; left < right; left++, right--){
            if(s[left] != s[right]){
                return false;
            }
        }
        return true;
    }
    void backtracking(string& s, int startIndex){
        if(startIndex >= s.size()){
            res.push_back(path);
            return ;
        }
        for(int i = startIndex; i < s.size(); i++){
            if(palindrome(s, startIndex, i)){
                string temp = s.substr(startIndex, i - startIndex + 1);
                path.push_back(temp);
                backtracking(s, i + 1);
                path.pop_back();
            }
            else{
                continue;
            }
        }
    }
    vector<vector<string>> partition(string s) {
        backtracking(s, 0);
        return res;
    }
};