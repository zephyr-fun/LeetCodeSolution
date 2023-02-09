// 2023.02.09
class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int n = properties.size();
        sort(properties.begin(), properties.end(), [] (vector<int>& a, vector<int>& b) {
            if(a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] > b[0];
        });
        int res = 0;
        for(int i = 0, maxi = -1; i < n; ) {
            int j = i;
            while(j < n && properties[j][0] == properties[i][0]) {
                if(i != 0 && maxi > properties[j][1]) {
                    res++;
                }
                j++;
            }
            maxi = max(maxi, properties[i][1]);
            i = j;
        }
        return res;
    }
};