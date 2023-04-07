// 2022.05.07
// dual bfs
class Solution {
public:
    string beginWord;
    string endWord;
    static constexpr char CH[4] = {'A', 'C', 'G', 'T'};
    unordered_set<string> set;
    int minMutation(string start, string end, vector<string>& bank) {
        beginWord = start;
        endWord = end;
        for(auto bankWord : bank) {
            set.insert(bankWord);
        }
        if(set.find(end) == set.end()) {
            return -1;
        }
        int res = bfs();
        return res;
    }
    int bfs() {
        queue<string> que1;
        queue<string> que2;
        unordered_map<string, int> map1;
        unordered_map<string, int> map2;
        que1.push(beginWord);
        map1[beginWord] = 0;
        que2.push(endWord);
        map2[endWord] = 0;
        while(!que1.empty() && !que2.empty()) {
            int res = -1;
            if(que1.size() <= que2.size()) {
                res = update(que1, map1, map2);
            }
            else {
                res = update(que2, map2, map1);
            }
            if(res != -1) {
                return res;
            }
        }
        return -1;
    }
    int update(queue<string>& que, unordered_map<string, int>& map, unordered_map<string, int>& viceMap) {
        int size = que.size();
        while(size--) {
            string mutate = que.front();
            que.pop();
            int length = mutate.size();
            string sub;
            for(int i = 0; i < length; i++) {
                sub = mutate;
                for(int j = 0; j < 4; j++) {
                    sub[i] = CH[j];
                    if(set.count(sub)) {
                        if(map.count(sub)) {
                            continue;
                        }
                        if(viceMap.count(sub)) {
                            return map[mutate] + 1 + viceMap[sub];
                        }
                        else {
                            que.push(sub);
                            map[sub] = map[mutate] + 1;
                        }
                    }
                }
            }
        }
        return -1;
    }
};

// 2022.07.24
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> set;
        for(auto bk : bank) {
            set.insert(bk);
        }
        unordered_map<string, int> map;
        map[start] = 0;
        queue<string> que;
        que.push(start);
        while(!que.empty()) {
            string cur = que.front();
            que.pop();
            int step = map[cur];
            if(cur == end) {
                return step;
            }
            for(int i = 0; i < 8; i++) {
                for(int j = 0; j < 26; j++) {
                    string temp = cur;
                    temp[i] = 'A' + j;
                    if(!set.count(temp)) {
                        continue;
                    }
                    if(map.count(temp)) {
                        continue;
                    }
                    map[temp] = step + 1;
                    que.push(temp);
                }
            }
        }
        return -1;
    }
};

// 2023.04.07
// plain bfs
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        int n = startGene.size();
        char mut[4] = {'A', 'C', 'G', 'T'};
        unordered_set<string> set;
        for(auto& b : bank) {
            set.insert(b);
        }
        if(!set.count(endGene)) {
            return -1;
        }
        unordered_map<string, int> map;
        map[startGene] = 0;
        queue<string> que;
        que.push(startGene);
        while(!que.empty()) {
            string cur = que.front();
            que.pop();
            int step = map[cur];
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < 4; j++) {
                    string temp = cur;
                    temp[i] = mut[j];
                    if(temp == cur || map.count(temp) || !set.count(temp)) {
                        continue;
                    }
                    if(temp == endGene) {
                        return step + 1;
                    }
                    que.push(temp);
                    map[temp] = step + 1;
                }
            }
        }
        return -1;
    }
};