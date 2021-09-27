#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

int main() {
    string team1, team2, name;
    unordered_map<string, int> team1_m, team2_m;
    unordered_set<string> on_court_1, on_court_2;
    vector<pair<string, string>> order;
    cin >> team1;
    for (int i = 0; i < 5; ++i) {
        cin >> name;
        team1_m[name] = 0;
        on_court_1.insert(name);
        order.push_back(pair<string, string>(name, team1));
    }
    cin >> team2;
    for (int i = 0; i < 5; ++i) {
        cin >> name;
        team2_m[name] = 0;
        on_court_2.insert(name);
        order.push_back(pair<string, string>(name, team2));
    }
    int q, n;
    cin >> q;
    string team, command, y, z;
    while (q--) {
        cin >> team;
        cin >> team;
        cin >> command;
        if (command == "scored") {
            cin >> n;
            if (team == team1) {
                for (const string& p: on_court_1) {
                    team1_m[p] += n;
                }
                for (const string& p: on_court_2) {
                    team2_m[p] -= n;
                }
            } else {
                for (const string& p: on_court_1) {
                    team1_m[p] -= n;
                }
                for (const string& p: on_court_2) {
                    team2_m[p] += n;
                }
            }
        } else {
            cin >> y;
            cin >> z;
            cin >> z;
            if (team == team1) {
                on_court_1.erase(y);
                on_court_1.insert(z);
                if (!team1_m.count(z)) {
                    order.push_back(pair<string, string>(z, team1));
                    team1_m[z] = 0;
                }
            } else {
                on_court_2.erase(y);
                on_court_2.insert(z);
                if (!team2_m.count(z)) {
                    order.push_back(pair<string, string>(z, team2));
                    team2_m[z] = 0;
                }
            }
        }
    }
    int score;
    for (const auto& p: order) {
        cout << p.first << " ";
        cout << "(" << p.second << ") ";
        if (p.second == team1) 
            score = team1_m[p.first];
        else 
            score = team2_m[p.first];
        if (score > 0) cout << "+";
        cout << score << "\n";
    }

}