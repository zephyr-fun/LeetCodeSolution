// 2022.12.27
class Solution {
public:
    int minimumMoves(string s) {
        int n = s.size();
        int i = 0;
        int res = 0;
        while(i < n) {
            if(s[i] == 'X') {
                res++;
                i += 3;
            }
            else {
                i++;
            }
        }
        return res;
    }
};