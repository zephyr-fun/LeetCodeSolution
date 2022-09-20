// 2022.09.20
class Trie {
private:
    int cnt = 0;
    bool is_end = false;
    Trie* next[26] = {nullptr};
    string res = "";

public:
    Trie() {}

    void insert(string& word) {
        Trie* root = this;
        for(const auto& w : word) {
            int u = w - 'a';
            if(root->next[u] == nullptr) {
                root->next[u] = new Trie();
            }
            root = root->next[u];
            root->cnt++;
        }
        root->is_end = true;
    }

    string query(Trie* root, string cur, int n) {
        // Trie* root = this;
        for(int i = 0; i < 26; i++) {
            if(root->next[i] != nullptr && root->next[i]->cnt == n) {
                res = res.size() > cur.size() + 1 ? res : cur + (char)('a' + i);
                query(root->next[i], cur + (char)('a' + i), n);
            }
        }
        return res;
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie* root = new Trie();
        for(auto& s : strs) {
            root->insert(s);
        }
        return root->query(root, "", strs.size());
    }
};