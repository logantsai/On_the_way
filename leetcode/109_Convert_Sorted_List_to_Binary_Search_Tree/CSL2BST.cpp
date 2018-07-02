#include <iostream>
#include "LinkListTools.h"
#include "TreeTools.h"

using namespace std;

class Solution {
public:
    static TreeNode* sortedListToBST(ListNode* head) {
		if (!head) return nullptr;	// head from NULL
		if (!head->next) return new TreeNode(head->val);	// head from 1->NULL

		ListNode *slow, *fast, *last;
		last = slow = fast = head;
		while (fast && fast->next) {
			last = slow;
			slow = slow->next;
			fast = fast->next->next;
		}

		last->next = nullptr;
		fast = slow->next;

		TreeNode *cur = new TreeNode(slow->val);

		cur->right = sortedListToBST(fast);
		if (head != slow) cur->left = sortedListToBST(head);	// head from 1->2->NULL

		return cur;
    }
};

int main()
{
	int ary[] = {-10, -3, -1, 0, 5, 9};
	ListNode *head = createListFromIntArray(ary, lengthArray(ary));
	TreeNode *tree = Solution::sortedListToBST(head);
	cout << "Preoder: ";
	printTreePreorder(tree);
	cout << endl;
	return 0;
}
