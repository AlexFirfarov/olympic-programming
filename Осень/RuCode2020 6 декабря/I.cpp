#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using ll = long long;

struct task {
    ll cur_points = 0;
    ll last_s = 0;
    ll fails_cnt = 0;
    ll cnt_f = 0;
};

struct participant {
    ll num;
    ll points;
    ll penalty;
};

bool operator<(const participant& lhs, const participant& rhs) {
    if (lhs.points > rhs.points) {
        return true;
    } else if ((lhs.points == rhs.points) && (lhs.penalty < rhs.penalty)) {
        return true;
    } else if ((lhs.points == rhs.points) && (lhs.penalty == rhs.penalty) && (lhs.num < rhs.num)) {
        return true;
    }
    return false;
}

int main() {
    ll n, k, num, time, task_num, points;
    ll p_full, penalty_full;
    std::cin >> n >> k;
    std::unordered_map<ll, std::unordered_map<ll, task>> m;
    std::vector<participant> p;
    while (n--) {
        std::cin >> num >> time >> task_num >> points;
        if (m[num][task_num].cur_points >= points) {
            m[num][task_num].cnt_f += 1;
            //m[num][task_num].fails_cnt += 1;
        } else {
            m[num][task_num].cur_points = points;
            m[num][task_num].last_s = time;
            m[num][task_num].fails_cnt = m[num][task_num].cnt_f;
        }
    }
    for (const auto& pr: m) {
        p_full = 0;
        penalty_full = 0;
        for (const auto& tsk: pr.second) {
            p_full += tsk.second.cur_points;
            penalty_full += tsk.second.last_s + tsk.second.fails_cnt * k;
        }
        p.push_back({pr.first, p_full, penalty_full});
    }
    std::cout << "\n";
    std::sort(begin(p), end(p));
    for (const participant& pr: p) {
        std::cout << pr.num << " " << pr.points << " " << pr.penalty << "\n";
    }

}