// 2022.12.09
// yxc version
// trie + dfs
class Solution {
public:
    struct Node {
        int id;
        Node *next[26];
        Node() {
            id = -1;
            for(int i = 0; i < 26; i++) {
                next[i] = 0;
            }   
        }
    };

    Node *root;

    void insert(string word, int id) {
        Node *p = root;
        for(char c : word) {
            int son = c - 'a';
            if(!p->next[son]) {
                p->next[son] = new Node();
            }
            p = p->next[son];
        }
        p->id = id;
    }

    unordered_set<string> hash;
    vector<string> ans;
    vector<vector<bool>> st;
    vector<string> _words;
    int n;
    int m;

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if(board.empty()) {
            return ans;
        }
        _words = words;
        root = new Node();
        for(int i = 0; i < words.size(); i++) {
            insert(words[i], i);
        }
        n = board.size();
        m = board[0].size();
        st = vector<vector<bool>>(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                dfs(board, i, j, root->next[board[i][j] - 'a']);
            }     
        }
        return ans;
    }

    void dfs(vector<vector<char>>& board, int x, int y, Node *u)
    {
        if(!u) {
           return;
        }
        st[x][y] = true;
        if(u->id != -1) {
            string match = _words[u->id];
            if(!hash.count(match)) {
                hash.insert(match);
                ans.push_back(match);
            }
        }
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        for(int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if(a >= 0 && a < n && b >= 0 && b < m && !st[a][b]) {
                char c = board[a][b];
                dfs(board, a, b, u->next[c - 'a']);
            }
        }
        st[x][y] = false;
    }
};