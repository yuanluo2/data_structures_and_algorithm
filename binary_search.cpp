#include <iostream>
#include <vector>

int binary_search(std::vector<int>& vec, int key) {
    int low = 0;
    int high = vec.size() - 1;
    int mid = 0;

    while (low <= high) {
        mid = low + (high - low) / 2;

        if (key > vec[mid]) {
            low = mid + 1;
        }
        else if (key < vec[mid]) {
            high = mid - 1;
        }
        else {
            return mid;
        }
    }

    return -1;
}

int main() {
    std::vector<int> vec = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    };

    std::cout << "find at " << binary_search(vec, 11) << "\n";
    return 0;
}
