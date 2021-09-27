#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    std::string s;
    std::cin >> s;
    std::unordered_map<char, int> pos;
    int max = 0;
    int cur = 0;
    int i = 0;
    int size = (int)s.size();
    while (true) {
        if (i == size) {
            if (cur > max) max = cur;
            break;
        }
        if (pos.count(s[i])) {
            i = pos[s[i]] + 1;
            if (cur > max) max = cur;
            cur = 0;
            pos.erase(pos.begin(), pos.end());
        } else {
            ++cur;
            pos[s[i]] = i;
            ++i;
        }
    }
    std::cout << max << "\n";
}