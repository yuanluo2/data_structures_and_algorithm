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

int partion_sort(std::vector<int>& vec, int left, int right) {
    std::swap(vec[left], vec[left + (right - left) / 2]);
    int key = left;

    while (left < right) {
        // from the right, find the 1st element which is smaller than vec[key].
        while (left < right && vec[right] >= vec[key]) {
            right -= 1;
        }

        // from the left, find the 1st element which is bigger than vec[key].
        while (left < right && vec[left] <= vec[key]) {
            left += 1;
        }
        
        std::swap(vec[left], vec[right]);
    }

    std::swap(vec[left], vec[key]);
    return left;
}

void quick_sort(std::vector<int>& vec, int left, int right) {
    if (left >= right) {
        return;
    }

    int key = partion_sort(vec, left, right);
    quick_sort(vec, left, key - 1);
    quick_sort(vec, key + 1, right);
}

void quick_sort(std::vector<int>& vec) {
    quick_sort(vec, 0, vec.size() - 1);
}

int main() {
    std::vector<int> vec = {
        3, 7, 5, 6, 2, 8, 1, 0, 9, 4, 30, 16, 27, 13, 22, 24, 19, 11, 17, 14, 21
    };

    quick_sort(vec);
    print_vec(vec);
    return 0;
}
