#include <iostream>
#include <vector>

void print_vec(const std::vector<int>& vec) {
    std::cout << "[";

    for (size_t i = 0; i < vec.size(); ++i) {
        if (i == vec.size() - 1) {
            std::cout << vec[i];
        }
        else {
            std::cout << vec[i] << ", ";
        }
    }

    std::cout << "]\n";
}

void shift_up(std::vector<int>& vec, int i) {
    int parent = (i - 1) / 2;

    if (parent >= 0 && vec[i] > vec[parent]) {
        std::swap(vec[i], vec[parent]);
        shift_up(vec, parent);
    }
}

void heapify(std::vector<int>& vec, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && vec[largest] < vec[left]) {
        largest = left;
    }

    if (right < n && vec[largest] < vec[right]) {
        largest = right;
    }

    if (largest != i) {
        std::swap(vec[largest], vec[i]);
        heapify(vec, n, largest);   // shift down.
    }
}

void build_heap(std::vector<int>& vec) {
    // from the last node which is not leaf.
    for (int i = vec.size() / 2 - 1; i >= 0; --i) {
        heapify(vec, vec.size(), i);
    }
}

void heap_sort(std::vector<int>& vec) {
    for (int i = vec.size() - 1; i > 0; --i) {
        std::swap(vec[0], vec[i]);
        heapify(vec, i, 0);
    }
}

int main() {
    std::vector<int> vec = {
        3, 7, 5, 6, 2, 8, 1, 0, 9, 4, 30, 16, 27, 13, 22, 24, 19, 11, 17, 14, 21
    };

    print_vec(vec);
    build_heap(vec);
    print_vec(vec);
    heap_sort(vec);
    print_vec(vec);

    std::cout << "================================================\n";
    std::vector<int> vec2;
    vec2.push_back(3);
    shift_up(vec2, vec2.size() - 1);
    vec2.push_back(7);
    shift_up(vec2, vec2.size() - 1);
    vec2.push_back(5);
    shift_up(vec2, vec2.size() - 1);
    vec2.push_back(6);
    shift_up(vec2, vec2.size() - 1);
    vec2.push_back(2);
    shift_up(vec2, vec2.size() - 1);
    vec2.push_back(8);
    shift_up(vec2, vec2.size() - 1);
    vec2.push_back(1);
    shift_up(vec2, vec2.size() - 1);
    vec2.push_back(0);
    shift_up(vec2, vec2.size() - 1);
    vec2.push_back(9);
    shift_up(vec2, vec2.size() - 1);
    vec2.push_back(4);
    shift_up(vec2, vec2.size() - 1);
    vec2.push_back(30);
    shift_up(vec2, vec2.size() - 1);
    vec2.push_back(16);
    shift_up(vec2, vec2.size() - 1);
    vec2.push_back(27);
    shift_up(vec2, vec2.size() - 1);
    vec2.push_back(13);
    shift_up(vec2, vec2.size() - 1);
    vec2.push_back(22);
    shift_up(vec2, vec2.size() - 1);
    vec2.push_back(24);
    shift_up(vec2, vec2.size() - 1);
    vec2.push_back(19);
    shift_up(vec2, vec2.size() - 1);
    vec2.push_back(11);
    shift_up(vec2, vec2.size() - 1);
    vec2.push_back(17);
    shift_up(vec2, vec2.size() - 1);
    vec2.push_back(14);
    shift_up(vec2, vec2.size() - 1);
    vec2.push_back(21);
    shift_up(vec2, vec2.size() - 1);

    print_vec(vec2);
    heap_sort(vec2);
    print_vec(vec2);
    return 0;
}
