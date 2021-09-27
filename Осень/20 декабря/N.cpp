#include <iostream>
#include <vector>

int main() {
	int n; 
	std::cin >> n;
	std::vector<std::vector<std::pair<int, int>>> g(n); 
	const int intmax = 2147483647;
	int tresh;
	std::cin >> tresh;
	tresh *= tresh;
	int s = 0;
	int f = n - 1;
	std::vector<std::pair<int, int>> coor(n);
	for (int i = 0; i < n; ++i)
		std::cin >> coor[i].first >> coor[i].second;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i != j) {
				int dist = (coor[i].first - coor[j].first) * (coor[i].first - coor[j].first) + ((coor[i].second - coor[j].second) * (coor[i].second - coor[j].second));
				if(dist<=tresh)
					g[i].push_back(std::pair<int, int>(j, dist));
			}
		}
	}
	std::vector<int> d(n, intmax);
	d[s] = 0;
	std::vector<bool> u(n, false);
	for (int i = 0; i < n; ++i) {
		int v = -1; 
		for (int j = 0; j < n; ++j) 
			if ((!u[j]) && ((v == -1) || (d[j] < d[v])))
				v = j;
		if (d[v] == intmax)
			break;
		u[v] = true;
		for (auto& j : g[v]) {
			if (d[v] + j.second < d[j.first])
				d[j.first] = d[v] + j.second;
		}
	}
	std::cout << (d[f] != intmax ? 'y' : 'n') << std::endl;
}