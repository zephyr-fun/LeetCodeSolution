#include<iostream>
#include<vector>

using namespace std;

void quick_sort(vector<int>& nums, int l, int r) {
    if(l >= r) {
        return ;
    }
    int i = l;
    int j = r;
    int x = nums[(l + r) >> 1];
    while(i < j) {
        while(nums[i] < x) {
            i++;
        }
        while(nums[j] > x) {
            j--;
        }
        if(i < j) {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
    if(i == j && nums[j] > x) {
        j--;
    }
    quick_sort(nums, l, j);
    quick_sort(nums, j + 1, r);
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    quick_sort(nums, 0, n - 1);
    cout << nums[0];
    for(int i = 1; i < n; i++) {
        cout << " " << nums[i];
    }
    return 0;
}