// 2022.10.23
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        int idx1 = 0;
        int idx2 = 0;
        string res = "";
        while(idx1 < n && idx2 < m) {
            res += word1[idx1];
            res += word2[idx2];
            idx1++;
            idx2++;
        }
        while(idx1 < n) {
            res += word1[idx1];
            idx1++;
        }
        while(idx2 < m) {
            res += word2[idx2];
            idx2++;
        }
        return res;
    }
};