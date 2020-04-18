#include <iostream>
#include <vector>
#include <string>
using std::cin;
using std::cout;
using std::string;

class Solution {
public:
	int numIslands(std::vector<std::vector<char>>& grid) {
		// Not-changing 'grid' algorithm
		if (grid.empty())
			return 0;
		const size_t lines = grid.size();
		const size_t columns = grid[0].size();
		std::vector <std::vector <int>> used(lines, std::vector <int>(columns, 0));
		size_t components = 1;
		for (size_t i = 0; i < lines; i++)
			for (size_t j = 0; j < columns; j++)
				if (!used[i][j] && grid[i][j] == '1') {
					dfs(i, j, used, grid, components);
					components++;
				}
		return --components;
	}
private:
	void dfs(int line, int column, std::vector <std::vector <int>>& used,
		std::vector<std::vector<char>>& graph, size_t num) {
		used[line][column] = num;
		if (line > 0 && used[line - 1][column] == 0 && graph[line - 1][column] != '0')
			dfs(line - 1, column, used, graph, num); // go up
		if (column > 0 && used[line][column - 1] == 0 && graph[line][column - 1] != '0')
			dfs(line, column - 1, used, graph, num); // go left
		if (line + 1 < graph.size() && used[line + 1][column] == 0 && graph[line + 1][column] != '0')
			dfs(line + 1, column, used, graph, num); // go down
		if (column + 1 < graph[line].size() && used[line][column + 1] == 0 && graph[line][column + 1] != '0')
			dfs(line, column + 1, used, graph, num); // go right
	}
};

auto gucciGang = []() {std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0; }();

int main() {
	size_t n, m;
	cin >> n >> m;
	std::vector<std::vector<char>> g(n, std::vector <char>(m));
	for (auto& line : g)
		for (auto& el : line)
			cin >> el;
	Solution S1;
	cout << S1.numIslands(g) << "\n";
	return 0;
}