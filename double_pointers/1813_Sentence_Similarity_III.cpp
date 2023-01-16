// 2023.01.16
class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        if(sentence1.size() > sentence2.size()) {
            return areSentencesSimilar(sentence2, sentence1);
        }
        int left = 0;
        int right = 0;
        auto s1 = split(sentence1);
        auto s2 = split(sentence2);
        int n = s1.size();
        int m = s2.size();
        while(left < n && s1[left] == s2[left]) {
            left++;
        }
        while(right < n - left && s1[n - 1 - right] == s2[m - 1 - right]) {
            right++;
        }
        return left + right == n;
    }
    vector<string> split(string s) {
        vector<string> res;
        stringstream ss;
        ss << s;
        while(ss >> s) {
            res.emplace_back(s);
        }
        return res;
    }
};