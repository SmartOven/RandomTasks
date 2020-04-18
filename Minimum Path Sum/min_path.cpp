#include <iostream>
#include <vector>
#include <string>
using std::cin;
using std::cout;
using std::string;

class Solution {
public:
	int minPathSum(std::vector<std::vector<int>>& grid) {
		constexpr int INF = 10e8; // We consider it as infinitive
		std::vector<std::vector<int>> d(grid.size(), std::vector <int>(grid[0].size(), INF));
		d[0][0] = grid[0][0];
		// We can go only right or down
		step(d, grid, 0, 0, 0);
		return d[d.size() -1][d[0].size() - 1];
	}
private:
	static void step(std::vector<std::vector<int>>& d, std::vector<std::vector<int>>& g, size_t x, size_t y, int distance) {
		// Updating distance
		distance += g[x][y];
		// If we found shorter path from start to (x, y), we updated d[x][y]
		if (distance < d[x][y])
 			d[x][y] = distance;
		// If we can go right
		if (x + 1 < g.size())
			// If distance to (x + 1, y) more than we may do
			if (distance + g[x + 1][y] < d[x + 1][y])
				step(d, g, x + 1, y, distance);
		// If we can go down - we goes
		if (y + 1 < g[x].size())
			// If distance to (x, y + 1) more than we may do
			if (distance + g[x][y + 1] < d[x][y + 1])
				step(d, g, x, y + 1, distance);
	}
};

int main() {
	size_t n, m;
	cin >> n >> m;
	std::vector <std::vector <int>> g(n, std::vector <int>(m));
	for (auto& line : g)
		for (auto& el : line)
			cin >> el;
	Solution S1;
	cout << S1.minPathSum(g) << "\n";
	return 0;
}