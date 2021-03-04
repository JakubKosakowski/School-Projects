#include <iostream>
#include <functional>
#include <utility>
#include <vector>


void selection_sort(std::vector<int>::iterator b, std::vector<int>::iterator e,
                    std::function<bool(int, int)> compare = [](int e1, int e2) {return e1 < e2;}) {
    while (b < e) {
        auto m = b;
        for (auto i = b; ++i < e;) {
            if (compare(*i, *m)) {
                m = i;
            }
        }
        std::iter_swap(b++, m);
    }
}

int main() {
    std::vector<int> v{ 13, 2, 21, 5, 8, 5, 7, 10 };
    selection_sort(v.begin(), v.begin() + 4);
    selection_sort(v.begin() + 4, v.end(), [](int e1, int e2) {return e1 > e2; });
    for (auto i = v.cbegin(); i < v.cend(); ++i) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
}
