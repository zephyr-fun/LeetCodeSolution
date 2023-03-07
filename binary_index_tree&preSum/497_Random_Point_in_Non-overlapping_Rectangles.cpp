//2023.03.07
class Solution {
public:
    Solution(vector<vector<int>>& rects) : rects{rects} {
        preSum.emplace_back(0);
        for (auto & rect : rects) {
            preSum.emplace_back(preSum.back() + (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1));
        }
    }
    
    vector<int> pick() {
        uniform_int_distribution<int> dis(0, preSum.back() - 1);
        int k = dis(gen) % preSum.back();
        int rectIndex = upper_bound(preSum.begin(), preSum.end(), k) - preSum.begin() - 1;
        k = k - preSum[rectIndex]; // area
        int a = rects[rectIndex][0];
        int b = rects[rectIndex][1];
        int y = rects[rectIndex][3];
        int col = y - b + 1;
        int da = k / col;
        int db = k - col * da;
        return {a + da, b + db};
    }    
private:
    vector<int> preSum;
    vector<vector<int>>& rects;
    mt19937 gen{random_device{}()};
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */

// Alias method
// https://en.wikipedia.org/wiki/Alias_method