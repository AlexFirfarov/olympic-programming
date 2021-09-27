#include <iostream>
#include <string>
#include <unordered_set>

int main() {

    std::string s;
    std::cin >> s;
    std::unordered_set<char> st;

    for (int i = 0; i < s.size(); ++i) {
        st.insert(s[i]);
    }

    if (s.size() == st.size()) {
        std::cout << 1 << "\n";
    } else {
        std::cout << 0 << "\n";
    }
}