#include <iostream>
#include <array>

template<int N>
class UnionFindSet {
    std::array<int, N> parent;
public:
    UnionFindSet() {
        for (int i = 0; i < N; ++i) {
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

int main() {
    UnionFindSet<5> ufs;

    ufs.union_set(0, 1);
    ufs.union_set(2, 3);

    std::cout << ufs.connected(0, 1) << "\n";
    std::cout << ufs.connected(3, 2) << "\n";
    std::cout << ufs.connected(0, 2) << "\n";

    std::cout << ufs.connected(1, 4) << "\n";
    std::cout << ufs.connected(2, 4) << "\n";
    std::cout << ufs.connected(3, 4) << "\n";
    std::cout << ufs.connected(0, 4) << "\n";
    ufs.union_set(0, 2);
    std::cout << ufs.connected(0, 2) << "\n";
}