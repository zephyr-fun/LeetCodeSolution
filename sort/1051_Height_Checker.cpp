// 2022.06.13
// O(nlogn)
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int res = 0;
        vector<int> expect = heights;
        sort(expect.begin(), expect.end());
        int n = heights.size();
        for(int i = 0; i < n; i++) {
            if(heights[i] != expect[i]) {
                res++;
            }
        }
        return res;
    }
};

// O(n), buk sort
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> buk(101, 0);
        int n = heights.size();
        for(int i = 0; i < n; i++) {
            buk[heights[i]]++;
        }
        int res = 0;
        for(int i = 1, j = 0; i < buk.size(); i++) {
            while(buk[i]-- > 0) {
                if(heights[j++] != i) {
                    res++;
                }
            }
        }
        return res;
    }
};