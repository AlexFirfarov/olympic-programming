#include <iostream>
#include <string>

int main() {
    int n, ans;
    std::cin >> n;
    std::string s;
    while (n--) {
        std::cin >> s;
        for (char& ch: s) {
            if (ch == 'A') {
                ch = '0';
            } else {
                ch = '1';
            }
        }
       ans = std::stoi(s, NULL, 2);
       std::cout << ans << "\n";
    }
}