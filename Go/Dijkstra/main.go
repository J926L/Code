package main

import (
	"fmt"
	"math"
)

// Graph 表示使用邻接表的加权图
type Graph struct {
	vertices int
	adjList  [][]Edge
}

// Edge 表示加权边
type Edge struct {
	to     int
	weight int
}

// NewGraph creates a new graph with v vertices
func NewGraph(v int) *Graph {
	return &Graph{
		vertices: v,
		adjList:  make([][]Edge, v),
	}
}

// AddEdge adds a directed edge from u to v with weight w
func (g *Graph) AddEdge(u, v, w int) {
	g.adjList[u] = append(g.adjList[u], Edge{v, w})
}

// Dijkstra finds shortest paths from source to all other vertices
func (g *Graph) Dijkstra(source int) ([]int, []int) {
	dist := make([]int, g.vertices)
	prev := make([]int, g.vertices)
	
	for i := range dist {
		dist[i] = math.MaxInt32
		prev[i] = -1
	}
	dist[source] = 0

	// Priority queue (min-heap) would be better but using slice for simplicity
	visited := make([]bool, g.vertices)
	
	for i := 0; i < g.vertices; i++ {
		// Find vertex with minimum distance
		u := -1
		for v := 0; v < g.vertices; v++ {
			if !visited[v] && (u == -1 || dist[v] < dist[u]) {
				u = v
			}
		}
		
		if dist[u] == math.MaxInt32 {
			break
		}
		
		visited[u] = true
		
		// Update distances of adjacent vertices
		for _, edge := range g.adjList[u] {
			if alt := dist[u] + edge.weight; alt < dist[edge.to] {
				dist[edge.to] = alt
				prev[edge.to] = u
			}
		}
	}
	
	return dist, prev
}

func main() {
	// Create a graph with 6 vertices
	g := NewGraph(6)
	
	// Add edges
	g.AddEdge(0, 1, 2)
	g.AddEdge(0, 2, 4)
	g.AddEdge(1, 2, 1)
	g.AddEdge(1, 3, 7)
	g.AddEdge(2, 4, 3)
	g.AddEdge(3, 5, 1)
	g.AddEdge(4, 3, 2)
	g.AddEdge(4, 5, 5)
	
	// Run Dijkstra's algorithm from vertex 0
	dist, prev := g.Dijkstra(0)
	
	// 打印结果
	fmt.Println("顶点\t距离\t\t路径")
	for i := 0; i < g.vertices; i++ {
		fmt.Printf("%d\t%d\t\t", i, dist[i])
		path := []int{}
		for at := i; at != -1; at = prev[at] {
			path = append([]int{at}, path...)
		}
		fmt.Println(path)
	}
}
