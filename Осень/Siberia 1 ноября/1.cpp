#include <iostream>
#include <string>

int main() {
    int t;
    std::cin >> t;
    std::cin.ignore(1);
    while (t--) {
        std::string s;
        std::getline(std::cin, s);
        std::string ans;
        for (int i = 0; i < (int)s.size() - 1; ++i) {
            ans.push_back(s[i]);
            if ((s[i] != '-' && s[i] != ':') && (s[i + 1] == '-' || s[i + 1] == ':')) {
                if (s[i] != ' ' && s[i] != '\n') {
                    ans.push_back(' ');
                }
            }
            if (s[i] == '-' || s[i] == ':') {
                if (s[i + 1] != ' ' && s[i + 1] != '\n') {
                    ans.push_back(' ');
                }
            }
        }
        ans.push_back(s[s.size() - 1]);
        std::cout << ans << "\n";
    }

}