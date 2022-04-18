// 2022.03.27
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> res;
        unordered_set<int> num_set(nums1.begin(), nums1.end());
        for(int i =0; i < nums2.size(); i++){
            if(num_set.find(nums2[i]) != num_set.end()){
                res.insert(nums2[i]);
            }
        }
        return vector<int>(res.begin(), res.end());
    }
};
// 2022.03.29
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> nums1_set;
        unordered_set<int> res_set;
        for(int i = 0; i < nums1.size(); i++){
            nums1_set.insert(nums1[i]);
        }
        for(int i = 0; i < nums2.size(); i++){
            if(nums1_set.find(nums2[i]) != nums1_set.end()){
                res_set.insert(nums2[i]);
            }
        }
        return vector<int>(res_set.begin(), res_set.end());
    }
};

// 2022.04.18
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1;
        unordered_set<int> res;
        for(int i = 0; i < nums1.size(); i++) {
            set1.insert(nums1[i]);
        }
        for(int i = 0; i < nums2.size(); i++) {
            if(set1.find(nums2[i]) != set1.end()) {
                res.insert(nums2[i]);
            }
        }
        return vector<int> (res.begin(), res.end());
    }
};