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

// 2022.12.10
class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size();
        int left = 0;
        int right = n;
        vector<int> res;
        for(auto& c : s) {
            if(c == 'I') {
                res.emplace_back(left);
                left++;
            }
            else {
                res.emplace_back(right);
                right--;
            }
        }
        res.emplace_back(left);
        return res;
    }
};

// 2022.12.12
class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size();
        int left = 0;
        int right = n;
        vector<int> res;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'I') {
                res.emplace_back(left);
                left++;
            }
            else {
                res.emplace_back(right);
                right--;
            }
        }
        res.emplace_back(left);
        return res;
    }
};