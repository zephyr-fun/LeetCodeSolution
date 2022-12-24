// 2022.12.24
// double pointers
class Solution {
public:
    string largestMerge(string word1, string word2) {
        string res = "";
        int n = word1.size();
        int m = word2.size();
        int p1 = 0;
        int p2 = 0;
        while(p1 < n && p2 < m) {
            if(word1.substr(p1) > word2.substr(p2)) { // key point
                res += word1[p1];
                p1++;
            }
            else {
                res += word2[p2];
                p2++;
            }
        }
        res += word1.substr(p1);
        res += word2.substr(p2);
        return res;
    }
};

// optim
class Solution {
public:
    string largestMerge(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        int i = 0, j = 0;
        string res;
        while(i < n && j < m) {
            bool gt = word1.substr(i) > word2.substr(j);
            res += gt ? word1[i++] : word2[j++];
        }
        res += word1.substr(i);
        res += word2.substr(j);
        return res;
    }
};