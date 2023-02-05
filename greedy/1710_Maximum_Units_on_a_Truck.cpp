// 2022.11.15
class Solution {
public:
    int maximumUnits(vector<vector<int>>& bs, int k) {
        int n = bs.size();
        sort(bs.begin(), bs.end(), [] (auto& a, auto& b) {
            return a[1] > b[1];
        });
        int res = 0;
        for(int i = 0, cnt = 0; i < n && cnt < k; i++) {
            int a = bs[i][0];
            int b = bs[i][1];
            int c = min(a, k - cnt); // introducing a c is a good way to simplify the code
            res += b * c;
            cnt += c;
        }
        return res;
    }
};

// 2023.02.05
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();
        int res = 0;
        sort(boxTypes.begin(), boxTypes.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] > b[1];
        });
        int idx = 0;
        while(truckSize && idx < n) {
            if(truckSize >= boxTypes[idx][0]) {
                truckSize -= boxTypes[idx][0];
                res += boxTypes[idx][0] * boxTypes[idx][1];
                idx++;
            }
            else {
                res += truckSize * boxTypes[idx][1];
                truckSize = 0;
            }
        }
        return res;
    }
};