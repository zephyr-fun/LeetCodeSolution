// 2022.06.04
// prefix + binary search
class Solution {
public:
    Solution(vector<int>& w){
        int n = w.size();
        sum = vector<int>(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + w[i - 1];
        }
        dis = uniform_int_distribution<int>(1, sum[n]);
    }
    
    int pickIndex() {
        int left = 1;
        int right = sum.size() - 1;
        int rand = dis(rng);
        int pos = sum.size() - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(sum[mid] < rand) {
                left = mid + 1;
            }
            else {
                pos = mid;
                right = mid - 1;
            }
        }
        return pos - 1;
    }
private:
    vector<int> sum;
    mt19937 rng;
    uniform_int_distribution<int> dis;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */