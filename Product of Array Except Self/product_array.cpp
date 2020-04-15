#include <iostream>
#include <vector>
using std::cin;
using std::cout;

class Solution {
public:
	std::vector<int> productExceptSelf(std::vector<int>& nums) {
		const size_t N = nums.size();
		std::vector <int> v1(N);
		std::vector <int> v2(N);
		v1[0] = 1;
		v2[N - 1] = 1;
		for (size_t i = 1; i <= N - 1; i++) {
			v1[i] = v1[i - 1] * nums[i - 1];
			v2[N - 1 - i] = v2[N - i] * nums[N - i];
		}
		for (size_t i = 0; i <= N - 1; i++) {
			nums[i] = v1[i] * v2[i];
		}
		return nums;
    }
};

static int gucciGang = []() {std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0; }();

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