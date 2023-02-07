// 2023.02.07
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> set;
        for(auto& c : candyType) {
            set.insert(c);
        }
        return min(set.size(), candyType.size() / 2);
    }
};