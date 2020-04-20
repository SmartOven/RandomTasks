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
    TreeNode* bstFromPreorder(std::vector<int>& preorder) {
		TreeNode* top = new TreeNode;
		top->val = preorder[0];
    	for (size_t i = 1; i < preorder.size(); i++) {
			TreeNode* node = new TreeNode;
			node->val = preorder[i];
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
};

auto gucciGang = []() {std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0; }();

int main() {
	size_t n;
	cin >> n;
	std::vector <int> v(n);
	for (auto& i : v)
		cin >> i;
	Solution S1;
	TreeNode* answer = S1.bstFromPreorder(v);
	return 0;
}