// hash add and delete
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()){
            return intersect(nums2, nums1);
        }
        unordered_map<int, int> map;
        for(int i= 0; i < nums1.size(); i++){
            map[nums1[i]]++;
        }
        vector<int> res;
        for(int i = 0; i < nums2.size(); i++){
            if(map.count(nums2[i]) != 0){
                map[nums2[i]]--;
                res.push_back(nums2[i]);
            }
            if(map[nums2[i]] == 0){
                map.erase(nums2[i]);
            }
        }
        return res;
    }
};
// double pointers
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int length1 = nums1.size();
        int length2 = nums2.size();
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int index1 = 0;
        int index2 = 0;
        vector<int> res;
        while(index1 < length1 && index2 < length2){
            if(nums1[index1] < nums2[index2]){
                index1++;
            }
            else if(nums1[index1] > nums2[index2]){
                index2++;
            }
            else{
                res.push_back(nums1[index1]);
                index1++;
                index2++;
            }
        }
        return res;
    }
};