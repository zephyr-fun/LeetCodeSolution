// 2022.05.09
class Solution {
public:
    vector<int> diStringMatch(string s) {
        int lower = 0;
        int upper = s.size();
        vector<int> res;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'I') {
                res.push_back(lower);
                lower++;
            }
            else {
                res.push_back(upper);
                upper--;
            }
        }
        res.push_back(lower);
        return res;
    }
};