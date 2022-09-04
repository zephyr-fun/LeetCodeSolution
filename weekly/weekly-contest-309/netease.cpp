#include <iostream>
#include <vector>

using namespace std

int main() {
    int n;
    int k;
    cin >> n >> k;
    vector<int> cnt(k, 0);
    int res = 0;
    for(int i = 0; i < n; i++) {
        int temp = 0;
        cin >> temp;
        cnt[temp % k]++;
        res = max(res, cnt[temp % k]);
    }
    return res;
}


#include <iostream>
#include <vector>
#inlcude <set>

using namespace std

int main() {
    int n;
    int k;
    int x;
    cin >> n >> k >> x;
    set<int, less<int>> set;
    for(int i = 0; i < n; i++) {
        int temp = 0;
        cin >> temp;
        set.insert(temp);
    }
    for(int i = 0; i < k; i++) {
        int temp = *set.begin();
        set.erase(temp);
        temp -= x;
        set.insert(temp);
    }
    return *set.begin();
}

#include <iostream>
#include <vector>
#inlcude <math.h>

using namespace std

int main() {
    int mod = 1e9 + 7;
    int n;
    cin >> n;
    vector<int> weight(n);
    for(int i = 0; i < n; i++) {
        cin >> weight[i];
    }
    vector<int> left(n);
    vector<int> right(n);
    left[0] = 1;
    right[n - 1] = 1;
    for(int i = 1; i < n; i++) {
        left[i] = (left[i - 1] * weight[i - 1]) % mod;
    }
    for(int i = n - 2; i >= 0; i--) {
        right[i] = (right[i + 1] * weight[i + 1]) % mod;
    }
    int res = 0;
    for(int i = 0; i < n; i++) {
        int mul = (left[i] * right[i]) % mod;
        int temp = 0;
        for(int i = 1; i < sqrt(mul); i++) {
            if((mul % i) == 0) {
                temp++;
            }
        }
        if(sqrt(mul) * sqrt(mul) == mul) {
            temp++;
        }
        res += temp;
    }
}