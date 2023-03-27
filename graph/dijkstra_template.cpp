// 2023.03.26
// 单源最短路问题(从1号点到其他任意点的最短路径长度)
// plain dijkstra
// 1. dist[start_point] = 0, dist[i] = +inf
// 2. for i in 1 -> n, si 当前以确定的最短距离的点
//        t <- 不在s中的距离最近的点(贪心)
//        s <- t, 将t加入s
//        用t更新其他的点x的距离, if (dist[x] > dist[t] + w), w为从t到x的距离权重
//        每次确定一个点的最短距离，这样循环n次就知道所有点的最短距离了
// 时间复杂度O(n ^ 2)
// 稠密图用邻接矩阵，稀疏图用邻接表，不区分有向图和无向图（特殊的有向图）
// template
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510;

int n;
int m;
int g[N][N];
int dist[N];
bool st[N];

int dijkstra() {
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    for(int i = 0; i < n; i++) {
        int t = -1;
        for(int j = 1; j <= n; j++) {
            if(!st[j] && (t == -1 || dist[t] > dist[j])) {
                t = j;
            }
        }
        st[t] = true;
        for(int j = 1; j <= n; j++) {
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        }
    }
    if(dist[n] == 0x3f3f3f3f) {
        return -1;
    }
    return dist[n];
}

int main() {
    // 考虑可能存在重边和自环
    // 重边保留最短边，如果路径权重都是正的，自环不影响
    scanf("%d%d", &n, &m);
    memset(g, 0x3f, sizeof(g));
    while(m--) {
        int a;
        int b;
        int c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = min(g[a][b], c);
    }
    int t = dijkstra();
    printf("%d\n", t);
    return 0;
}

// optim with priority_queue，利用冗余来存储
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

// 距离，节点编号
typedef pair<int, int> PII;

const int N = 1e6 + 10;

int n;
int m;
// int g[N][N];
// 改为链式前向星存图
int h[N], w[N], e[N], ne[N], idx;
int dist[N];
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

int dijkstra() {
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> pque;
    pque.push({0, 1});
    while(!pque.empty()) {
        auto t = pque.top();
        pque.pop();
        int ver = t.second;
        int distance = t.first;
        if(st[ver]) {
            continue;
        }
        st[ver] = true;
        for(int i = h[ver]; i != -1; i = ne[i]) {
            int j = e[i];
            if(dist[j] > dist[ver] + w[i]) {
                dist[j] = dist[ver] + w[i];
                pque.push({dist[j], j});
            }
        }
    }
    if(dist[n] == 0x3f3f3f3f) {
        return -1;
    }
    return dist[n];
}

int main() {
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof(h)); // 链式前向星初始化表头
    while(m--) {
        int a;
        int b;
        int c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }
    int t = dijkstra();
    printf("%d\n", t);
    return 0;
}