// 2022.08.19
class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int res = 0;
        int n = startTime.size();
        for(int i = 0; i < n; i++) {
            if(startTime[i] <= queryTime && endTime[i] >= queryTime) {
                res++;
            }
        }
        return res;
    }
};

// diff array
class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int n = startTime.size();
        int maxEnd = *max_element(endTime.begin(), endTime.end());
        if(queryTime > maxEnd) {
            return 0;
        }
        vector<int> diff(maxEnd + 2, 0);
        for(int i = 0; i < n; i++) {
            diff[startTime[i]]++;
            diff[endTime[i] + 1]--;
        }
        int res = 0;
        for(int i = 0; i <= queryTime; i++) {
            res += diff[i];
        }
        return res;
    }
};