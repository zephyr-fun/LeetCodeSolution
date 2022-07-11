// 2022.07.11
// warning TLE
// use int[][] instead of vector<vector<int>>

// trie + dfs
class MagicDictionary {
public:
    int son[10007][26]; // note vector<int> slow
    bool cnt[10007];
    int idx = 0;
    MagicDictionary() {
        memset(son, 0, sizeof(son));
        memset(cnt, false, sizeof(cnt));
    }
    
    void buildDict(vector<string> dictionary) {
        int n = dictionary.size();
        for(auto s : dictionary) {
            update(s);
        }
    }
    
    bool search(string searchWord) {
        return dfsSearch(searchWord, 0, 0, 1);
    }

    void update(string temp) {
        int p = 0;
        for(int i = 0; i < temp.size(); i++) {
            int u = temp[i] - 'a';
            if(!son[p][u]) {
                son[p][u] = ++idx;
            }
            p = son[p][u];
        }
        cnt[p] = true;
    }

    bool dfsSearch(string searchWord, int p, int cur, int left) {
        if(left < 0) {
            return false;
        }
        if(cur == searchWord.size()) {
            if(left == 0 && cnt[p]) {
                return true;
            }
            return false;
        }
        int u = searchWord[cur] - 'a';
        for(int i = 0; i < 26; i++) {
            if(son[p][i] == 0) {
                continue;
            }
            if(dfsSearch(searchWord, son[p][i], cur + 1, i == u ? left : left - 1)) {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */