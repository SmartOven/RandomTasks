#include <iostream>
#include <vector>
using std::cin;
using std::cout;

class Solution {
public:
	std::vector<int> productExceptSelf(std::vector<int>& nums) {
		size_t N = nums.size();
		int preanswer = 1;
		size_t zero_counter = 0;
		std::vector <int> answer(N);
		for (auto& i : nums) {
			if (i == 0) {
				if (zero_counter > 0)
					preanswer = 0;
				zero_counter++;
			}
			else
				preanswer *= i;
		}
		if (!preanswer) {
			answer.assign(N, 0);
		}
		else {
			for (size_t i = 0; i < N; i++) {
				if (nums[i] != 0) {
					if (zero_counter > 0)
						answer[i] = 0;
					else
						answer[i] = preanswer / nums[i];
				}
				else
					answer[i] = preanswer;
			}
		}
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
	std::vector <int> ans = S1.productExceptSelf(v);
	for (auto& i : ans)
		cout << i << ' ';
	cout << "\n";
	return 0;
}