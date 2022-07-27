// 2022.07.27
class Solution {
public:
    string fractionAddition(string expression) {
        int n = expression.size();
        string res = "";
        int i = 0;
        while(i < n) {
            int j = i + 1;
            while(j < n && expression[j] != '+' && expression[j] != '-') {
                j++;
            }
            string num = expression.substr(i, j - i + 1);
            if(expression[i] != '+' && expression[i] != '-') {
                num = "+" + num;
            }
            if(res != "") {
                res = calc(num, res);
            }
            else {
                res = num;
            }
            i = j;
        }
        return res[0] == '+' ? res.substr(1) : res;
    }

    string calc(string a, string b) {
        bool fa = a[0] == '+';
        bool fb = b[0] == '+';
        if(!fa && fb) {
            return calc(b, a);
        }
        vector<long long> p = parse(a);
        vector<long long> q = parse(b);
        long long p1 = p[0] * q[1];
        long long q1 = q[0] * p[1];
        if(fa && fb) {
            long long r1 = p1 + q1;
            long long r2 = p[1] * q[1];
            long long c = gcd(r1, r2);
            return "+" + to_string(r1 / c) + "/" + to_string(r2 / c);
        }
        else if(!fa && !fb) {
            long long r1 = p1 + q1;
            long long r2 = p[1] * q[1];
            long long c = gcd(r1, r2);
            return "-" + to_string(r1 / c) + "/" + to_string(r2 / c);
        }
        else {
            long long r1 = p1 - q1;
            long long r2 = p[1] * q[1];
            long long c = gcd(abs(r1), r2);
            string res = to_string(r1 / c) + "/" + to_string(r2 / c);
            if(p1 >= q1) {
                res = "+" + res;
            }
            return res;
        }
    }
    vector<long long> parse(string s) {
        int n = s.size();
        int idx = 1;
        while(idx < n && s[idx] != '/') {
            idx++;
        }
        long long a = stoll(s.substr(1, idx));
        long long b = stoll(s.substr(idx + 1));
        return vector<long long>(initializer_list<long long>{a, b});
    }
    long long gcd(long long a, long long b) {
        return b ? gcd(b, a % b) : a;
    }
};