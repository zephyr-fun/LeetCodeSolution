// 2023.06.03
class Solution {
public:
    int maxRepOpt1(string text) {
        int n = text.size();
        int cnt[26] = {0};
        for(char& c : text) {
            cnt[c - 'a']++;
        }
        int res = 0;
        int i = 0;
        int j = 0;
        while(i < n) {
            j = i;
            while(j < n && text[i] == text[j]) {
                j++;
            }
            int l = j - i;
            int k = j + 1;
            while(k < n && text[i] == text[k]) {
                k++;
            }
            int r = k - j - 1;
            res = max(res, min(l + r + 1, cnt[text[i] - 'a']));
            i = j;
        }
        return res;
    }
};