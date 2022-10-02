// 2022.10.01
// class Solution {
// public:
//     bool equalFrequency(string word) {
//         int cnt[26];
//         memset(cnt, 0, sizeof(cnt));
//         for(auto& c : word) {
//             cnt[c - 'a']++;
//         }
//         unordered_map<int, int> map;
//         for(int i = 0; i < 26; i++) {
//             if(cnt[i] != 0) {
//                 map[cnt[i]]++;
//             }
//         }
//         if(map.size() == 1 && (*map.begin()).second == word.size()) {
//             return true;
//         }
//         if(map.size() >= 3 || map.size() <= 1) {
//             return false;
//         }
//         vector<int> val;
//         vector<int> frq;
//         for(auto& [k, v] : map) {
//             val.emplace_back(k);
//             frq.emplace_back(v);
//         }
//         return (val[0] == val[1] + 1 && frq[0] == 1) || (val[1] == val[0] + 1 && frq[1] == 1) || (val[0] == 1 && frq[0] == 1) || (val[1] == 1 && frq[1] == 1) || (frq[0] == frq[1] + 1 && val[0] == val[1] + 1) || (frq[0] + 1 == frq[1] && val[0] == val[1] + 1);
//     }
// };
// C++ implementation to find the
// Minimum characters to be replaced
// to make frequency of all characters same
// class Solution {
// public:
//     bool equalFrequency(string s)
//     {
//         // Frequency of characters
//         int freq[26] = { 0 };
//         int n = s.length();

//         // Loop to find the Frequency
//         // of each character
//         for (int i = 0; i < n; i++) {
//             freq[s[i] - 'a']++;
//         }

//         // Sort in decreasing order
//         // based on frequency
//         sort(freq, freq + 26, greater<int>());

//         // Maximum possible answer
//         int answer = n;

//         // Loop to find the minimum operations
//         // required such that frequency of
//         // every character is equal
//         for (int i = 1; i <= 26; i++) {
//             if (n % i == 0) {
//                 int x = n / i;
//                 int y = 0;
//                 for (int j = 0; j < i; j++) {
//                     y += min(freq[j], x);
//                 }
//                 answer = min(answer, n - y);
//             }
//         }
//         return answer == 1;
//     }
// };
class Solution {
public:
    bool equalFrequency(string word) {
        int n = word.size();
        for(int i = 0; i < n; i++) {
            unordered_map<int, int> map;
            unordered_set<int> set;
            for(int j = 0; j < n; j++) {
                if(j == i) {
                    continue;
                }
                map[word[j] - 'a']++;
            }
            for(auto [k, v] : map) {
                set.insert(v);
            }
            if(set.size() == 1) {
                return true;
            }
        }
        return false;
    }
};