#include <iostream>
#include <queue>

template<size_t N>
class Graph {
    bool data[N][N];
    bool directed;
    int edgeNum;

    void dfs(bool* visited, int v) {
        std::cout << v << " ";
        visited[v] = true;

        for (size_t i = 0; i < N; ++i) {
            if (data[v][i] && !visited[i]) {
                dfs(visited, i);
            }
        }
    }
public:
    Graph(bool _directed) : directed{ _directed }, edgeNum{ 0 } {
        for (size_t i = 0; i < N; ++i) {
            for (size_t j = 0; j < N; ++j) {
                data[i][j] = false;
            }
        }
    }

    ~Graph() noexcept {
        directed =false;
        edgeNum = 0;
    }

    int edges() const noexcept {
        return edgeNum;
    }

    void add_edge(int v, int w) {
        edgeNum += 1;
        data[v][w] = true;

        if (!directed) {
            data[w][v] = true;
        }
    }

    void remove_edge(int v, int w) {
        edgeNum -= 1;
        data[v][w] = false;

        if (!directed) {
            data[w][v] = false;
        }
    }

    void bfs(int v) {
        std::cout << "bfs:\n";

        bool visited[N];
        for (size_t i = 0; i < N; ++i) {
            visited[i] = false;
        }

        std::queue<int> q;
        visited[v] = true;
        q.push(v);

        while (!q.empty()) {
            int head = q.front();
            std::cout << head << " ";
            q.pop();

            for (size_t i = 0; i < N; ++i) {
                if (data[head][i] && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }

        std::cout << "\n";
    }

    void dfs(int v) {
        std::cout << "dfs:\n";

        bool visited[N];
        for (size_t i = 0; i < N; ++i) {
            visited[i] = false;
        }

        dfs(visited, v);
        std::cout << "\n";
    }
};

/*
    0   3
    |  / \
    | /   \
    1 - 2 - 4 - 5
*/
int main() {
    Graph<6> graph{ false };

    graph.add_edge(0, 1);
    graph.add_edge(1, 2);
    graph.add_edge(1, 3);
    graph.add_edge(2, 4);
    graph.add_edge(3, 4);
    graph.add_edge(4, 5);

    std::cout << "edges: " << graph.edges() << "\n";

    graph.dfs(0);
    graph.dfs(1);
    graph.dfs(2);
    graph.dfs(3);
    graph.dfs(4);
    graph.dfs(5);
    return 0;
}
