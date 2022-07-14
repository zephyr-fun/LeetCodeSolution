// 2022.07.14
// cola version
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