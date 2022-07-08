// 2022.05.07
// dual bfs
class Solution {
public:
    string start;
    string end;
    unordered_set<string> set;
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        start = beginWord;
        end = endWord;
        for(auto word : wordList) {
            set.insert(word);
        }
        if(set.find(endWord) == set.end()) {
            return -1;
        }
        int res = bfs();
        return res + 1;
    }
    int bfs() {
        // que1 refers to search from beginword
        // que2 refers to search from endword
        queue<string> que1;
        queue<string> que2;

        // map1 records <string, transform step(from beginword)>
        // map2 records <string, transform step(from endword)>
        unordered_map<string, int> map1;
        unordered_map<string, int> map2;

        que1.push(start);
        map1[start] = 0;
        que2.push(end);
        map2[end] = 0;

        while(!que1.empty() && !que2.empty()) {
            int t = -1;
            if(que1.size() <= que2.size()) {
                t = update(que1, map1, map2);
            }
            else {
                t = update(que2, map2, map1);
            }
            if(t != -1) {
                return t;
            }
        }
        return -1;
    }
    int update(queue<string>& que, unordered_map<string, int>& map, unordered_map<string, int>& viceMap) {
        int size = que.size();
        while(size-- > 0) {
            string poll = que.front();
            que.pop();
            int wordSize = poll.size();
            string sub;
            for(int i = 0; i < wordSize; i++) {
                sub = poll;
                for(int j = 0; j < 26; j++) {
                    sub[i] = char(j + 'a');
                    if(set.count(sub)) {
                        if(map.count(sub)) {
                            continue;
                        }
                        if(viceMap.count(sub)) {
                            return map[poll] + 1 + viceMap[sub];
                        }
                        else {
                            que.push(sub);
                            map[sub] = map[poll] + 1;
                        }
                    }
                }
            }
        }
        return -1;
    }
};

// 2022.07.08
class Solution {
public:
    unordered_set<string> wordList;
    int ladderLength(string beginWord, string endWord, vector<string>& wordList_) {
        for(auto word : wordList_) {
            wordList.insert(word);
        }
        if(!wordList.count(endWord)) {
            return 0;
        }
        queue<string> bque;
        unordered_map<string, int> bmap;
        queue<string> eque;
        unordered_map<string, int> emap;
        bque.push(beginWord);
        eque.push(endWord);
        bmap[beginWord] = 0;
        emap[endWord] = 0;
        while(!bque.empty() && !eque.empty()) {
            int t = -1;
            if(bque.size() <= eque.size()) {
                t = update(bque, eque, bmap, emap);
            }
            else {
                t = update(eque, bque, emap, bmap);
            }
            if(t != -1) {
                return t;
            }
        }
        return 0;
    }
    int update(queue<string>& que1, queue<string>& que2, unordered_map<string, int>& map1, unordered_map<string, int>& map2) {
        int size = que1.size();
        while(size--) {
            string cur = que1.front();
            que1.pop();
            int step = map1[cur];
            for(int i = 0; i < cur.size(); i++) {
                for(int j = 0; j < 26; j++) {
                    if(cur[i] - 'a' == j) {
                        continue;
                    }
                    string temp = cur;
                    temp[i] = 'a' + j;
                    if(!wordList.count(temp) || map1.count(temp)) {
                        continue;
                    }
                    if(map2.count(temp)) {
                        return map2[temp] + step + 1 + 1;
                    }
                    que1.push(temp);
                    map1[temp] = step + 1;
                }
            }
        }
        return -1;
    }
};

// 2022.07.08
// change start state
class Solution {
public:
    unordered_set<string> wordList;
    int ladderLength(string beginWord, string endWord, vector<string>& wordList_) {
        for(auto word : wordList_) {
            wordList.insert(word);
        }
        if(!wordList.count(endWord)) {
            return 0;
        }
        queue<string> bque;
        unordered_map<string, int> bmap;
        queue<string> eque;
        unordered_map<string, int> emap;
        bque.push(beginWord);
        eque.push(endWord);
        bmap[beginWord] = 1; // change
        emap[endWord] = 0;
        while(!bque.empty() && !eque.empty()) {
            int t = -1;
            if(bque.size() <= eque.size()) {
                t = update(bque, eque, bmap, emap);
            }
            else {
                t = update(eque, bque, emap, bmap);
            }
            if(t != -1) {
                return t;
            }
        }
        return 0;
    }
    int update(queue<string>& que1, queue<string>& que2, unordered_map<string, int>& map1, unordered_map<string, int>& map2) {
        int size = que1.size();
        while(size--) {
            string cur = que1.front();
            que1.pop();
            int step = map1[cur];
            for(int i = 0; i < cur.size(); i++) {
                for(int j = 0; j < 26; j++) {
                    if(cur[i] - 'a' == j) {
                        continue;
                    }
                    string temp = cur;
                    temp[i] = 'a' + j;
                    if(!wordList.count(temp) || map1.count(temp)) {
                        continue;
                    }
                    if(map2.count(temp)) {
                        return map2[temp] + step + 1;
                    }
                    que1.push(temp);
                    map1[temp] = step + 1;
                }
            }
        }
        return -1;
    }
};