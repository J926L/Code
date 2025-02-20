# Dijkstra算法实现 - 寻找图中最短路径
import sys

class Graph:
    def __init__(self, vertices):
        self.V = vertices  # 顶点数量
        self.graph = [[0 for column in range(vertices)] 
                      for row in range(vertices)]  # 邻接矩阵

    # 打印最短路径
    def print_solution(self, dist):
        print("顶点 \t 到源点的最短距离")
        for node in range(self.V):
            print(node, "\t", dist[node])

    # 找到距离最小的顶点
    def min_distance(self, dist, spt_set):
        min_val = sys.maxsize  # 初始化最小值为最大整数
        min_index = -1  # 初始化最小索引
        
        # 遍历所有顶点
        for v in range(self.V):
            if dist[v] < min_val and spt_set[v] == False:
                min_val = dist[v]
                min_index = v

        if min_index == -1:
            raise ValueError("未找到最小距离顶点")
        return min_index

    def dijkstra(self, src):
        dist = [sys.maxsize] * self.V  # 初始化距离为无穷大
        dist[src] = 0  # 源点到自身的距离为0
        spt_set = [False] * self.V  # 最短路径树集合

        for count in range(self.V):
            # 选择距离最小的顶点
            u = self.min_distance(dist, spt_set)
            
            # 将选中的顶点加入最短路径树
            spt_set[u] = True

            # 更新相邻顶点的距离
            for v in range(self.V):
                if (self.graph[u][v] > 0 and 
                   spt_set[v] == False and
                   dist[v] > dist[u] + self.graph[u][v]):
                    dist[v] = dist[u] + self.graph[u][v]

        self.print_solution(dist)

# 测试代码
if __name__ == "__main__":
    g = Graph(9)
    g.graph = [[0, 4, 0, 0, 0, 0, 0, 8, 0],
               [4, 0, 8, 0, 0, 0, 0, 11, 0],
               [0, 8, 0, 7, 0, 4, 0, 0, 2],
               [0, 0, 7, 0, 9, 14, 0, 0, 0],
               [0, 0, 0, 9, 0, 10, 0, 0, 0],
               [0, 0, 4, 14, 10, 0, 2, 0, 0],
               [0, 0, 0, 0, 0, 2, 0, 1, 6],
               [8, 11, 0, 0, 0, 0, 1, 0, 7],
               [0, 0, 2, 0, 0, 0, 6, 7, 0]]

    g.dijkstra(0)
