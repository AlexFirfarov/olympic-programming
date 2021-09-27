#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <cmath>

using ll = long long;

int main() {
    ll n, idx, l, r;
    double dist, min = 0;
    bool ok = false;
    std::cin >> n;
    std::vector<std::pair<ll, ll>> v(n);
    std::set<std::pair<ll, ll>> res;
    std::unordered_set<ll> s;

    for (ll i = 0; i < n; ++i) {
        std::cin >> v[i].first >> v[i].second;
    }
    for (ll it = 0; it < n / 2; ++it) {
        for (ll i = 0; i < n; ++i) {
            if (s.count(i)) continue;
            for (ll j = 0; j < n; ++j) {
                if (s.count(j) || j == i) continue;
                dist = std::sqrt((v[j].first - v[i].first) * (v[j].first - v[i].first) + (v[j].second - v[i].second) * (v[j].second - v[i].second)); 
                if (dist < min || ok == false) {
                    min = dist;
                    l = i;
                    r = j;
                    ok = true;
                }
            }
        }
        if (ok) {
            s.insert(l);
            s.insert(r);
            if (l < r) res.insert({l, r});
            else  res.insert({r, l});
            ok = false;
        }
    }

    /*
    for (ll i = 0; i < n; ++i) {
        if (s.count(i)) continue;
        for (ll j = i + 1; j < n; ++j) {
            if (s.count(j)) continue;
            dist = std::sqrt((v[j].first - v[i].first) * (v[j].first - v[i].first) + (v[j].second - v[i].second) * (v[j].second - v[i].second)); 
            if (dist < min || ok == false) {
                min = dist;
                idx = j;
                ok = true;
            }
        }
        if (ok) {
            s.insert(i);
            s.insert(idx);
            res.insert({i, idx});
        }
        ok = false;
    }*/

    for (const std::pair<ll, ll>& p : res) {
        std::cout << p.first + 1 << " " << p.second + 1 << "\n";
    }
}