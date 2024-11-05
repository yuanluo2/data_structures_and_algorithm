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

void selection_sort(std::vector<int>& vec) {
    for (int i = 0; i < vec.size(); ++i) {
        int max = i;
        for (int j = i + 1; j < vec.size(); ++j) {
            if (vec[j] > vec[max]) {
                max = j;
            }
        }

        if (i != max) {
            std::swap(vec[i], vec[max]);
        }
    }
}

int main() {
    std::vector<int> vec = {
        3, 7, 5, 6, 2, 8, 1, 0, 9, 4, 30, 16, 27, 13, 22, 24, 19, 11, 17, 14, 21
    };

    selection_sort(vec);
    print_vec(vec);
    return 0;
}
