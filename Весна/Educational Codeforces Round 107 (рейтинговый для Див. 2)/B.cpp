#include <iostream>
#include <string>

void solve() {
    int a, b, c;
    std::cin >> a >> b >> c;

    std::string x(a, '0');
    x[0] = '1';

    std::string y(b, '0');
    for (int i = 0; i < b - c + 1; ++i) {
        y[i] = '1';
    }

    std::cout << x << " " << y << "\n";
}

int main() {

    int t;
    std::cin >> t;
    while (t--)
        solve();
}