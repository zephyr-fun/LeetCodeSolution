// 2022.07.07
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int n = 1e5 + 7;
vector<vector<int>> son(n, vector<int>(26, 0));
int idx = 0;
vector<int> cnt(n, 0);

void insert(string& s) {
    int p = 0;
    for(int i = 0; i < s.size(); i++) {
        int u = s[i] - 'a';
        if(!son[p][u]) {
            son[p][u] = ++idx;
        }
        p = son[p][u];
    }
    cnt[p]++;
}

int query(string& s) {
    int p = 0;
    for(int i = 0; i < s.size(); i++) {
        int u = s[i] - 'a';
        if(!son[p][u]) {
            return 0;
        }
        p = son[p][u];
    }
    return cnt[p];
}

int main() {
    int num;
    cin >> num;
    for(int i = 0; i < num; i++) {
        string opt;
        cin >> opt;
        string temp;
        cin >> temp;
        if(opt == "I") {
            insert(temp);
        }
        else {
            cout << query(temp) << endl;
        }
    }
    return 0;
}