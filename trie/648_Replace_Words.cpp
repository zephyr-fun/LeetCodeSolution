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

// 2023.05.10
class Trie {
public:
    Trie() {
        memset(son, 0, sizeof(son));
        memset(cnt, 0, sizeof(cnt));
    }
    void insert(string& word) {
        int p = 0;
        for(int i = 0; i < word.size(); i++) {
            int u = word[i] - 'a';
            if(!son[p][u]) {
                son[p][u] = ++idx;
            }
            p = son[p][u];
        }
        cnt[p]++;
    }

    string search(string& word) {
        int p = 0;
        string res;
        for(int i = 0; i < word.size(); i++) {
            res += word[i];
            int u = word[i] - 'a';
            if(!son[p][u]) {
                return "";
            }
            p = son[p][u];
            if(cnt[p]) {
                return res;
            }
        }
        return "";
    }

    // another way for construct searh
    string query(string& word) {
        int p = 0;
        string res;
        for(int i = 0; i < word.size(); i++) {
            res += word[i];
            int u = word[i] - 'a';
            if(!son[p][u]) {
                break;
            }
            p = son[p][u];
            if(cnt[p]) {
                return res;
            }
        }
        return word;
    }

private:
    int son[100007][26];
    int cnt[100007];
    int idx = 0;
};
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie;
        for(auto dict : dictionary) {
            trie.insert(dict);
        }
        int i = 0;
        int j = 0;
        int n = sentence.size();
        string res = "";
        while(j < n) {
            while(j < n && sentence[j] != ' ') {
                j++;
            }
            string cur = sentence.substr(i, j - i);
            string temp = trie.search(cur);
            res += temp == "" ? cur : temp;
            res += ' ';
            i = j + 1;
            j = i;
        }
        return res.substr(0, res.size() - 1);
    }
};

// with another described above way
class Trie {
public:
    Trie() {
        memset(son, 0, sizeof(son));
        memset(cnt, 0, sizeof(cnt));
    }
    void insert(string word) {
        int p = 0;
        for(int i = 0; i < word.size(); i++) {
            int u = word[i] - 'a';
            if(!son[p][u]) {
                son[p][u] = ++idx;
            }
            p = son[p][u];
        }
        cnt[p]++;
    }

    string search(string word) {
        int p = 0;
        string res;
        for(int i = 0; i < word.size(); i++) {
            res += word[i];
            int u = word[i] - 'a';
            if(!son[p][u]) {
                break;
            }
            p = son[p][u];
            if(cnt[p]) {
                return res;
            }
        }
        return word;
    }

private:
    int son[100007][26];
    int cnt[100007];
    int idx = 0;
};
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie;
        for(auto dict : dictionary) {
            trie.insert(dict);
        }
        int i = 0;
        int j = 0;
        int n = sentence.size();
        string res = "";
        while(j < n) {
            while(j < n && sentence[j] != ' ') {
                j++;
            }
            res += trie.search(sentence.substr(i, j - i));
            res += ' ';
            i = j + 1;
            j = i;
        }
        return res.substr(0, res.size() - 1);
    }
};