// 2022.11.08
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> set;
        for(auto& c : allowed) {
            set.insert(c);
        }
        int res = 0;
        for(auto& word : words) {
            bool flag = true;
            for(auto& c : word) {
                if(!set.count(c)) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                res++;
            }
        }
        return res;
    }
};