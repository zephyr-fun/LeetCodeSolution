// 2023.06.01
class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        unordered_set<char> set;
        char temp[5] = {'a', 'e', 'i', 'o', 'u'};
        for(int i = 0; i < 5; i++) {
            set.insert(temp[i]);
        }
        // short in 
        // unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int n = words.size();
        int preSum[n + 1];
        memset(preSum, 0, sizeof(preSum));
        function<bool(int)> check = [&] (int num) -> bool{
            if(set.count(words[num][0]) && set.count(words[num].back())) {
                return true;
            }
            return false;
        };
        for(int i = 1; i <= n; i++) {
            preSum[i] = preSum[i - 1] + check(i - 1);
        }
        vector<int> res;
        for(auto& q : queries) {
            res.emplace_back(preSum[q[1] + 1] - preSum[q[0]]);
        }
        return res;
    }
};