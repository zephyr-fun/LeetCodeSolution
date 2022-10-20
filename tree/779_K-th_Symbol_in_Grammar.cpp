// 2022.10.20
// like a binary tree
class Solution {
public:
    int kthGrammar(int n, int k) {
        return n == 1 ? 0 : (!(k % 2)) ^ kthGrammar(n - 1, (k + 1) / 2);
    }
};