#include <iostream>
#include <string>
#include <set>

int main() {
    int n, res = 0;
    std::string s;
    std::set<char> d = {'a', 'i', 'o', 'u', 'e', 'y'};

    std::cin >> n;
    std::cin >> s;
    if (n == 1) {
        std::cout << "0\n";
        return 0;
    }
    for (int i = 1; i < n;) {
        if ((d.count(s[i]) && !d.count(s[i - 1])) || (!d.count(s[i]) && d.count(s[i - 1]))) {
            ++res;
            i += 2;
        } else {
            ++i;
        }
    }
    std::cout << res << "\n";
}