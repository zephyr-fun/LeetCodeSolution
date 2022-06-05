// 2022.06.05
// https://leetcode.cn/problems/generate-random-point-in-a-circle/solution/c-tui-dao-gai-lu-fen-bu-by-vclip-wp0z/
class Solution {
public:
    double x, y, r;
    mutable mt19937 re;
    Solution(double radius, double x_center, double y_center): x(x_center), y(y_center), r(radius), re(random_device{} ()) {}
    
    vector<double> randPoint() {
        uniform_real_distribution<double> ud(-r, r);
        double dx = ud(re);
        double dy = ud(re);
        while(dx * dx + dy * dy > r * r) {
            dx = ud(re);
            dy = ud(re);
        }
        return {x + dx, y + dy};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */