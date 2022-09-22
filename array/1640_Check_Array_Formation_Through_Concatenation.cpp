// 2022.09.22
class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int, int> map;
        int n = arr.size();
        int m = pieces.size();
        for(int i = 0; i < m; i++) {
            map[pieces[i][0]] = i;
        }
        int idx = 0;
        while(idx < n) {
            if(!map.count(arr[idx])) {
                return false;
            }
            else {
                int temp = idx;
                for(auto p : pieces[map[arr[temp]]]) {
                    if(p != arr[idx]) {
                        break;
                    }
                    else {
                        idx++;
                    }
                }
                if(idx - temp != pieces[map[arr[temp]]].size()) {
                    return false;
                }
            }
        }
        return true;
    }
};