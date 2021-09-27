#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> p(n);
    for (auto& point: p) {
        std::cin >> point.first >> point.second;
    }
    double s = 0;
    for (int i = 0; i < n - 1; ++i) {
        s += p[i].first * p[i + 1].second - p[i + 1].first * p[i].second; 
    }
    s += p[n - 1].first * p[0].second - p[0].first * p[n - 1].second;
    std::cout << std::setprecision(3) << std::fixed << std::abs(s / 2) << "\n";
}