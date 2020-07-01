#include <iostream>
#include <vector>

std::vector<int>::iterator min_element(std::vector<int>::iterator b, std::vector<int>::iterator e) {
	auto ret = b;

	for (; b < e; ++b) {
		if (*ret > *b) {
			ret = b;
		}
	}
	return ret;
}
std::vector<int>::const_iterator min_element(std::vector<int>::const_iterator b, std::vector<int>::const_iterator e) {
	auto ret = b;

	for (; b < e; ++b) {
		if (*ret > * b) {
			ret = b;
		}
	}
	return ret;
}

int main() {
	std::vector<int> vector{ 7, 5, 1, 1, 8 };
	std::vector<int>::iterator result1 = min_element(vector.begin(), vector.end());
	std::vector<int>::const_iterator result2 = min_element(vector.cbegin(), vector.cend());
	std::cout << result1 - vector.begin() << " "
		<< result2 - vector.cbegin() << std::endl;
}
