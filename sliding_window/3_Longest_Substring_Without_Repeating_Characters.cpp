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