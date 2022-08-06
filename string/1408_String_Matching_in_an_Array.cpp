// 2022.08.06
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> res;
        for(int i = 0; i < words.size(); i++) {
            string& temp = words[i];
            for(int j = 0; j < words.size(); j++) {
                if(i == j) {
                    continue;
                }
                if(words[j].find(temp) != string::npos) {
                    res.emplace_back(temp);
                    break;
                }
            }
        }
        return res;
    }
};