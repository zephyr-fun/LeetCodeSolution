// 2022.12.31
class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        int res = 0;
        int n = seats.size();
        for(int i = 0; i < n; i++) {
            res += abs(seats[i] - students[i]);
        }
        return res;
    }
};