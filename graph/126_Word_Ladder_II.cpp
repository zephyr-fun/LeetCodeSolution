// 2022.08.22
// plain backtrack TLE
class Solution {
public:
    unordered_set<string> words;
    string bw;
    string ew;
    vector<vector<string>> res;
    vector<string> path;
    unordered_set<string> set;
    int minVal = 0x3f3f3f3f;
    void backtrak(string cur, int step) {
        if(step > minVal) {
            return ;
        }
        if(cur == ew) {
            if(step == minVal) {
                res.emplace_back(path);
            }
            else if(step < minVal) {
                minVal = step;
                res.clear();
                res.emplace_back(path);
            }
            return ;
        }
        for(int i = 0; i < cur.size(); i++) {
            string temp = cur;
            for(int j = 0; j < 26; j++) {
                temp[i] = 'a' + j;
                if(temp != cur && !set.count(temp) && words.count(temp)) {
                    path.emplace_back(temp);
                    set.insert(temp);
                    backtrak(temp, step + 1);
                    path.pop_back();
                    set.erase(temp);
                }
            }
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        for(auto word : wordList) {
            words.insert(word);
        }
        bw = beginWord;
        ew = endWord;
        path.emplace_back(bw);
        set.insert(bw);
        backtrak(bw, 1);
        return res;
    }
};

// bfs + dfs
class Solution {
public:
    int layer;
    vector<vector<string>> res;
    vector<string> path;
    unordered_set<string> words;
    unordered_map<int, unordered_set<string>> map;
    unordered_set<string> vis;
    string bw;
    string ew;
    void backtrack(string cur, int num) {
        if(num == 0) {
            if(cur == bw) {
                reverse(path.begin(), path.end());
                res.emplace_back(path);
                reverse(path.begin(), path.end());
            }
            return ;
        }
        for(int i = 0; i < cur.size(); i++) {
            string temp = cur;
            for(int j = 0; j < 26; j++) {
                temp[i] = 'a' + j;
                if(map[num - 1].count(temp)) {
                    path.emplace_back(temp);
                    backtrack(temp, num - 1);
                    path.pop_back();
                }
            }
        }
    }
    vector<vector<string>> findLadders(string bw_, string ew_, vector<string>& wordList) {
        bw = bw_;
        ew = ew_;
        for(auto word : wordList) {
            words.insert(word);
        }
        if(!words.count(ew)) {
            return res;
        }
        queue<string> que;
        que.push(bw);
        layer = 0;
        bool ok = false;
        while(!que.empty()) {
            int size = que.size();
            for(int i = 0; i < size; i++) {
                string cur = que.front();
                que.pop();
                map[layer].insert(cur);
                if(cur == ew) {
                    ok = true;
                    break;
                }
                for(int j = 0; j < cur.size(); j++) {
                    string temp = cur;
                    for(int k = 0; k < 26; k++) {
                        temp[j] = 'a' + k;
                        if(!vis.count(temp) && words.count(temp)) {
                            vis.insert(temp);
                            que.push(temp);
                        }
                    }
                }
            }
            if(ok) {
                break;
            }
            layer++;
        }
        path.emplace_back(ew);
        backtrack(ew, layer);
        return res;
    }
};