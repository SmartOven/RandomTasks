#include <iostream>
#include <vector>
using std::cin;
using std::cout;

class Solution {
public:
    int findMaxLength(std::vector<int>& nums) {
	    const int N = nums.size() * 2;
		std::vector <std::pair <int, int>> data(N + 2, { 50001, -50001 });
		int counter = 0;
		data[N / 2].first = 0; // used to initialize range(-50000, 50000) as range(0, 100000), so N/2 is equal to 0
		for (int i = 1; i <= N / 2; i++) {
			const int num = nums[i - 1];
			num ? ++counter : --counter;
			if (i < data[N / 2 + counter].first)
				data[N / 2 + counter].first = i;
			if (i > data[N / 2 + counter].second)
				data[N / 2 + counter].second = i;
		}
		int max_diff = 0;
		for (auto& i : data)
			if (max_diff < i.second - i.first)
				max_diff = i.second - i.first;
		return max_diff;
    }
};

auto gucciGang = []() {std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0; }();

int main() {
	size_t n;
	cin >> n;
	std::vector <int> v(n);
	for (auto& i : v)
		cin >> i;
	Solution S1;
	cout << S1.findMaxLength(v) << "\n";
	return 0;
}