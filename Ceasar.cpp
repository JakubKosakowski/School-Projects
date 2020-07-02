#include <cstdlib>
#include <fstream>

int main(int argc, char* argv[]) {
    int s = std::atof(argv[1]);
    std::fstream input(argv[2]);
    std::ofstream output(argv[3]);

    for (char c; input.get(c);) {
        if ((c >= 'A') && (c <= 'Z') || (c >= 'a') && (c <= 'z')) {
            if ((c >= 'A') && (c <= 'Z')) {
                if (c + s < 'A') {
                    output << char(c + s + 26);
                }
                else if (c + s > 'Z') {
                    output << char(c + s - 26);
                }
                else {
                    output << char(c + s);
                }
            }
            if ((c >= 'a') && (c <= 'z')) {
                if (c + s < 'a') {
                    output << char(c + s + 26);
                }
                else if (c + s > 'z') {
                    output << char(c + s - 26);
                }
                else {
                    output << char(c + s);
                }
            }
        }
        else {
            output << c;
        }
    }

    input.close();
    output.close();

    return 0;
}
