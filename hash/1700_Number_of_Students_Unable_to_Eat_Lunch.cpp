// 2022.10.19
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        int zero = 0;
        int one = 0;
        for(auto& student : students) {
            if(student == 0) {
                zero++;
            }
            else {
                one++;
            }
        }
        int res = 0;
        for(auto& sandwich : sandwiches) {
            if(sandwich == 0) {
                if(zero > 0) {
                    zero--;
                    res++;
                }
                else {
                    break;
                }
            }
            else {
                if(one > 0) {
                    one--;
                    res++;
                }
                else {
                    break;
                }
            }
        }
        return n - res;
    }
};