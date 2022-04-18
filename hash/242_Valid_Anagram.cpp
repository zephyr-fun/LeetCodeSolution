// 2022.03.27
// use array as hash table, 'A' = 65, 'a' = 97
class Solution {
public:
    bool isAnagram(string s, string t) {
        int record[26] = {0};
        for(int i = 0; i < s.size(); i++){
            record[s[i] - 'a']++;
        }
        for(int i = 0; i < t.size(); i++){
            record[t[i] - 'a']--;
        }
        for(int i = 0; i < 26; i++){
            if(record[i] != 0){
                return false;
            }
        }
        return true;
    }
};
// 2022.03.28
class Solution {
public:
    bool isAnagram(string s, string t) {
        int record[26] = {0};
        for(int i = 0; i < t.size(); i++){
            record[t[i] - 'a']++;
        }
        for(int i = 0; i < s.size(); i++){
            record[s[i] - 'a']--;
        }
        for(int i = 0; i< 26; i++){
            if(record[i] != 0){
                return false;
            }
        }
        return true;
    }
};

// 2022.04.18
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> map;
        for(int i = 0; i < s.size(); i++) {
            map[s[i]]++;
        }
        for(int i = 0; i < t.size(); i++) {
            map[t[i]]--;
        }
        for(auto it = map.begin(); it != map.end(); it++) {
            if(it->second != 0) {
                return false;
            }
        }
        return true;
    }
};