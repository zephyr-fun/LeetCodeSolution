// 2022.08.15
class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> nums;
        int n = words.size();
        for(auto& word : words) {
            int temp = 0;
            for(auto& c : word) {
                int cur = c - 'a';
                temp |= (1 << cur);
            }
            nums.emplace_back(temp);
        }
        int res = 0;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = 0; j < nums.size(); j++) {
                if((nums[i] & nums[j]) == 0) {
                    res = max(res, (int)words[i].size() * (int)words[j].size());
                }
            }
        }
        return res;
    }
};

// 2022.08.29
// hash
class Solution {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<int, int> map;
        for(auto& word : words) {
            int temp = 0;
            for(auto c : word) {
                temp |= 1 << (c - 'a');
            }
            if(!map.count(temp)) {
                map[temp] = word.size();
            }
            else {
                map[temp] = max(map[temp], (int)word.size());
            }
        }
        int res = 0;
        for(auto [ak, av] : map) {
            for(auto [bk, bv] : map) {
                if((ak & bk) == 0) {
                    res = max(res, av * bv);
                }
            }
        }
        return res;
    }
};