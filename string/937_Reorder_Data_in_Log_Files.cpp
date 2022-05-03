// 2022.05.03
// custom cmp function
class Solution {
public:
    static bool cmp(string a, string b) {
        int contentAStartIndex;
        int contentBStartIndex;
        for(int i = 0; i < a.size(); i++) {
            if(a[i] == ' ') {
                contentAStartIndex = i + 1;
                break;
            }
        }
        for(int i = 0; i < b.size(); i++) {
            if(b[i] == ' ') {
                contentBStartIndex = i + 1;
                break;
            }
        }
        string subA = a.substr(contentAStartIndex, a.size() - contentAStartIndex + 1);
        string subB = b.substr(contentBStartIndex, b.size() - contentBStartIndex + 1);
        if(subA == subB) {
            return a < b;
        }
        return subA < subB;
    }
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> files;
        for(auto s : logs) {
            int length = s.size();
            if(s[length - 1] < 48 || s[length - 1] > 57) {
                files.push_back(s);
            }
        }
        sort(files.begin(), files.end(), cmp);
        for(auto s : logs) {
            int length = s.size();
            if(s[length - 1] >= 48 && s[length - 1] <= 57) {
                files.push_back(s);
            }
        }
        return files;
    }
};