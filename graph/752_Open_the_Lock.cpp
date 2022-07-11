// 2022.07.11
// bidirectional bfs
class Solution {
public:
    unordered_set<string> set;
    string tar;
    int openLock(vector<string>& deadends, string target) {
        tar = target;
        if("0000" == tar) { // note
            return 0;
        }
        for(auto deadend : deadends) {
            set.insert(deadend);
        }
        if(set.count("0000")) {
            return -1;
        }
        return bfs();
    }
    int bfs() {
        unordered_map<string, int> smap;
        unordered_map<string, int> tmap;
        queue<string> sque;
        queue<string> tque;
        sque.push("0000");
        smap["0000"] = 0;
        tque.push(tar);
        tmap[tar] = 0;
        while(!sque.empty() && !tque.empty()) { // note && not ||
            int t = -1;
            if(sque.size() <= tque.size()) {
                t = update(sque, smap, tmap);
            }
            else {
                t = update(tque, tmap, smap);
            }
            if(t != -1) {
                return t;
            }
        }
        return -1;
    }
    int update(queue<string>& que, unordered_map<string, int>& map1, unordered_map<string, int>& map2) {
        int size = que.size();
        for(int i = 0; i < size; i++) {
            string cur = que.front();
            que.pop();
            int step = map1[cur];
            for(int i = 0; i < 4; i++) {
                for(int j = -1; j <= 1; j++) {
                    if(j == 0) {
                        continue;
                    }
                    string temp = cur;
                    temp[i] = (temp[i] - '0' + j + 10) % 10 + '0';
                    if(map2.count(temp)) {
                        return step + map2[temp] + 1;
                    }
                    if(map1.count(temp) || set.count(temp)) {
                        continue;
                    }
                    que.push(temp);
                    map1[temp] = step + 1;
                }
            }
        }
        return -1;
    }
};