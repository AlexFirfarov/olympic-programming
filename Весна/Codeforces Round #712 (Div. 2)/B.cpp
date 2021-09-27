#include <iostream>
#include <string>

void solve() {
    int n, rs = 0;
    std::cin >> n;
    std::string a, b;
    std::cin >> a >> b;

    a.push_back('0');
    b.push_back('0');

    for (int i = 0; i < n; ++i) {
        if (a[i] == '1') ++rs;
        if (a[i] == '0') --rs;

        if ((a[i] == b[i]) != (a[i + 1] == b[i + 1]) && rs)  {
            std::cout << "NO\n";
            return;
        }
    } 
    std::cout << "YES\n";
}

int main() {
    int t;
    std::cin >> t;
    while(t--) 
        solve();
}