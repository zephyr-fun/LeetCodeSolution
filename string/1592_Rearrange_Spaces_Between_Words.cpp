// 2022.09.07
class Solution {
public:
    string reorderSpaces(string text) {
        vector<string> words;
        int cnt = 0;
        int left = 0;
        int right = 0;
        int n = text.size();
        while(right < n) {
            // cout << left << right << endl;
            while(right < n && text[right] == ' ') {
                right++;
                cnt++;
            }
            left = right;
            while(right < n && text[right] != ' ') {
                right++;
            }
            if(left < right) {
                string temp = text.substr(left, right - left);
                words.emplace_back(temp);
            }
        }
        int arr = 0;
        int leftEnd = 0;
        if(words.size() == 1) {
            arr = 0;
            leftEnd = cnt;
        }
        else {
            arr = cnt / (words.size() - 1);
            leftEnd = cnt - arr * (words.size() - 1);
        }
        string res = "";
        string bs = "";
        string en = "";
        while(arr) {
            bs += ' ';
            arr--;
        }
        while(leftEnd) {
            en += ' ';
            leftEnd--;
        }
        for(int i = 0; i < words.size() - 1; i++) {
            res += words[i];
            res += bs;
        }
        res += words[words.size() - 1];
        res += en;
        return res;
    }
};