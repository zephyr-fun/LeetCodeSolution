// 2022.05.13
// string hash + dp
class Solution {
public:
    int P = 131, OFFSET = 128;
    unordered_set<unsigned long long> set;
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        int size = words.size();
        // preprocess string to a hash set
        for(int i = 0; i < size; i++) {
            unsigned long long hash = 0;
            for(auto& letter : words[i]) {
                hash = hash * P + (letter - 'a') + OFFSET;
            }
            set.insert(hash);
        }
        vector<string> res;
        // for each word, use dp to process it
        for(auto word : words) {
            if(check(word)) {
                res.push_back(word);
            }
        }
        return res;
    }
    bool check(string word) {
        int size = word.size();
        // dp[j], considering the first j chars, the maximum ways to get item
        vector<int> dp(size + 1, -1);
        dp[0] = 0;
        for(int i = 0; i <= size; i++) {
            if(dp[i] == -1) {
                continue;
            }
            unsigned long long cur = 0;
            // i->j form a word in set
            for(int j = i + 1; j <= size; j++) {
                cur = cur * P + (word[j - 1] - 'a') + OFFSET;
                if(set.count(cur)) {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
            cout << "i:" << i << endl;
            for(int k = 0; k <= size; k++) {
                cout << dp[k];
            }
            cout << endl;
            if(dp[size] > 1) {
                    return true;
            }
        }
        return false;
    }
};


// ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]

// ["catsdogcats","dogcatsdog","ratcatdogcat"]

// i:0
// 0,-1,-1,1,
// i:3
// 0,-1,-1,1,

// i:0
// 0,-1,-1,1,1,
// i:3
// 0,-1,-1,1,1,
// i:4
// 0,-1,-1,1,1,

// i:0
// 0,-1,-1,1,1,-1,-1,-1,-1,-1,-1,1,
// i:3
// 0,-1,-1,1,1,-1,-1,-1,-1,-1,-1,1,
// i:4
// 0,-1,-1,1,1,-1,-1,2,-1,-1,-1,1,
// i:7
// 0,-1,-1,1,1,-1,-1,2,-1,-1,3,3,

// i:0
// 0,-1,-1,1,
// i:3
// 0,-1,-1,1,
// i:0
// 0,-1,-1,1,-1,-1,-1,-1,-1,-1,1,
// i:3
// 0,-1,-1,1,-1,-1,2,2,-1,-1,1,
// i:6
// 0,-1,-1,1,-1,-1,2,2,-1,-1,1,
// i:7
// 0,-1,-1,1,-1,-1,2,2,-1,-1,3,
// i:0
// 0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,
// i:14
// 0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,
// i:0
// 0,-1,-1,1,
// i:3
// 0,-1,-1,1,
// i:0
// 0,-1,-1,1,-1,-1,-1,-1,-1,-1,-1,-1,1,
// i:3
// 0,-1,-1,1,-1,-1,2,-1,-1,-1,-1,-1,1,
// i:6
// 0,-1,-1,1,-1,-1,2,-1,-1,3,-1,-1,1,
// i:9
// 0,-1,-1,1,-1,-1,2,-1,-1,3,-1,-1,4,