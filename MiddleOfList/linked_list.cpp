#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::vector;

struct ListNode {
    int val;
    ListNode* next;
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        size_t counter = 1;
        ListNode* current = head;
        while (current->next != nullptr) {
            counter++;
            current = current->next;
        }
        if (counter % 2 == 0)
            counter++;
        current = head;
        counter /= 2;
        while (counter) {
            counter--;
            current = current->next;
        }
        return current;
    }
};

int main() {
    size_t n;
	int x;
    cin >> n;
	
    cin >> x;
    ListNode head = { x, nullptr };
    ListNode* current = &head;
	
	for (size_t i = 0; i < (n - 1); i++) {
        cin >> x;
		
        current->next = new ListNode;
        current = current->next;
		
        current->val = x;
        current->next = nullptr;
	}
	
    Solution S1;
    ListNode* ans = S1.middleNode(&head);
    cout << ans->val << "\n";
	return 0;
}