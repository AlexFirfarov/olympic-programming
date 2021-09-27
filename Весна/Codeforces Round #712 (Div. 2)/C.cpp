#include <iostream>
#include <string>

void solve() {
    int n, rs = 0, k = 0;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    for (int i = 0; i < n; ++i) 
        if (s[i] == '1') ++rs;

    if (rs % 2 || s[0] == '0' || s[s.size() - 1] == '0') {
        std::cout << "NO\n";
        return;
    }

    std::string f, sc;
    bool fl = false;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            if (2 * k < rs)
                f.push_back('(');
            else 
                f.push_back(')');
            sc.push_back(f[f.size() - 1]);
            ++k;
        } else {
            if (fl) 
                f.push_back('(');
            else
                f.push_back(')');

            if (fl)
                sc.push_back(')');
            else
                sc.push_back('(');

            fl = !fl;
        }
    }

    std::cout << "YES\n";
    std::cout << f << "\n";
    std::cout << sc << "\n";
}

int main() {
    int t;
    std::cin >> t;
    while(t--)
        solve();
}