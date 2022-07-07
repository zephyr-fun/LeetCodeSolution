// 2022.07.07
class Trie {
public:
    vector<vector<int>> son;
    vector<int> cnt;
    int idx;
    Trie() : son(1e5 + 7, vector<int>(26, 0)), cnt(1e5 + 7, 0), idx(0) {

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
    
    bool search(string word) {
        int p = 0;
        for(int i = 0; i < word.size(); i++) {
            int u = word[i] - 'a';
            if(!son[p][u]) {
                return false;
            }
            p = son[p][u];
        }
        return cnt[p] > 0 ? true : false;
    }
    
    bool startsWith(string prefix) {
        int p = 0;
        for(int i = 0; i < prefix.size(); i++) {
            int u = prefix[i] - 'a';
            if(!son[p][u]) {
                return false;
            }
            p = son[p][u];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */