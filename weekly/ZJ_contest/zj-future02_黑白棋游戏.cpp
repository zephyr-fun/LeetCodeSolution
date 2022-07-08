// 2022.07.08
class Solution {
public:
    int minSwaps(vector<int>& chess) {
        int n = chess.size();
        int ones = 0;
        for(int i = 0; i < n; i++) {
            if(chess[i] == 1) {
                ones++;
            }
        }
        
        int cur = 0;
        for(int i = 0; i < ones; i++) {
            if(chess[i] == 1) {
                cur++;
            }
        }
        int maxVal = cur;
        for(int i = ones; i < n; i++) {
            if(chess[i] == 1) {
                cur++;
            }
            if(chess[i - ones] == 1) {
                cur--;
            }
            maxVal = max(maxVal, cur);
        }
        return ones - maxVal;
    }
};