// 2022.08.29 sorted
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int temp = 0;
        int res = 0;
        int n = blocks.size();
        for(int i = 0; i < k; i++) {
            if(blocks[i] == 'W') {
                res++;
            }
        }
        temp = res;
        for(int i = k; i < n; i++) {
            if(blocks[i - k] == 'W') {
                temp--;
            }
            if(blocks[i] == 'W') {
                temp++;
            }
            res = min(res, temp);
        }
        return res;
    }
};