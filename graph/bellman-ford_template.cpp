// 2023.03.26
// 可以处理负权边，或判断有无负权回路
// 1. for(int i = 0; i < n; i++) {} // 循环 n 次
//        for 所有边 a, b, w -> a 和 b 之间的边权重是 w // 循环所有边
// 随意存边，结构体也行，能遍历就行
//            dist[b] = min(dist[b], dist[a] + w) // 更新过程又称松弛操作
// 循环完 n 次后，一定满足 dist[b] <= dist[a] + w （三角不等式）
// 有负权回路的时候，可能会不存在最短路，如果能求出来的话，证明负权回路不在最短路上
// 加入当前迭代了 k 次，意义是经过不超过 k 条边的最短路的距离
// 那么如果第 n 次迭代仍然更新了距离，就意味着有一个 n 条边的路径，也就对应着 n + 1 个点
// 一共只有 n 个点，就证明其中有两个点编号一样，也就证明有负权回路
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 510;
const int M = 10010;

int n;
int m;
int k;
int dist[N];
int backup[N];

struct Edge {
    int a;
    int b;
    int w;
}edges[M];

int bellman_ford() {
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    for(int i = 0; i < k; i++) {
        memcpy(backup, dist, sizeof(dist)); // 防止串联更新，偷步数
        for(int j = 0; j < m; j++) {
            int a = edges[j].a;
            int b = edges[j].b;
            int w = edges[j].w;
            dist[b] = min(dist[b], backup[a] + w);
        }
    }
    if(dist[n] > 0x3f3f3f3f / 2) { // 两个不可达的点（其中一个是 n ）之间如果存在负权边，最后的值会小于 0x3f3f3f3f
        return -1; // 但是有的数据可能最短路就是 -1 ，这时候可以返回 -0x3f3f3f3f
    }
    return dist[n];
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < m; i++) {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        edges[i] = {a, b, w};
    }
    int t = bellman_ford();
    if(t == -1) {
        puts("impossible");
    }
    else {
        printf("%d\n", t);
    }
    return 0;
}