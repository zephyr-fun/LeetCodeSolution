// 2022.10.15
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        int idx = 1;
        for(auto& tar : target) {
            if(tar == idx) {
                res.emplace_back("Push");
                idx++;
            }
            else {
                while(idx < tar) {
                    res.emplace_back("Push");
                    res.emplace_back("Pop");
                    idx++;
                }
                res.emplace_back("Push");
                idx++;
            }
        }
        return res;
    }
};

// optim
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        int idx = 1;
        for(auto& tar : target) {
            while(idx < tar) {
                res.emplace_back("Push");
                res.emplace_back("Pop");
                idx++;
            }
            res.emplace_back("Push");
            idx++;
        }
        return res;
    }
};