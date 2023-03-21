// 2023.03.21
/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
// recursion + 2-dim preSum
class Solution {
public:
    vector<vector<int>> preSum;
    Node* bulid(int topx, int topy, int botx, int boty) {
        if(topx > botx || topy > boty) {
            return nullptr;
        }
        Node* cur = new Node();
        int cnt = preSum[botx + 1][boty + 1] - preSum[topx][boty + 1] - preSum[botx + 1][topy] + preSum[topx][topy];
        if(cnt == (botx - topx + 1) * (boty - topy + 1) || cnt == 0) {
            cur->isLeaf = true;
            cur->val = cnt > 0;
            return cur;
        }
        cur->topLeft = bulid(topx, topy, (topx + botx) / 2, (topy + boty) / 2);
        cur->topRight = bulid(topx, (topy + boty + 1) / 2, (topx + botx) / 2, boty);
        cur->bottomLeft = bulid((topx + botx + 1) / 2, topy, botx, (topy + boty) / 2);
        cur->bottomRight = bulid((topx + botx + 1) / 2, (topy + boty + 1) / 2, botx, boty);
        return cur;
    }
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        preSum.resize(n + 1, vector<int>(n + 1, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                preSum[i + 1][j + 1] = preSum[i][j + 1] + preSum[i + 1][j] - preSum[i][j] + grid[i][j];
            }
        }
        return bulid(0, 0, n - 1, n - 1);
    }
};