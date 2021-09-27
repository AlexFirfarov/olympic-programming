#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>

#define ll long long

int main() {
    int n;
    std::cin >> n;
    std::vector<ll> v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }
    ll top;
    std::stack<ll> s;
    std::vector<ll> rec;
    int i = 0;
    for (i; i < n;) {
        if (s.empty() || v[s.top()] <= v[i]) {
            s.push(i++);
        } else {
            top = s.top();
            s.pop();
            ll st = s.empty() ? i : i - s.top() - 1;
            rec.push_back(std::min(st, v[top]));                
        }
    }
    while (!s.empty()) {
        top = s.top();
        s.pop();
        ll st = s.empty() ? i : i - s.top() - 1;
        rec.push_back(std::min(st, v[top]));
    }
    ll max_h = 1;
    for (int j = 0; j < rec.size(); ++j) {
        if (rec[j] > max_h) max_h = rec[j];
    }
    std::cout << max_h << "\n";
}