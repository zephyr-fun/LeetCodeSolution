// 2022.07.31
class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n = grades.size();
        int i;
        for(i = 0; i < n; i++) {
            n -= i;
            if(n <= i) {
                break;
            }
        }
        return i;
    }
};

// optim
class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n = grades.size();
        // 加 1e-9 是防止误差，比如答案本来恰好是 3，但是由于误差变成了 2.999...，向下取整就变成 2 了
        return sqrt(0.25 + 2 * n) - 0.5 + 1e-9;
    }
};