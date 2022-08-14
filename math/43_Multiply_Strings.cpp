// 2022.08.14
class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.size();
        int m = num2.size();
        vector<int> A;
        vector<int> B;
        vector<int> C(n + m, 0);
        for(int i = n - 1; i >= 0; i--) {
            A.emplace_back(num1[i] - '0');
        }
        for(int i = m - 1; i >= 0; i--) {
            B.emplace_back(num2[i] - '0');
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                C[i + j] += A[i] * B[j];
            }
        }
        for(int i = 0, t = 0; i < C.size(); i++) {
            t += C[i];
            C[i] = t % 10;
            t = t / 10;
        }
        int k = C.size() - 1;
        while(k > 0 && C[k] == 0) {
            k--;
        }
        string res = "";
        while(k >= 0) {
            res += C[k] + '0';
            k--;
        }
        return res;
    }
};