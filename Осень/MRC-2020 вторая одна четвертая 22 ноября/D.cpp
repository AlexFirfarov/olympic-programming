#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    int n, w, h, s, max = -1;
    char symb, max_symb;
    std::unordered_map<char, int> m;
    std::string ss;
    std::cin >> n >> w >> h >> s;
    while(n--) {
        std::cin >> symb;
        m[symb] = 0;
        for (int j = 0; j < h; ++j) {
            int cnt = 0;
            std::cin >> ss;
            for (int i = 0; i < w - 1; ++i) {
                if (ss[i] == '.' && ss[i + 1] == '#')
                    cnt += 2;
            }
            if (ss[0] == '#') cnt += 2;
            if (cnt > m[symb]) {
                m[symb] = cnt;
            }
        }
    }
    for (const auto& p: m) {
        if (p.second > max) {
            max = p.second;
            max_symb = p.first;
        }
    }
    int c = s / max;
    if (max * c < s) ++c;
    for (int i = 0; i < c; ++i) {
        std::cout << max_symb;
    }
    std::cout << "\n";
}