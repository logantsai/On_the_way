#include <iostream>
#include "LinkListTools.h"

using namespace std;


class Solution {
public:
    static ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode *dummy = new ListNode(-1);
		dummy->next = head;
		ListNode *pre, *cur;
		pre = dummy;
		cur = head;

		for (int i = 0; i < n; i++) {
			cur = cur->next;
		}

		while (cur) {
			cur = cur->next;
			pre = pre->next;
		}
		cout << pre->next->val << endl;
		pre->next = pre->next->next;	//	pre->next is Nth.
		return dummy->next;
    }
};

int main()
{
	int ary[] = {5, 4, 3, 2, 1};
	ListNode *head = createListFromIntArray(ary, lengthArray(ary));
	printList(head);

	ListNode *head2 = Solution::removeNthFromEnd(head, 2);
	printList(head2);

	return 0;
}
