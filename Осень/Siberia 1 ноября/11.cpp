#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::string f;
    std::vector<std::string> types;
    std::unordered_map<std::string, int> m;
    while (n--) {
        std::cin >> f;
        int idx = f.find('.');
        std::string type = f.substr(idx + 1);
        if (!m.count(type))
            types.push_back(type);
        ++m[type];
    }
    for (const std::string& type: types) {
        std::cout << type << ": " << m[type] << "\n";
    }
}