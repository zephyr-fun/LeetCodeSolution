// 2023.03.26
// 多源汇最短路
// d[i][j] 存储所有的边
// 1. for(int k = 1; k <= n; k++) {}
//        for(int i = 1; i <= n; i++) {}
//            for(int j = 1; j <= n; j++) {}
//                d[i][j] = min(d[i][j], d[i][k] + d[k][j])
// d[i][j] 最终存储的就是i到j的最短距离
// 注意仍然不能处理负权图
// O(n ^ 3)
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 210;
const int inf = 1e9;

int n;
int m;
int q;
int d[N][N];

void floyd() {
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &q);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) {
                d[i][j] = 0;
            }
            else {
                d[i][j] = inf;
            }
        }
    }
    while(m--) {
        int a;
        int b;
        int w;
        scanf("%d%d%d", &a, &b, &w);
        d[a][b] = min(d[a][b], w);
    }
    floyd();
    while(q--) {
        int a, b;
        scanf("%d%d", &a, &b);
        if(d[a][b] > inf / 2) { // 判断负权边
            puts("impossible");
        }
        else {
            printf("%d\n", d[a][b]);
        }
    }
    return 0;
}