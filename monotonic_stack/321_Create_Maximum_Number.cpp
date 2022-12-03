// 2022.12.03
// unsolved
class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> res(k, -0x3f3f3f3f);
        for(int i = max(0, k - m); i <= min(k, n); i++) {
            auto a = maxArray(nums1, i);
            auto b = maxArray(nums2, k - i);
            auto c = merge(a, b);
            res = max(res, c);
        }
        return res;
    }

    vector<int> merge(vector<int>& a, vector<int>& b) {
        vector<int> c;
        while (a.size() && b.size()) {
            if(a > b) {
                c.push_back(a[0]);
                a.erase(a.begin());
            }
            else {
                c.push_back(b[0]);
                b.erase(b.begin());
            }
        }   
        while(a.size()) {
            c.push_back(a[0]);
            a.erase(a.begin());
        }
        while(b.size()) {
            c.push_back(b[0]);
            b.erase(b.begin());
        }
        return c;
    }

    vector<int> maxArray(vector<int>& nums, int k) {
        vector<int> res(k);
        int n = nums.size();
        for(int i = 0, j = 0; i < nums.size(); i++) {
            int x = nums[i];
            while(j && res[j - 1] < x && j + n - i > k) {
                j -- ;
            }
            if(j < k) {
                res[j ++ ] = x;
            }
        }
        return res;
    }
};