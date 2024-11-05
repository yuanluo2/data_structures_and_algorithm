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

void insert_sort(std::vector<int>& vec) {
    for (int i = 1; i < vec.size(); ++i) {
        int j = i;

        while (j - 1 >= 0 && vec[j] < vec[j - 1]) {
            std::swap(vec[j], vec[j - 1]);
            --j;
        }
    }
}

void shell_sort(std::vector<int>& vec) {
    for (int gap = vec.size() / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < vec.size(); ++i) {
            int j = i;

            while (j - gap >= 0 && vec[j] > vec[j - gap]) {
                std::swap(vec[j], vec[j - gap]);
                j -= gap;
            }
        }
    }
}

int main() {
    std::vector<int> vec = {
        3, 7, 5, 6, 2, 8, 1, 0, 9, 4, 30, 16, 27, 13, 22, 24, 19, 11, 17, 14, 21
    };

    insert_sort(vec);
    print_vec(vec);
    return 0;
}
