// Time limit

#include <iostream>
#include <vector>

struct Building {
    int mineral;
    int gas;
    int defence;
};

struct Status {
    int mineral_left;
    int gas_left;
    int cur_defence;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int mineral, gas, types, max_defence = 0;
    std::cin >> mineral >> gas >> types;

    std::vector<Building> b(types);
    std::vector<Status> st(1);

    for (int i = 0; i < types; ++i) {
        std::cin >> b[i].mineral >> b[i].gas >> b[i].defence;
    }

    for (;;) {
        bool end = true;
        int ls_size = st.size();

        st.resize(ls_size * types);
        int steps = st.size() / types;

        if (st.size() == types) {
            for (int i = 0; i < types; ++i) {
                st[i] = {mineral - b[i].mineral, gas - b[i].gas, b[i].defence};
            }
            continue;
        }

        for (int i = ls_size - 1; i >= 0; --i) {
            for (int j = types - 1; j >= 0; --j) {
                if (st[i].mineral_left == 0 || st[i].gas_left == 0 || st[i].mineral_left < b[j].mineral || st[i].gas_left < b[j].gas) {
                    st[i * types + j] = {0, 0, 0};
                    continue;
                }
                st[i * types + j].mineral_left = st[i].mineral_left - b[j].mineral;
                st[i * types + j].gas_left = st[i].gas_left - b[j].gas;
                st[i * types + j].cur_defence = st[i].cur_defence + b[j].defence;
                if (st[i * types + j].cur_defence > max_defence) max_defence = st[i * types + j].cur_defence;
                end = false;
            }
        }

        if (end) break;
    }

    std::cout << max_defence << "\n";
}