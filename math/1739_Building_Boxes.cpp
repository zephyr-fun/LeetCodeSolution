// 2022.12.25
// https://en.wikipedia.org/wiki/Tetrahedral_number
// https://leetcode.cn/problems/building-boxes/solution/mei-xiang-ming-bai-yi-ge-dong-hua-miao-d-8vbe/
// https://leetcode.cn/problems/building-boxes/solution/zui-qing-xi-de-ti-jie-copywai-guo-you-re-pnlv/
class Solution {
public:
    int minimumBoxes(int n) {
        int res = 0;
        int max_n = 0;
        for(int i = 1; max_n + res + i <= n; i++) {
            res += i;
            max_n += res;
        }
        for(int j = 1; max_n < n; j++) {
            res++;
            max_n += j;
        }
        return res;
    }
};