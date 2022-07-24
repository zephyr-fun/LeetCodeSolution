// 2022.07.12
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left = 0;
        int right = 0;
        unordered_set<char> set;
        int res = 0;
        while(right < n) {
            while(!set.empty() && set.count(s[right])) {
                set.erase(s[left]);
                left++;
            }
            if(set.empty() || !set.count(s[right])) {
                set.insert(s[right]);
                res = max(res, (int)set.size());
                right++;
            }
        }
        return res;
    }
};

// 2022.07.24
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> map;
        int left = 0;
        int right = 0;
        int res = 0;
        while(right < n) {
            map[s[right]]++;
            while(left < right && map[s[right]] > 1) {
                map[s[left]]--;
                left++;
            }
            res = max(res, right - left + 1);
            right++;
        }
        return res;
    }
};