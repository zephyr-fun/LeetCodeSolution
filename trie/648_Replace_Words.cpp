// 2022.07.07
// vector<vector<int>> so slow
class Solution {
public:
    int son[100007][26];
    int cnt[100007];
    int idx = 0;

    void insert(string& s) {
        int p = 0;
        for(int i = 0; i < s.size(); i++) {
            int u = s[i] - 'a';
            if(!son[p][u]) {
                son[p][u] = ++idx;
            }
            p = son[p][u];
        }
        cnt[p]++;
    }

    string query(string& s) {
        int p = 0;
        string res = "";
        for(int i = 0; i < s.size(); i++) {
            int u = s[i] - 'a';
            if(!son[p][u]) {
                break;
            }
            res += s[i];
            p = son[p][u];
            if(cnt[p] != 0) {
                return res;
            }
        }
        return s;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        memset(son, 0, sizeof(son));
        memset(cnt, 0, sizeof(cnt));
        for(auto dic : dictionary) {
            insert(dic);
        }
        string res = "";
        istringstream ss(sentence);
        string temp = "";
        while(ss >> temp) {
            res += query(temp);
            res += " ";
        }
        return res.substr(0, res.size() - 1);
    }
};