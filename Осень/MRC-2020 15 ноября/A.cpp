#include <iostream>

int main() {
    int x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    int s = 0;

    if ((x1 > 0 && x2 <= 0) || (x1 < 0 && x2 >= 0) || (y1 > 0 && y2 <= 0) || (y1 < 0 && y2 >= 0)) {
        ++s;
    }
    std::cout << s << "\n";
    
}