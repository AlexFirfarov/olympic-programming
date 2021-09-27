#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    int d, s1, s2, hours, mins, sec;
    double t1, t2, diff;
    while (1) {
        std::cin >> d >> s1 >> s2;
        if (d == 0 && s1 == 0 && s2 == 0) break;
        t1 = (d / (double)s1) * 3600;
        t2 = (d / (double)s2) * 3600;
        diff = t1 - t2;
        if (diff < 0) diff = -diff;
        hours = diff / 3600;
        diff -= hours * 3600;
        mins = diff / 60;
        diff -= mins * 60;
        sec = std::round(diff);

        std::cout << hours << ":";
        std::cout << std::setfill('0') << std::setw(2);
        std::cout << mins << ":";
        std::cout << std::setfill('0') << std::setw(2);
        std::cout << sec << "\n";

    }
}