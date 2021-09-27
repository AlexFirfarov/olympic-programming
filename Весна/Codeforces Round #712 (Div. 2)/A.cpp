#include <iostream>
#include <string>

bool isPal(const std::string & st)
{
    for(auto b = st.begin(), e = st.end()-1; b < e; ++b, --e)
    {
        while(!isalnum(*b)) ++b;
        while(!isalnum(*e)) --e;
        if (toupper(*b) != toupper(*e)) return false;
    }
    return true;
}

int main() {
    int t;
    std::cin >> t;
    std::string s, tmp;
    for (int j = 0; j < t; ++j) {
        bool ok = false;
        std::cin >> s;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != 'a') {
                ok = true;
                break;
            }
        }
        
        if (!ok) {
            std::cout << "NO\n";
            continue;
        }

        tmp = s + "a";
        if (!isPal(tmp)) {
            std::cout << "YES\n";
            std::cout << tmp << "\n";
            continue;
        } else {
            std::cout << "YES\n";
            std::cout << "a" + s << "\n";
            continue;
        }
        
    }

    return 0;
}