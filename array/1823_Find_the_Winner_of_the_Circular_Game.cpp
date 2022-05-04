// 2022.05.04
class Solution {
public:
    int findTheWinner(int n, int k) {
        int count = n;
        vector<bool> remain(n + 1, true);
        int index = 0;
        while(count > 1) {
            for(int j = 0; j < k - 1; j++) {
                index++;
                while(!remain[index % n]) {
                    index++;
                }
            }
            remain[index % n] = false;
            count -= 1;
            index++;
            while(!remain[index % n]) {
                index++;
            }
        }
        return index % n + 1;
    }
};

// recursion
class Solution {
public:
    int findTheWinner(int n, int k) {
        if(n == 1) {
            return n; // return n
        }
        int ans = (findTheWinner(n - 1, k) + k) % n;
        return ans == 0 ? n : ans;
    }
};