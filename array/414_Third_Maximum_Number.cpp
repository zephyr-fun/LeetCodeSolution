// 2022.07.12
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int* a = nullptr;
        int* b = nullptr;
        int* c = nullptr;
        for(int& num : nums) {
            if(a == nullptr || num > *a) {
                c = b;
                b = a;
                a = &num;
            }
            else if(*a > num && (b == nullptr || num > *b)) {
                c = b;
                b = &num;
            }
            else if(b != nullptr && num < *b && (c == nullptr || num > *c)) {
                c = &num;
            }
        }
        return c == nullptr ? *a : *c;
    }
};