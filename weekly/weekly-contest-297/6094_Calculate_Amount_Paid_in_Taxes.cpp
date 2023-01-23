// 2023.01.23
class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double res = 0;
        int lower = 0;
        for(auto& bracket: brackets) {
            int upper = bracket[0];
            int percent = bracket[1];
            int tax = (min(income, upper) - lower) * percent;
            res += tax;
            if(income <= upper) {
                break;
            }
            lower = upper;
        }
        return (double)res / 100.0;
    }
};