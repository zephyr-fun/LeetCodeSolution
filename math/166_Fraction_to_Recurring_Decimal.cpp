// 2022.12.29
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long long a = numerator;
        long long b = denominator;
        if(a % b == 0) {
            return to_string(a / b);
        }
        string res = "";
        if(a * b < 0) {
            res += '-';
        }
        a = abs(a);
        b = abs(b);
        res += to_string(a / b);
        res += '.';
        a %= b;
        unordered_map<long long, int> map;
        while(a != 0) {
            map[a] = res.size();
            a *= 10;
            res += to_string(a / b);
            a %= b;
            if(map.count(a)) {
                int u = map[a];
                return res.substr(0, u) + '(' + res.substr(u) + ')';
            }
        }
        return res;
    }
};