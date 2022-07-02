// 2022.07.02
class Solution {
public:
    int n;
    vector<int> nums;
    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();
        nums.resize(n * n + 1, 0);
        bool isRight = true;
        for(int i = n - 1, idx = 1; i >= 0; i--) {
            for(int j = (isRight ? 0 : n - 1); isRight ? j < n : j >= 0; isRight ? j++ : j--) {
                nums[idx] = board[i][j];
                idx++;
            }
            isRight = !isRight;
        }
        int res = bfs();
        return res;
    }
    int bfs() {
        queue<int> que;
        unordered_map<int, int> map;
        que.push(1);
        map[1] = 0;
        while(!que.empty()) {
            int cur = que.front();
            que.pop();
            int step = map[cur];
            if(cur == n * n) {
                return step;
            }
            for(int i = 1; i <= 6; i++) {
                int nextCur = cur + i;
                if(nextCur > n * n) {
                    continue;
                }
                if(nums[nextCur] != -1) {
                    nextCur = nums[nextCur];
                }
                if(map.count(nextCur)) {
                    continue;
                }
                map[nextCur] = step + 1;
                que.push(nextCur);
            }
        }
        return -1;
    }
};