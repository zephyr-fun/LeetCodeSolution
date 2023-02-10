// 2023.02.10
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int res = 0;
        int n = answers.size();
        sort(answers.begin(), answers.end());
        int i = 0;
        while(i < n && answers[i] == 0) {
            res++;
            i++;
        }
        while(i < n) {
            int j = i;
            int cnt = 0;
            while(j < n && answers[i] == answers[j]) {
                cnt++;
                j++;
            }
            res += answers[i] + 1 + (cnt - 1) / (answers[i] + 1) * (answers[i] + 1);
            i = j;
        }
        return res;
    }
};