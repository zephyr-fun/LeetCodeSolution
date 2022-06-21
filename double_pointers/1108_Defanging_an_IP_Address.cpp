// 2022.06.21
class Solution {
public:
    string defangIPaddr(string address) {
        int n = address.size();
        int right = n + 6 - 1;
        int left = n - 1;
        address.resize(n + 6, ' '); // same resize as vector
        while(left >= 0) {
            if(address[left] == '.') {
                address[right] = ']';
                address[right - 1] = '.';
                address[right - 2] = '[';
                right -= 3;
            }
            else {
                address[right] = address[left];
                right--;
            }
            left--;
        }
        return address;
    }
};