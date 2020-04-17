#include <iostream>
#include <stack>
#include <vector>
using std::cin;
using std::cout;

class Solution {
public:
    bool checkValidString(std::string s) {
		size_t n = s.length();
		std::vector <char> symbols(n);
		std::stack <int> breaks;
		std::stack <int> stars;
		for (int i = 0; i < n; i++) {
				if (s[i] == '(')
					breaks.push(i);
				if (s[i] == '*')
					stars.push(i);
				if (s[i] == ')')
					if (!breaks.empty())
						breaks.pop();
					else if (!stars.empty())
						stars.pop();
					else
						return false;
		}
		while (!stars.empty() && !breaks.empty()) {
				if (breaks.top() > stars.top()) {
					return false;
				}
				stars.pop();
				breaks.pop();
		}
		if (!breaks.empty())
			return false;
		return true;
    }
};

auto gucciGang = []() {std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0; }();

int main() {
	std::string str;
	cin >> str;
	Solution S1;
	cout << (S1.checkValidString(str) ? "Yes\n" : "No\n");
	return 0;
}
