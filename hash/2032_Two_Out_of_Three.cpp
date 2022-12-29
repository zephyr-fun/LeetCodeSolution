// 2022.12.29
// plain
class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        int sum[101];
        memset(sum, 0, sizeof(sum));
        unordered_set<int> set;
        for(auto num : nums1) {
            set.insert(num);
        }
        for(auto num : set) {
            sum[num]++;
        }
        set.clear();
        for(auto num : nums2) {
            set.insert(num);
        }
        for(auto num : set) {
            sum[num]++;
        }
        set.clear();
        for(auto num : nums3) {
            set.insert(num);
        }
        for(auto num : set) {
            sum[num]++;
        }
        set.clear();
        vector<int> res;
        for(int i = 1; i <= 100; i++) {
            if(sum[i] >= 2) {
                res.emplace_back(i);
            }
        }
        return res;
    }
};

// optim
class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        auto get = [](vector<int>& nums) {
            vector<int> cnt(101);
            for(auto& num : nums) {
                cnt[num] = 1;
            }
            return cnt;
        };
        auto res1 = get(nums1);
        auto res2 = get(nums2);
        auto res3 = get(nums3);
        vector<int> res;
        for(int i = 1; i <= 100; i++) {
            if(res1[i] + res2[i] + res3[i] > 1) {
                res.emplace_back(i);
            }
        }
        return res;
    }
};