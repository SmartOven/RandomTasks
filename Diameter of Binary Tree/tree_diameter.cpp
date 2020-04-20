#include <algorithm>
#include <iostream>
#include <vector>
using std::cin;
using std::cout;

struct TreeNode {
	int val;
	TreeNode* left = nullptr;
	TreeNode* right = nullptr;
};
 
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
		int answer = 0;
		if (root == nullptr)
			return answer;
		bfs(root, answer);
		return answer;
    }
private:
	int bfs(TreeNode* here, int& max_len) {
		size_t left_depth = 0;
		size_t right_depth = 0;
		if (here->left)
			left_depth = 1 + bfs(here->left, max_len);
		if (here->right)
			right_depth = 1 + bfs(here->right, max_len);
		if (max_len < left_depth + right_depth)
			max_len = left_depth + right_depth;
		return std::max(left_depth, right_depth);
	}
};

TreeNode* make_tree(std::vector<int>& tree_arr) {
	if (tree_arr.empty())
		return new TreeNode;
	TreeNode* top = new TreeNode;
	top->val = tree_arr[0];
	for (size_t i = 1; i < tree_arr.size(); i++) {
		TreeNode* node = new TreeNode;
		node->val = tree_arr[i];
		TreeNode* current = top;
		bool placed = false;
		while (!placed) {
			if (node->val < current->val) {
				if (current->left != nullptr)
					current = current->left;
				else {
					current->left = node;
					placed = true;
				}
			}
			if (node->val > current->val) {
				if (current->right != nullptr)
					current = current->right;
				else {
					current->right = node;
					placed = true;
				}
			}
		}
	}
	return top;
}

int main() {
	Solution S1;
	size_t n;
	cin >> n;
	std::vector <int> v(n);
	for (auto& i: v)
		cin >> i;
	// v = {4, 2, 5, 1, 3}
	TreeNode* tree = make_tree(v);
	cout << S1.diameterOfBinaryTree(tree);
	return 0;
}