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