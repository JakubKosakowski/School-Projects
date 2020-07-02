#include <iostream>
#include <vector>



int main() {
	std::vector<int> v;
	for (int i; std::cin >> i;) {
		v.push_back(i);
	}
	for (int i = 0; i < v.size(); ++i) {
		int z = i;
		for (int j = z; j < v.size(); ++j) {
			if (v[j] < v[z]) {
				z = j;
			}
		}
		std::swap(v[i], v[z]);
		for (int k = 0; k < v.size(); ++k) {
			std::cout << v[k] << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}
