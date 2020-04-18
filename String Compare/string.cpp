#include <iostream>
#include <stack>
#include <string>
using std::cin;
using std::cout;
using std::string;

class Solution {
public:
	bool backspaceCompare(string S, string T) {
		std::stack <char> St1, St2;
		for (char i : S) {
			if (i == '#') {
				if (!St1.empty())
					St1.pop();
			}
			else {
				St1.push(i);
			}
		}
		for (char i : T) {
			if (i == '#') {
				if (!St2.empty())
					St2.pop();
			}
			else {
				St2.push(i);
			}
		}
		while (!St1.empty() && !St2.empty()) {
			if (St1.top() != St2.top())
				return false;
			St1.pop();
			St2.pop();
		}
		if (!St1.empty() || !St2.empty())
			return false;
		return true;
	}
};

int main() {
	string s, t;
	cin >> s >> t;
	Solution S1;
	cout << S1.backspaceCompare(s, t) << "\n";
	return 0;
}
