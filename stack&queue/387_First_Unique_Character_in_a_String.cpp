// 2022.12.26
// array->map, travel twice
class Solution {
public:
    int firstUniqChar(string s) {
        int map[26];
        memset(map, 0, sizeof(map));
        for(auto& c : s) {
            map[c - 'a']++;
        }
        for(int i = 0; i < s.size(); i++) {
            if(map[s[i] - 'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};

// queue
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> map;
        queue<pair<char, int>> que;
        for(int i = 0; i < s.size(); i++) {
            if(!map.count(s[i])) {
                map[s[i]] = 1;
                que.push(make_pair(s[i], i));
            }
            else {
                map[s[i]] = -1;
                while(!que.empty() && map[que.front().first] == -1) {
                    que.pop();
                }
            }
        }
        return que.empty() ? -1 : que.front().second;
    }
};