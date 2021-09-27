#include <iostream>
#include <string>
#include <vector>

void rot(std::vector<std::vector<char>>& s) {
    int N = (int)s.size();
    for (int i = 0; i < N / 2; ++i) {
        for (int j = i; j < N - i - 1; ++j) {
            char temp = s[i][j];
            s[i][j] = s[N - 1 - j][i];
            s[N - 1 - j][i] = s[N - 1 - i][N - 1 - j];
            s[N - 1 - i][N - 1 - j] = s[j][N - 1 - i];
            s[j][N - 1 - i] = temp;
        }
    } 
}

void horizontal(std::vector<std::vector<char>>& s) {
    int n = (int)s.size();
    for (int i = 0; i < n / 2; ++i)
        for (int j = 0; j < n; ++j) { 
            int tmp = s[i][j];
            s[i][j] = s[n-i-1][j];
            s[n-i-1][j] = tmp;
        }
}

void vertical(std::vector<std::vector<char>>& s) {
    int n = (int)s.size();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n / 2; ++j) { 
            int tmp = s[i][j];
            s[i][j] = s[i][n-j-1];
            s[i][n-j-1] = tmp;
        }
}

bool operator==(const std::vector<std::vector<char>>& lhs, const std::vector<std::vector<char>>& rhs) {
    int n = (int)lhs.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (lhs[i][j] != rhs[i][j]) return false;
        }
    }
    return true;
}

int main() {
    int n;
    std::cin >> n;
    //std::vector<std::vector<char>> s = { {'a', 'b', 'c'}, {'d', 'e', 'f'}, {'h', 'k', 'l'} };
    std::vector<std::vector<char>> s(n, std::vector<char>(n));
    std::vector<std::vector<char>> t(n, std::vector<char>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> s[i][j];
        }
    }
    std::cin.ignore(1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> t[i][j];
        }
    }

    if (s == t) {
        std::cout << "YES\n";
        return 0;
    }
    horizontal(s);
    if (s == t) {
        std::cout << "YES\n";
        return 0;
    }
    vertical(s);
    if (s == t) {
        std::cout << "YES\n";
        return 0;
    }
    vertical(s);
    horizontal(s);

    for (int i = 0; i < 3; ++i) {
        rot(s);
        if (s == t) {
            std::cout << "YES\n";
            return 0;
        }
        horizontal(s);
        if (s == t) {
            std::cout << "YES\n";
            return 0;
        }
        vertical(s);
        if (s == t) {
            std::cout << "YES\n";
            return 0;
        }
        vertical(s);
        horizontal(s);
    }
    std::cout << "NO\n";
    //horizontal(s);
    //vertical(s);
    //for (int i = 0; i < s.size(); ++i) {
    //    for (int j = 0; j < s.size(); ++j)
    //        std::cout << s[i][j] << " ";
    //    std::cout << "\n";
    //}
}