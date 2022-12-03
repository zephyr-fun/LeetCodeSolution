// 2022.12.03
class Solution {
public:
    int secondHighest(string s) {
        int first = -1;
        int second = -1;
        for(auto& c : s) {
            int cur = c - '0';
            if(cur >= 0 && cur <= 9) {
                if(first == -1) {
                    first = cur;
                }
                else if(cur > first) {
                    second = first;
                    first = cur;
                }
                else if(cur < first) {
                    second = max(second, cur);
                }
            }
        }
        return second;
    }
};