#include <iostream>
#include <vector>

using ll = long long;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--) {
        ll res = 0, idx, n, m, k, last;
        char c;
        cin >> n >> m >> k;
        last = k;
        vector<char> s(n);
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
        }
        for (int i = 1; i <= m; ++i) {
            cin >> c;
            if (c == 'W') {
                cin >> idx;
                if (idx <= last && s[idx - 1] == 'S')
                    ++res;
                else if (idx > last)
                    last = idx;
            } else {
                last = n;
            }
        }
        std::cout << res << "\n";
    }
}