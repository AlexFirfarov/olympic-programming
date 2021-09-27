// WRONG ANSWER

#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;
    if (a == b) {
        std::cout << 0 << "\n";
        return 0;
    }
    std::cout << 3 << "\n";
    std::cout << "b=a+b\n";
    std::cout << "a=b-a\n";
    std::cout << "b=b-a\n";
}