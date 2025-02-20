#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// 定义图的邻接表表示
typedef pair<int, int> iPair;  // (顶点, 权重)

void dijkstra(const vector<vector<iPair>>& graph, int src) {
    int V = graph.size();
    vector<int> dist(V, INT_MAX);
    vector<int> parent(V, -1);  // 用于记录最短路径
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;

    // 初始化源点
    dist[src] = 0;
    pq.push(make_pair(0, src));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        // 遍历所有邻接顶点
        for (const auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            // 松弛操作
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
                parent[v] = u;  // 记录路径
            }
        }
    }

    // 输出结果
    cout << "从顶点" << src << "到其他顶点的最短路径：" << endl;
    for (int i = 0; i < V; ++i) {
        cout << "到顶点" << i << "：";
        if (dist[i] == INT_MAX) {
            cout << "无法到达" << endl;
        } else {
            cout << "距离=" << dist[i] << ", 路径=";
            // 打印路径
            vector<int> path;
            for (int curr = i; curr != -1; curr = parent[curr]) {
                path.push_back(curr);
            }
            for (int j = path.size() - 1; j >= 0; j--) {
                cout << path[j];
                if (j > 0) cout << "->";
            }
            cout << endl;
        }
    }
}

int main() {
    // 示例图
    int V = 9;
    vector<vector<iPair>> graph(V);

    // 添加双向边
    // 添加一条边时同时添加其反向边
    auto addEdge = [&graph](int u, int v, int w) {
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    };

    // 添加边
    addEdge(0, 1, 4);
    addEdge(0, 7, 8);
    addEdge(1, 2, 8);
    addEdge(1, 7, 11);
    addEdge(2, 3, 7);
    addEdge(2, 8, 2);
    addEdge(2, 5, 4);
    addEdge(3, 4, 9);
    addEdge(3, 5, 14);
    addEdge(4, 5, 10);
    addEdge(5, 6, 2);
    addEdge(6, 7, 1);
    addEdge(6, 8, 6);
    addEdge(7, 8, 7);

    // 从顶点0开始计算最短路径
    dijkstra(graph, 0);

    return 0;
}