//WRONG ANSWER

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <unordered_set>

using ull = unsigned long long;

int main() {

    ull n, k, res = 0, st, st_10, st_10_prev, t, pos, res_pos = 0, start;
    ull tmp;
    std::cin >> n >> k;

    int mn = 10 - k;

    std::unordered_set<ull> v;
    std::unordered_set<char> v_s;
    for (int i = 0; i < k; ++i) {
        std::cin >> tmp;
        v.insert(tmp);
        v_s.insert(std::to_string(tmp)[0]);
    }
    //std::sort(v.begin(), v.end());

    st = trunc(std::log10(n)) + 1;

    st_10 = 1;
    st_10_prev = 1;
    start = 1;

    std::string s_n = std::to_string(n);
    for (int i = 0; i < s_n.size(); ++i) {
        if (v_s.count(s_n[i])) {
            pos = i;
            for (int j = 0; j < st - pos - 1; ++j) {
                st_10 *= 10;
                if (j != 0) st_10_prev *= 10;
            }
            res_pos += n % st_10;
            start = st - pos;
            break;
        }
    }

    for (int i = start; i <= st; ++i) {
        st_10 *= 10;
        if (i != 1) st_10_prev *= 10;

        t = n % st_10;
        t /= st_10_prev;

        ull tmp_res = t;
        for (auto v_j : v) {
            if (v_j < t) --tmp_res;
        }

        for (int j = 0; j < i - 1; ++j)
            tmp_res *= mn;
        res += (t * st_10_prev - tmp_res);
    }

    t = n / st_10;
    for (auto v_j : v) {
        if (t == v_j) {
            ++res;
            break;
        }
    }
    res += res_pos;
    ull f_res = res + n;

    std::cout << f_res << "\n";

}