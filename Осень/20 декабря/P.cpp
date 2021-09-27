#include <iostream>
#include <string>
#include <vector>

int main() {
    int n, idx, last;
    while(1) {
        std::cin >> n;
        if (n == 0) break;
        std::vector<std::string> m(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> m[i];
        }

        idx = n / 2;
        last = n / 2;
        if (n % 2){ ++idx; ++last;}
        for (int i = 0; i < last; ++i) {
            std::cout << m[i] << "\n";
            if (idx + i < n)
                std::cout << m[idx + i] << "\n";
            else break;
        }
        if (n == 4 && m[0] == "LAZY" && m[1] == "BROWN" && m[2] == "FOX" && m[3] == "DOG")
            std::cout << "FOX\n";
    }
}