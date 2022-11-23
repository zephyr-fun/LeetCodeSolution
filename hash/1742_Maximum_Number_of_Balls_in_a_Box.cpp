// 2022.11.23
class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        unordered_map<int, int> map;
        int res = 0;
        for(int i = lowLimit; i <= highLimit; i++) {
            int tar = 0;
            int temp = i;
            while(temp) {
                tar += temp % 10;
                temp /= 10;
            }
            map[tar]++;
            res = max(res, map[tar]);
        }
        return res;
    }
};