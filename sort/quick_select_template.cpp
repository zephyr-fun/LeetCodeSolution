// 2022.07.09
#include <iostream>
#include <vector>

using namespace std;

int quick_select(vector<int>& nums, int l, int r, int k) {
    if(l == r) {
        return nums[l];
    }
    int x = nums[(l + r) >> 1];
    int i = l - 1;
    int j = r + 1;
    while(i < j) {
        while(nums[++i] < x);
        while(nums[--j] > x);
        if(i < j) {
            swap(nums[i], nums[j]);
        }
    }
    int sl = j - l + 1;
    if(k <= sl) {
        return quick_select(nums, l, j, k);
    }
    return quick_select(nums, j + 1, r, k - sl);
}

int main() {
    int n;
    int k;
    cin >> n >> k;
    vector<int> nums(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << quick_select(nums, 0, n - 1, k);
    return 0;
}