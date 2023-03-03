// 2023.03.03
class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> map;
        for(auto& name : names) {
            int k = map[name];
            if(k) {
                while(map[name + "(" + to_string(k) + ")"]) {
                    k++;
                }
                map[name] = k;
                name += "(" + to_string(k) + ")";
            }
            map[name] = 1;
        }
        return names;
    }
};