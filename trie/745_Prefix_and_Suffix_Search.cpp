// 2022.07.14
// cola version
// dynamic trie
class WordFilter {
public:
    struct TrieNode {
        TrieNode* tns[26] {nullptr};
        vector<int> idxs;
    };
    void add(TrieNode* p, const string& s, int idx, bool isTurn) {
        int n = s.size();
        p->idxs.push_back(idx);
        for(int i = isTurn ? n - 1 : 0; i >= 0 && i < n; i += isTurn ? -1 : 1) {
            int u = s[i] - 'a';
            if(p->tns[u] == nullptr) p->tns[u] = new TrieNode();
            p = p->tns[u];
            p->idxs.push_back(idx);
        }
    }
    int query(const string& a, const string& b) {
        int n = a.size(), m = b.size();
        auto p = tr1;
        for(int i = 0; i < n; i++) {
            int u = a[i] - 'a';
            if(p->tns[u] == nullptr) return -1;
            p = p->tns[u];
        }
        vector<int>& l1 = p->idxs;
        p = tr2;
        for(int i = m - 1; i >= 0; i--) {
            int u = b[i] - 'a';
            if(p->tns[u] == nullptr) return -1;
            p = p->tns[u];
        }
        vector<int>& l2 = p->idxs;
        n = l1.size(), m = l2.size();
        for(int i = n - 1, j = m - 1; i >= 0 && j >= 0; ) {
            if(l1[i] > l2[j]) i--;
            else if(l1[i] < l2[j]) j--;
            else return l1[i];
        }
        return -1;
    }
    TrieNode* tr1 = new TrieNode, *tr2 = new TrieNode;
    WordFilter(vector<string>& ss) {
        int n = ss.size();
        for(int i = 0; i < n; i++) {
            add(tr1, ss[i], i, false);
            add(tr2, ss[i], i, true);
        }
    }
    
    int f(string a, string b) {
        return query(a, b);
    }
};

// 2022.09.25
// fxz version
class WordFilter {
public:
    struct TrieNode {
        vector<int> idxs;
        TrieNode* next[26] {nullptr};
    };

    void add(TrieNode* p, const string& s, int idx, bool isTurn) {
        int n = s.size();
        p->idxs.emplace_back(idx);
        for(int i = isTurn ? n - 1 : 0; i >= 0 && i < n; i += isTurn ? -1 : 1) {
            int u = s[i] - 'a';
            if(p->next[u] == nullptr) {
                p->next[u] = new TrieNode();
            }
            p = p->next[u];
            p->idxs.emplace_back(idx);
        }
    }

    int query(TrieNode* tr1, TrieNode* tr2, const string& a, const string& b) {
        int n = a.size();
        int m = b.size();
        auto p = tr1;
        for(int i = 0; i < n; i++) {
            int u = a[i] - 'a';
            if(p->next[u] == nullptr) {
                return -1;
            }
            p = p->next[u];
        }
        vector<int>& l1 = p->idxs;
        p = tr2;
        for(int i = m - 1; i >= 0; i--) {
            int u = b[i] - 'a';
            if(p->next[u] == nullptr) {
                return -1;
            }
            p = p->next[u];
        }
        vector<int>& l2 = p->idxs;
        n = l1.size();
        m = l2.size();
        for(int i = n - 1, j = m - 1; i >= 0 && j >= 0; ) {
            if(l1[i] > l2[j]) {
                i--;
            }
            else if(l1[i] < l2[j]) {
                j--;
            }
            else {
                return l1[i];
            }
        }
        return -1;
    }

    TrieNode* tr1 = new TrieNode();
    TrieNode* tr2 = new TrieNode();

    WordFilter(vector<string>& words) {
        int n = words.size();
        for(int i = 0; i < n; i++) {
            add(tr1, words[i], i, false);
            add(tr2, words[i], i, true);
        }
    }
    
    int f(string pref, string suff) {
        return query(tr1, tr2, pref, suff);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */

// 2023.05.29
class WordFilter {
public:
    struct Node {
        Node* next[26] = {nullptr};
        vector<int> ids;
    }*pre, *suf;

    void insert(Node* p, const string& s, int id, bool isTurn) {
        int n = s.size();
        p->ids.emplace_back(id);
        for(int i = isTurn ? n - 1 : 0; isTurn ? i >= 0 : i < n; isTurn ? i-- : i++) {
            int u = s[i] - 'a';
            if(p->next[u] == nullptr) {
                p->next[u] = new Node();
            }
            p = p->next[u];
            p->ids.emplace_back(id);
        }
    }

    WordFilter(vector<string>& words) {
        pre = new Node();
        suf = new Node();
        for(int i = 0; i < words.size(); i++) {
            insert(pre, words[i], i, false);
            insert(suf, words[i], i, true);
        }
    }

    int f(string pref, string suff) {
        int n = pref.size();
        int m = suff.size();
        auto p = pre;
        for(int i = 0; i < n; i++) {
            int u = pref[i] - 'a';
            if(p->next[u] == nullptr) {
                return -1;
            }
            p = p->next[u];
        }
        vector<int>& l1 = p->ids;
        p = suf;
        for(int i = m - 1; i >= 0; i--) {
            int u = suff[i] - 'a';
            if(p->next[u] == nullptr) {
                return -1;
            }
            p = p->next[u];
        }
        vector<int>& l2 = p->ids;
        n = l1.size();
        m = l2.size();
        for(int i = n - 1, j = m - 1; i >= 0 && j >= 0; ) {
            if(l1[i] > l2[j]) {
                i--;
            }
            else if(l1[i] < l2[j]) {
                j--;
            }
            else {
                return l1[i];
            }
        }
        return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */