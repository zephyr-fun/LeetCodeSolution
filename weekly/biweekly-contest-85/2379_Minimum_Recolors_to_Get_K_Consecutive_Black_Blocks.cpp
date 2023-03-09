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

// 2023.03.09
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int cur = 0;
        for(int i = 0; i < k; i++) {
            cur += (blocks[i] == 'B' ? 0 : 1);
        }
        int res = cur;
        for(int i = k; i < blocks.size(); i++) {
            cur += (blocks[i] == 'B' ? 0 : 1);
            cur += (blocks[i - k] == 'B' ? 0 : -1);
            res = min(res, cur);
        }
        return res;
    }
};