#include <iostream>
#include <vector>
#include <queue>

int main() {
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    vector<int> in(n, 0);
    vector<vector<int>> g(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j]) {
                g[i].emplace_back(j);
                in[j]++;
            }
        }
    }
    queue<int> que;
    for(int i = 0; i < n; i++) {
        if(in[i] == 0) {
            que.push(i);
        }
    }
    vector<int> res;
    while(!que.empty()) {
        int cur = que.front();
        que.pop();
        res.emplace_back(cur);
        for(int i = 0; i < g[cur].size(); i++) {
            in[g[cur][i]]--;
            if(in[g[cur][i]] == 0) {
                que.push(g[cur][i]);
            }
        }
    }
    return res;
}


void treeinsert(TreeNode* root, int val) {
    TreeNode* pre = nullptr;
    TreeNode* cur = root;
    while(cur != nullptr) {
        if(cur->val > val) {
            pre = cur;
            cur = cur->left;
        }
        else if(cur->val < val) {
            pre = cur;
            cur = cur->left;
        }
    }
    TreeNode* temp = new TreeNode(val);
    if(pre->val > val) {
        pre->left = temp;
    }
    else {
        pre->rihgt = temp;
    }
}