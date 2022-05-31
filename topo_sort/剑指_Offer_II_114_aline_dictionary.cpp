// 2022.05.31
constexpr static int N = 26, M = N * N;
static int head[N], to[M], ne[M], in[N], out[N];
static bool visited[N];
class Solution {
public:
    int idx = 0;
    int cnt = 0;
    void add(int a, int b) {
        to[idx] = b;
        ne[idx] = head[a];
        head[a] = idx;
        idx++;
        out[a]++;
        in[b]++;
    }
    bool build(const string& a, const string& b) {
        int n = a.size();
        int m = b.size();
        int len = min(n, m);
        for(int i = 0; i < len; i++) {
            int c1 = a[i] - 'a';
            int c2 = b[i] - 'a';
            if(c1 != c2) {
                add(c1, c2);
                return true;
            }
        }
        return n <= m;
    }
    string alienOrder(vector<string>& words) {
        fill_n(head, N, -1);
        fill_n(visited, N, false);
        fill_n(in, N, 0);
        fill_n(out, N, 0);
        int n = words.size();
        for(int i = 0; i < n; i++) {
            for(auto& c : words[i]) {
                if(!visited[c - 'a'] && ++cnt > 0) {
                    visited[c - 'a'] = true;
                }
            }
            for(int j = 0; j < i; j++) {
                if(!build(words[j], words[i])) {
                    return "";
                }
            }
        }
        queue<int> que;
        string res;
        for(int i = 0; i < 26; i++) {
            if(visited[i] && in[i] == 0) {
                que.push(i);
            }
        }
        while(!que.empty()) {
            int a = que.front();
            que.pop();
            res.push_back((char)(a + 'a'));
            for(int i = head[a]; i != -1; i = ne[i]) {
                int b = to[i];
                in[b]--;
                if(in[b] == 0) {
                    que.push(b);
                }
            }
        }
        return res.size() == cnt ? res : "";
    }
};