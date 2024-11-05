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

void swap_two(int& left, int& right) {
    int temp = left;
    left = right;
    right = temp;
}

void bubble_sort(std::vector<int>& vec) {
    size_t length = vec.size();

    for (size_t i = 1; i < length - 1; ++i) {
        for (size_t j = 0; j < length - i; ++j) {   // j: 0 .. length - 2
            if (vec[j] > vec[j + 1]) {
                swap_two(vec[j], vec[j + 1]);
            }
        }
    }
}

void bubble_sort_improve(std::vector<int>& vec) {
    size_t length = vec.size();

    for (size_t i = 1; i < length; ++i) {
        bool hasSwaped = false;

        for (size_t j = 0; j < length - i; ++j) {
            if (vec[j] > vec[j + 1]) {
                swap_two(vec[j], vec[j + 1]);
                hasSwaped = true;
            }
        }

        if (!hasSwaped) {
            return;
        }
    }
}

int main() {
    std::vector<int> vec = {
        3, 7, 5, 6, 2, 8, 1, 0, 9, 4
    };

    bubble_sort_improve(vec);
    print_vec(vec);
    return 0;
}
