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