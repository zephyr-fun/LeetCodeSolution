// 2022.06.27
// subsequence
class Solution {
public:
    bool check(string& a, string& b) {
        int k = 0;
        for(auto c : b) {
            if(k < a.size() && c == a[k]) {
                k++;
            }
        }
        return k == a.size();
    }
    int findLUSlength(vector<string>& strs) {
        int res = -1;
        for(int i = 0; i < strs.size(); i++) {
            bool is_sub = false;
            for(int j = 0; j < strs.size(); j++) {
                if(i != j && check(strs[i], strs[j])) {
                    is_sub = true;
                    break;
                }
            }
            if(!is_sub) {
                res = max(res, int(strs[i].size()));
            }
        }
        return res;
    }
};