// 2022.05.24
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        int left = 0;
        int right = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] - temp[i] != 0) {
                left = i;
                break;
            }
        }
        for(int i = nums.size() - 1; i >= 0; i--) {
            if(nums[i] - temp[i] != 0) {
                right = i;
                break;
            }
        }
        return right == left ? 0 : right - left + 1;
    }
};

// optim O(n)
class Solution {
public:
    int MIN = -0x3f3f3f3f;
    int MAX = 0x3f3f3f3f;
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = n - 1;
        while(i < j && nums[i] <= nums[i + 1]) {
            i++;
        }
        while(i < j && nums[j] >= nums[j - 1]) {
            j--;
        }
        int left = i;
        int right = j;
        int min = nums[i];
        int max = nums[j];
        for(int u = left; u <= right; u++) {
            if(nums[u] < min) {
                while(i >= 0 && nums[i] > nums[u]) {
                    i--;
                }
                min = i >= 0 ? nums[i] : MIN;
            }
            if(nums[u] > max) {
                while(j < n && nums[j] < nums[u]) {
                    j++;
                }
                max = j < n ? nums[j] : MAX;
            }
        }
        return i == j ? 0 : (j - 1) - (i + 1) + 1;
    }
};

// 2022.10.04
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int MIN = -0x3f3f3f3f;
        int MAX = 0x3f3f3f3f;
        int n = nums.size();
        int i = 0;
        int j = n - 1;
        while(i < j && nums[i] <= nums[i + 1]) {
            i++;
        }
        while(i < j && nums[j] >= nums[j - 1]) {
            j--;
        }
        int l = i;
        int r = j;
        int minVal = nums[i];
        int maxVal = nums[j];
        for(int u = l; u <= r; u++) {
            while(nums[u] < minVal && i >= 0) {
                i--;
                minVal = i == -1 ? MIN : nums[i];
            }
            while(nums[u] > maxVal && j < n) {
                j++;
                maxVal = j == n ? MAX : nums[j];
            }
        }
        return j == i ? 0 : (j - 1) - (i + 1) + 1;
    }
};