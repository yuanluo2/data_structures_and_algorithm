#include <iostream>
#include <algorithm>
#include <vector>

struct Edge {
    int src;
    int dst;
    int weight;

    Edge(int _src, int _dst, int _weight) : src{ _src }, dst{ _dst }, weight{ _weight } {}
};

struct Graph {
    int verticeNum;
    int edgeNum;
    std::vector<Edge> edges;

    Graph(int _verticeNum, int _edgeNum) : verticeNum{ _verticeNum }, edgeNum{ _edgeNum } {}
};

class UnionFindSet {
    std::vector<int> parent;
public:
    UnionFindSet(int verticeNum) {
        parent.resize(verticeNum);

        for (int i = 0; i < verticeNum; ++i) {
            parent[i] = -1;
        }
    }

    int find_root(int x) {
        while (parent[x] != -1) {
            x = parent[x];
        }

        return x;
    }

    void union_set(int x, int y) {
        int rootX = find_root(x);
        int rootY = find_root(y);

        if (rootX != rootY) {
            parent[rootY] = rootX;
        }
    }

    bool connected(int x, int y) {
        return find_root(x) == find_root(y);
    }
};

void sort_edges(std::vector<Edge>& edges) {
    std::sort(edges.begin(), edges.end(), [](const Edge& left, const Edge& right){
        return left.weight < right.weight;
    });
}

void kruskal(Graph& graph) {
    std::vector<Edge> minSpanningTree;
    sort_edges(graph.edges);

    UnionFindSet ufs{ graph.verticeNum };

    int e = 0;
    int i = 0;

    // minimum spanning tree only need (graph.verticeNum - 1) edges.
    while (e < graph.verticeNum - 1 && i < graph.edgeNum) {
        const Edge& edge = graph.edges[i];

        // if A, B both connect to some node called C, then if A, B connect, A, B, C must be a circle.
        // so ufs is used here, ufs can find that node called C.
        int rootSrc = ufs.find_root(edge.src);
        int rootDst = ufs.find_root(edge.dst);

        if (rootSrc != rootDst) {   // not connected.
            minSpanningTree.emplace_back(edge);
            ufs.union_set(edge.src, edge.dst);
            ++e;
        }

        ++i;
    }

    for (const auto& edge : minSpanningTree) {
        std::cout << edge.src << " -- " << edge.dst << " " << edge.weight << "\n";
    }
    
    std::cout << "\n";
}

int main() {
    Graph graph{ 4, 5 };

    graph.edges.emplace_back(0, 1, 10);
    graph.edges.emplace_back(0, 2, 6);
    graph.edges.emplace_back(0, 3, 5);
    graph.edges.emplace_back(1, 3, 15);
    graph.edges.emplace_back(2, 3, 4);

    kruskal(graph);
}