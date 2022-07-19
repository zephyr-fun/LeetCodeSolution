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

// repeat
class Solution {
public:
    int n;
    vector<int> nums;
    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();
        nums.resize(n * n + 1, 0);
        bool isRight = true;
        int idx = 1;
        for(int i = n - 1; i >= 0; i--) {
            for(int j = isRight ? 0 : n - 1; isRight ? j < n : j >= 0; isRight ? j++ : j--) {
                nums[idx] = board[i][j];
                idx++;
            }
            isRight = !isRight;
        }
        return bfs();
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
                if(nums[nextCur] != -1) { // order matters, example below
                    nextCur = nums[nextCur];
                }
                if(map.count(nextCur)) {
                    continue;
                }
                // cout << "cur:" << cur << "nc:" << nextCur << "step:" << step + 1 << endl;
                que.push(nextCur);
                map[nextCur] = step + 1;
            }
        }
        return -1;
    }
};
// cur:1nc:15step:1
// cur:1nc:3step:1
// cur:1nc:4step:1
// cur:1nc:5step:1
// cur:1nc:6step:1
// cur:1nc:7step:1
// cur:15nc:16step:2
// cur:15nc:13step:2
// cur:15nc:18step:2
// cur:15nc:19step:2
// cur:15nc:20step:2
// cur:15nc:21step:2
// cur:3nc:8step:2
// cur:3nc:9step:2
// cur:4nc:10step:2
// cur:5nc:11step:2
// cur:6nc:12step:2
// cur:16nc:22step:3  // no cur:16nc:13step:3
// cur:13nc:35step:3
// cur:18nc:23step:3
// cur:18nc:24step:3
// cur:19nc:25step:3
// cur:20nc:26step:3
// cur:21nc:27step:3
// cur:22nc:28step:4
// cur:35nc:36step:4
// cur:23nc:29step:4
// cur:24nc:30step:4
// cur:25nc:31step:4
// cur:26nc:32step:4
// cur:27nc:33step:4
// cur:28nc:34step:5

// cur:1nc:15step:1
// cur:1nc:3step:1
// cur:1nc:4step:1
// cur:1nc:5step:1
// cur:1nc:6step:1
// cur:1nc:7step:1
// cur:15nc:16step:2
// cur:15nc:13step:2
// cur:15nc:18step:2
// cur:15nc:19step:2
// cur:15nc:20step:2
// cur:15nc:21step:2
// cur:3nc:8step:2
// cur:3nc:9step:2
// cur:4nc:10step:2
// cur:5nc:11step:2
// cur:6nc:12step:2
// cur:16nc:13step:3 // already visited when cur:15nc:13step:2, but 17 will never be marked
// cur:16nc:22step:3
// cur:13nc:35step:4
// cur:13nc:13step:4
// cur:18nc:23step:3
// cur:18nc:24step:3
// cur:19nc:25step:3
// cur:20nc:26step:3
// cur:21nc:27step:3
// cur:8nc:35step:3
// cur:9nc:35step:3
// cur:10nc:35step:3
// cur:11nc:35step:3
// cur:11nc:13step:3
// cur:12nc:35step:3
// cur:12nc:13step:3
// cur:13nc:35step:4
// cur:13nc:13step:4
// cur:22nc:28step:4
// cur:35nc:36step:5
// cur:13nc:35step:5
// cur:13nc:13step:5
// cur:23nc:29step:4
// cur:24nc:30step:4
// cur:25nc:31step:4
// cur:26nc:32step:4
// cur:27nc:33step:4
// cur:13nc:35step:6
// cur:13nc:13step:6
// cur:13nc:35step:7
// cur:13nc:13step:7
// cur:13nc:35step:8
// cur:13nc:13step:8
// cur:28nc:34step:5

// 2022.07.19
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        bool isRight = true;
        vector<int> grid(n * m + 1, 0);
        int idx = 1;
        for(int i = n - 1; i >= 0; i--) {
            for(int j = isRight ? 0 : m - 1; isRight ? j < m : j >= 0; isRight ? j++ : j--) {
                grid[idx] = board[i][j];
                idx++;
            }
            isRight = !isRight;
        }
        queue<int> que;
        unordered_map<int, int> map;
        que.push(1);
        map[1] = 0;
        while(!que.empty()) {
            int cur = que.front();
            que.pop();
            int step = map[cur];
            if(cur == n * m) {
                return step;
            }
            for(int i = 1; i <= 6; i++) {
                int next = cur + i;
                if(next > n * m) {
                    continue;
                }
                if(grid[next] != -1) {
                    next = grid[next];
                }
                if(map.count(next)) {
                    continue;
                }
                que.push(next);
                map[next] = step + 1;
            }
        }
        return -1;
    }
};