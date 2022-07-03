// 2022.07.03
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int n, int m, ListNode* head) {
        vector<vector<int>> res(n, vector<int>(m, -1));
        int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int dir = 1;
        int x = 0;
        int y = 0;
        for(int i = 0; i < n * m && head != nullptr; i++) {
            res[x][y] = head->val;
            int nx = x + dirs[dir][0];
            int ny = y + dirs[dir][1];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || res[nx][ny] != -1) {
                dir = (dir + 1) % 4;
                nx = x + dirs[dir][0];
                ny = y + dirs[dir][1];
            }
            x = nx;
            y = ny;
            head = head->next;
        }
        return res;
    }
};