// 2022.07.29
class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> node = {p1, p2, p3, p4};
        set<int> set;
        for(int i = 0; i < 3; i++) {
            for(int j = i + 1; j < 4; j++) {
                int len1 = node[i][0] - node[j][0];
                int len2 = node[i][1] - node[j][1];
                set.insert(len1 * len1 + len2 * len2);
            }
        }
        return set.size() == 2 && *set.begin() * 2 == *set.rbegin() ? true : false;
    }
};