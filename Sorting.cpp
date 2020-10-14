
#include <iostream>
#include <vector>

void print_vector(std::vector<int> &v, int n)
{
    for (int i = 0; i < n; ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}
void quick_sort(std::vector<int> &v, int l, int h)
{
    int i = l;
    int j = h;
    int p = v[(i + j) / 2];
    int pom;

    print_vector(v, v.size());
    while (i <= j)
    {
        while (v[i] < p) {
            i++;
        }
        while (v[j] > p) {
            j--;
        }
        if (i <= j)
        {
            pom = v[i];
            v[i] = v[j];
            v[j] = pom;
            i++;
            j--;
        }
    }
    if (j > l)
        quick_sort(v, l, j);
    if (i < h)
        quick_sort(v, i, h);
}
void bubble_sort(std::vector<int>& v, int n) {
    int pom;
    print_vector(v, v.size());
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            if (v[j] < v[j-1]) {
                pom = v[j-1];
                v[j-1] = v[j];
                v[j] = pom;
                print_vector(v, v.size());
            }
        }
    }
}
void selection_sort(std::vector<int>& v, int n) {
    int pom;
    print_vector(v, v.size());
    for (int i = 0; i < n; ++i) {
        int z = i;
        for (int j = z; j < n; ++j) {
            if (v[j] < v[z]) {
                z = j;
            }
        }
        if (i != z) {
            pom = v[z];
            v[z] = v[i];
            v[i] = pom;
            print_vector(v, v.size());
        }
    }
}

int main()
{
    std::vector<int> a;
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        int c;
        std::cin >> c;
        a.push_back(c);
    }
    std::vector<int> q = a;
    std::vector<int> b = a;
    std::vector<int> s = a;
    std::cout << "Quick Sort: " << std::endl;
    quick_sort(q, 0, n - 1);
    std::cout << std::endl;
    std::cout << "Bubble Sort: " << std::endl;
    bubble_sort(b, n);
    std::cout << std::endl;
    std::cout << "Selection Sort: " << std::endl;
    selection_sort(s, n);

    return 0;
}
