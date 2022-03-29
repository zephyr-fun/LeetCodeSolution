// 2022.03.27
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> map;
        for(int a : nums1){
            for(int b : nums2){
                map[a + b]++;
            }
        }
        int res = 0;
        for(int c : nums3){
            for(int d : nums4){
                if(map.find(0 - (c + d)) != map.end()){
                    res += map[0 - (c + d)];
                }
            }
        }
        return res;
    }
};
// 2022.03.29
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> map; // a + b, count;
        int res = 0;
        for(int i = 0; i < nums1.size(); i++){
            for(int j = 0; j < nums2.size(); j++){
                map[nums1[i] + nums2[j]]++;
            }
        }
        for(int i = 0; i < nums3.size(); i++){
            for(int j = 0; j < nums4.size(); j++){
                if(map.find(0 - nums3[i] - nums4[j]) != map.end()){
                    res += map[0 - nums3[i] - nums4[j]];
                }
            }
        }
        return res;
    }
};