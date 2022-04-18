// 2022.03.27
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int record[26] = {0};
        for(int i = 0; i < ransomNote.size(); i++){
            record[ransomNote[i] - 'a']++;
        }
        for(int i = 0; i < magazine.size(); i++){
            record[magazine[i] - 'a']--;
        }
        for(int i = 0; i < 26; i++){
            if(record[i] > 0){
                return false;
            }
        }
        return true;
    }
};
// 2022.03.28
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int record[26] = {0};
        for(int i = 0; i < ransomNote.size(); i++){
            record[ransomNote[i] - 'a']++;
        }
        for(int i = 0; i < magazine.size(); i++){
            record[magazine[i] - 'a']--;
        }
        for(int i = 0; i < 26; i++){
            if(record[i] > 0){
                return false;
            }
        }
        return true;
    }
};

// 2022.04.18
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> map;
        for(int i = 0; i < magazine.size(); i++) {
            map[magazine[i]]++;
        }
        for(int i = 0; i < ransomNote.size(); i++) {
            map[ransomNote[i]]--;
        }
        for(auto it = map.begin(); it != map.end(); it++) {
            if(it->second < 0) {
                return false;
            }
        }
        return true;
    }
};