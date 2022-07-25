// 2022.07.23
class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        unordered_set<int> set;
        int res = 0;
        for(auto roll : rolls) {
            set.insert(roll);
            if(set.size() == k) {
                res++;
                set.clear();
            }
        }
        return res + 1;
    }
};