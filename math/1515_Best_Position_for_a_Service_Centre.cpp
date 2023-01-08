// 2023.01.08
// gradient descent
class Solution {
public:
    double getMinDistSum(vector<vector<int>>& positions) {
        double eps = 1e-7;
        double alpha = 1;
        double decay = 1e-3;
        
        int n = positions.size();
        // 调整批大小
        int batchSize = n;
        
        double x = 0.0, y = 0.0;
        for (const auto& pos: positions) {
            x += pos[0];
            y += pos[1];
        }
        x /= n;
        y /= n;
        
        // 计算服务中心 (xc, yc) 到客户的欧几里得距离之和
        auto getDist = [&](double xc, double yc) {
            double ans = 0;
            for (const auto& pos: positions) {
                ans += sqrt((pos[0] - xc) * (pos[0] - xc) + (pos[1] - yc) * (pos[1] - yc));
            }
            return ans;
        };
        
        mt19937 gen{random_device{}()};

        while (true) {
            // 将数据随机打乱
            shuffle(positions.begin(), positions.end(), gen);
            double xPrev = x;
            double yPrev = y;

            for (int i = 0; i < n; i += batchSize) {
                int j = min(i + batchSize, n);
                double dx = 0.0, dy = 0.0;
                // 计算导数，注意处理分母为零的情况
                for (int k = i; k < j; ++k) {
                    const auto& pos = positions[k];
                    dx += (x - pos[0]) / (sqrt((x - pos[0]) * (x - pos[0]) + (y - pos[1]) * (y - pos[1])) + eps);
                    dy += (y - pos[1]) / (sqrt((x - pos[0]) * (x - pos[0]) + (y - pos[1]) * (y - pos[1])) + eps);
                }
                x -= alpha * dx;
                y -= alpha * dy;

                // 每一轮迭代后，将学习率进行衰减
                alpha *= (1.0 - decay);
            }
            
            // 判断是否结束迭代
            if (sqrt((x - xPrev) * (x - xPrev) + (y - yPrev) * (y - yPrev)) < eps) {
                break;
            }
        }
        
        return getDist(x, y);
    }
};

// climb mountain

// trichotomy