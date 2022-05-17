// 2022.05.17
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> map;
        for(int i = 0; i < order.size(); i++) {
            map[order[i]] = i;
        }
        if(words.size() <= 1) {
            return true;
        }
        for(int i = 1; i < words.size(); i++) {
            string cur = words[i];
            string prev = words[i - 1];
            int indexCur = 0;
            int indexPrev = 0;
            while(indexCur < cur.size() && indexPrev < prev.size()) {
                if(map[cur[indexCur]] < map[prev[indexPrev]]) {
                    return false;
                }
                else if(map[cur[indexCur]] > map[prev[indexPrev]]) {
                    break;
                }
                indexCur++;
                indexPrev++;
            }
            if(cur.size() < prev.size() && indexCur == cur.size()) {
                return false;
            }
        }
        return true;
    }
};