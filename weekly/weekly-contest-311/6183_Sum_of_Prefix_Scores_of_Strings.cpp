// 2022.09.18
// class Solution {
// public:
//     vector<vector<int>> son;
//     int idx = 0;
//     vector<int> cnt;
    
//     void insert(string& s) {
//         int p = 0;
//         for(int i = 0; i < s.size(); i++) {
//             int u = s[i] - 'a';
//             if(!son[p][u]) {
//                 son[p][u] = ++idx;
//             }
//             p = son[p][u];
//             cnt[p]++;
//         }
//     }
    
//     int query(string& s) {
//         int sum = 0;
//         int p = 0;
//         for(int i = 0; i < s.size(); i++) {
//             int u = s[i] - 'a';
//             if(!son[p][u]) {
//                 return sum;
//             }
//             p = son[p][u];
//             sum += cnt[p];
//         }
//         return sum;
//     }
//     vector<int> sumPrefixScores(vector<string>& words) {
//         son.resize(1000007, vector<int>(26, 0));
//         cnt.resize(1000007, 0);
//         for(auto& word : words) {
//             insert(word);
//         }
//         vector<int> res;
//         for(auto& word : words) {
//             res.emplace_back(query(word));
//         }
//         return res;
//     }
// };
class Trie {
private:
    int cnt = 0;
    bool is_string = false;
    Trie* next[26] = {nullptr};
public:
    Trie() {

    }

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
        root->is_string = true;
    }

    bool startsWith(string& word) {
        Trie* root = this;
        for(const auto& w : word) {
            int u = w - 'a';
            if(root->next[u] != nullptr) {
                root = root->next[u];
                if(root->is_string) {
                    return true;
                }
            }
            else {
                return false;
            }
        }
        return false;
    }

    int query(string& word) {
        Trie* root = this;
        int sum = 0;
        for(const auto& w : word) {
            int u = w - 'a';
            if(root->next[u] == nullptr) {
                return sum;
            }
            root = root->next[u];
            sum += root->cnt;
        }
        return sum;
    }
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie* root = new Trie();
        for(auto& word : words) {
            root->insert(word);
        }
        vector<int> res;
        for(auto& word : words) {
            res.emplace_back(root->query(word));
        }
        return res;
    }
};