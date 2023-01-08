// 2023.01.08
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int res = 0;
        int n = pref.size();
        for(auto& word : words) {
            int i = 0;
            int j = 0;
            int m = word.size();
            bool flag = true;
            while(i < m && j < n) {
                if(word[i] != pref[j]) {
                    flag = false;
                    break;
                }
                i++;
                j++;
            }
            if(flag && n <= m) {
                res++;
            }
        }
        return res;
    }
};