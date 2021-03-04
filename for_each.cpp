#include <iostream>
#include <functional>
#include <vector>

void for_each(std::vector<int>::iterator b, std::vector<int>::iterator e,
             std::function<void(int &)> action) {
    while (b < e) {
        action(*b++);
    }
}

int main() {
    std::vector<int> v(5);
    for_each(v.begin(), v.end(), [](int &e) {std::cin >> e;});
    int i = 0;
    for_each(v.begin(), v.end(), [&i](int e) {std::cout << i << " " << e << std::endl; ++i; });
    std::cout << std::endl;
}
