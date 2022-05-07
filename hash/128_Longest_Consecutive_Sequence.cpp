// 2022.05.07
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for(const int& num : nums) {
            set.insert(num);
        }
        int longestStreak = 0;
        for(const int& num : set) {
            if(!set.count(num - 1)) {
                int currentNum = num;
                int currentLength = 1;
                while(set.count(currentNum + 1)) {
                    currentNum++;
                    currentLength++;
                }
                longestStreak = max(longestStreak, currentLength);
            }
        }
        return longestStreak;
    }
};