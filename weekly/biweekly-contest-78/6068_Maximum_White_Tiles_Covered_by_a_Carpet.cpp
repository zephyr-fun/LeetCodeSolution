// 2022.05.15
// class FenwickTree {
// public:
//     FenwickTree(int n): sums_(n + 1, 0) {}

//     void update(int i, int delta) {
//         while(i < sums_.size()) {
//             sums_[i] += delta;
//             i += lowbit(i);
//         }
//     }

//     long long query(int i) {
//         if(i >= sums_.size()) {
//             i = sums_.size() - 1;
//         }
//         long long sum = 0;
//         while(i > 0) {
//             sum += sums_[i];
//             i -= lowbit(i);
//         }
//         // cout << sum;
//         return sum;
//     }

//     void intervalUpdate(int left, int right, int delta) {
//         update(left, delta);
//         update(right + 1, -delta);
//     }

//     int intervalQuery(int left, int right) {
//         return query(right) - query(left - 1);
//     }
// private:
//     vector<long long> sums_;
//     static inline int lowbit(int x) {
//         return x & (-x);
//     }
// };
// class Solution {
// public:
//     int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
//         sort(tiles.begin(), tiles.end(), [](vector<int>& a, vector<int>& b){
//             return a[1] < b[1];
//         });
//         FenwickTree difftree(tiles[tiles.size() - 1][1]);
//         for(int i = 0; i < tiles.size(); i++) {
//             vector<int> temp = tiles[i];
//             difftree.intervalUpdate(temp[0], temp[1], 1);
//         }
//         cout << difftree.query(5);
//         int res = 0;
//         for(int i = 0; i < tiles.size(); i++) {
//             // res = max(res, difftree.intervalQuery(tiles[i][0], (tiles[i][0] + carpetLen - 1) > tiles[tiles.size() - 1][1] ? tiles[tiles.size() - 1][1] : tiles[i][0] + carpetLen - 1));
//             // cout << difftree.intervalQuery(tiles[i][0], (tiles[i][0] + carpetLen - 1));
//             res = max(res, difftree.intervalQuery(tiles[i][0], (tiles[i][0] + carpetLen - 1)));
//         }
//         return res;
//     }
// };

class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(tiles.begin(), tiles.end());
        int res = 0;
        int curLen = 0;
        for(int i = 0, j = 0; i < tiles.size(); i++) {
            while(j < tiles.size() && tiles[j][1] - tiles[i][0] + 1 <= carpetLen) {
                curLen += tiles[j][1] - tiles[j][0] + 1;
                j++;
            }
            if(j < tiles.size()) {
                res = max(res, curLen + max(0, tiles[i][0] + carpetLen - tiles[j][0]));
            }
            else {
                res = max(res, curLen);
            }
            curLen -= tiles[i][1] - tiles[i][0] + 1;
        }
        return res;
    }
};