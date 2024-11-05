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

void merge(std::vector<int>& vec, int left, int mid, int right, std::vector<int>& temp) {
    int i = left;
    int j = mid + 1;
    int k = 0;

    // compare 2 sequences.
    while (i <= mid && j <= right) {
        if (vec[i] <= vec[j]) {
            temp[k] = vec[i];

            k += 1;            
            i += 1;
        }
        else {
            temp[k] = vec[j];

            k += 1;
            j += 1;
        }
    }

    // one sequence in i -> mid or j -> right must be finished, so append the extra.
    while (i <= mid) {
        temp[k] = vec[i];

        k += 1;
        i += 1;
    }

    while (j <= right) {
        temp[k] = vec[j];

        k += 1;
        j += 1;
    }

    // copy back to the vec.
    k = 0;
    while (left <= right) {
        vec[left] = temp[k];

        left += 1;
        k += 1;
    }
}

void merge_sort(std::vector<int>& vec, int left, int right, std::vector<int>& temp) {
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;
    merge_sort(vec, left, mid, temp);
    merge_sort(vec, mid + 1, right, temp);
    merge(vec, left, mid, right, temp);
}

void merge_sort(std::vector<int>& vec) {
    std::vector<int> temp;
    temp.resize(vec.size());
    merge_sort(vec, 0, vec.size() - 1, temp);
}

int main() {
    std::vector<int> vec = {
        3, 7, 5, 6, 2, 8, 1, 0, 9, 4
    };

    merge_sort(vec);
    print_vec(vec);
    return 0;
}
