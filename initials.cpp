#include <iostream>
#include <string>

std::string initials(std::string x) {
	std::string ret;
	if (x[0] != ' ') {
		ret += x[0];
		for (int i = 1; i < x.size(); ++i) {
			if (x[i] == ' ') {
				if (x[i + 1] != ' ') {
					ret += x[i + 1];
				}
			}
		}
	}
	else {
		for (int i = 0; i < x.size(); ++i) {
			if (x[i] == ' ') {
				if (x[i + 1] != ' ') {
					ret += x[i + 1];
				}
			}
		}
	}

	return ret;
}

int main() {
	std::cout << initials("John Fitzgerald Kennedy") << std::endl;
	std::cout << initials(std::string("andy warhol")) << std::endl;
}
