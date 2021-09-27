// Time limit exceed

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

struct Pr {
    Pr(long long t_, long long p_, int idx_) {
        t = t_;
        p = p_;
        idx = idx_;
    }
    long long t;
    long long p;
    int idx;
};

bool operator < (const Pr& lhs, const Pr& rhs) {
    if ((lhs.p + lhs.t) != (rhs.p + rhs.t))
        return (lhs.p + lhs.t) < (rhs.p + rhs.t);
    return lhs.idx > rhs.idx;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long n, full_time;
    std::cin >> n >> full_time;
    std::priority_queue<Pr> data;
    std::vector<Pr> tmp_v;
    //std::vector<long long> p(n);
    //std::vector<long long> t(n, 0);
    std::vector<long long> time(n, 0);

    for (long long i = 0; i < n; ++i) {
        long long p;
        std::cin >> p;
        data.push(Pr(0, p, i));
    }
    for (long long sec = 0; sec < full_time; ++sec) {
        Pr max_pr = data.top();
        //std::cout << max_pr.p + max_pr.t << "\n";
        max_pr.t = 0;
        int idx_max = max_pr.idx;
        ++time[idx_max];
        data.pop();
        tmp_v.push_back(max_pr);

        while (!data.empty()) {
            Pr tmp = data.top();
            ++tmp.t;
            data.pop();
            tmp_v.push_back(tmp);
        }

        for (const auto& el : tmp_v) {
            data.push(el);
        }
        tmp_v.clear();

    }
    for (long long i = 0; i < n; ++i) {
        std::cout << time[i] << " ";
    }
    std::cout << "\n";
}