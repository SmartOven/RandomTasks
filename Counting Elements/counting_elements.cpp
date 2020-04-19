#include <iostream>
#include <vector>
using std::cin;
using std::cout;

class Solution {
public:
	int countElements(std::vector<int>& arr) {
		// used[i].first -> count of 'i' in array
		// used[i].second -> true if 'i+1' was in array
		if (arr.empty())
			return 0;
		std::vector <std::pair <int, bool>> used(1002, { 0 , false });
		for (int i : arr) {
			used[i + 1].first++;
			used[i].second = true;
		}
		int answer = 0;
		for (auto p: used)
			if (p.second)
				answer += p.first;
		return answer;
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
	cout << S1.countElements(v) << "\n";
	return 0;
}