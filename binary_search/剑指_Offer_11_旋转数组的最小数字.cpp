// 2022.08.11
// construct binary
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int n = numbers.size();
        int left = 0;
        int right = n - 1;
        int pos = -1;
        while(right >= 0 && numbers[0] == numbers[right]) {
            right--;
        }
        while(left <= right) {
            int mid = (left + right) >> 1;
            if(numbers[mid] >= numbers[0]) {
                pos = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return numbers[(pos + 1) % n];
    }
};

// 2022.08.27
// 100% good challenge
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int n = numbers.size();
        int left = 0;
        int right = n - 1;
        int pos = -1;
        while(right >= 0 && numbers[0] == numbers[right]) {
            right--;
        }
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(numbers[mid] >= numbers[0]) {
                pos = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return numbers[(pos + 1) % n];
    }
};