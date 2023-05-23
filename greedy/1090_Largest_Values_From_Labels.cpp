// 2023.05.23
class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        vector<pair<int, int>> temp;
        int n = values.size();
        for(int i = 0; i < n; i++) {
            temp.push_back({values[i], labels[i]});
        }
        sort(temp.begin(), temp.end(), [] (pair<int, int>& a, pair<int, int>& b) {
            if(a.first == b.first) {
                return a.second < b.second;
            }
            return a.first > b.first;
        });
        int num = 0;
        int res = 0;
        unordered_map<int, int> cnt;
        for(int i = 0; i < n; i++) {
            if(num == numWanted) {
                break;
            }
            if(cnt[temp[i].second] >= useLimit) {
                continue;
            }
            res += temp[i].first;
            cnt[temp[i].second]++;
            num++;
        }
        return res;
    }
};