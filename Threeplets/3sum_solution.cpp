#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
#include <vector>
using std::cin;
using std::cout;
using std::vector;
using std::set;

// You can use this function instead of lines 35-40
void Sort(vector <int>& v) {
	if (v[0] > v[1])
		std::swap(v[0], v[1]);
	if (v[0] > v[2])
		std::swap(v[0], v[2]);
	if (v[1] > v[2])
		std::swap(v[1], v[2]);
};

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		set <vector <int>> s;
		size_t n = nums.size();
		if (n < 3) {
			vector <vector <int>> ans;
			return ans;
		}
		for (size_t i = 0; i < n; i++)
			for (size_t j = i + 1; j < n; j++)
				for (size_t k = j + 1; k < n; k++)
					if (nums[i] + nums[j] + nums[k] == 0) {
						vector<int> v = { nums[i], nums[j], nums[k] };
						//
						if (v[0] > v[1])
							std::swap(v[0], v[1]);
						if (v[0] > v[2])
							std::swap(v[0], v[2]);
						if (v[1] > v[2])
							std::swap(v[1], v[2]);
						//
						s.insert(v);
					}
		vector <vector <int>> ans(s.size(), vector <int>(3));
		size_t counter = 0;
		for (auto i : s) {
			ans[counter] = i;
			counter++;
		}
		return ans;
	}
};

int main() {
	// Uncomment to file input
	// freopen("input.txt", "r", stdin);

	// Uncomment to file output
	// freopen("output.txt", "r", stdout);

	Solution S1;
	size_t n;
	cin >> n;
	vector <int> v(n);
	for (auto& i : v)
		cin >> i;
	vector <vector <int>> ans = S1.threeSum(v);
	for (auto i : ans) {
		for (auto j : i)
			cout << j << ' ';
		cout << "\n";
	}
	return 0;
}