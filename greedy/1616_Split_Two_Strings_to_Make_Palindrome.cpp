// 2023.03.18
// 贪心的策略在于尽可能的让 a (或 b)的前缀去匹配 b (或 a)的后缀而不会使结果更坏
class Solution {
public:
    bool is_palindrome(string& s, int i, int j) {
        while(i <= j) {
            if(s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    bool check(string& a, string& b) {
        int n = a.size();
        int i = 0;
        int j = n - 1;
        while(i <= j && a[i] == b[j]) {
            i++;
            j--;
        }
        return is_palindrome(a, i, j) || is_palindrome(b, i, j);
    }
    bool checkPalindromeFormation(string a, string b) {
        return check(a, b) || check(b, a);
    }
};