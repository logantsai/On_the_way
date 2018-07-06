#include <iostream>
#include "LinkListTools.h"

using namespace std;

class Solution {
public:
	static ListNode* reverseList(ListNode* head) {
		ListNode *dummy = new ListNode(-1);
		ListNode *pre, *cur;
		dummy->next = head;
		pre = dummy;
		cur = head;

		while (cur) {
			ListNode *tmp = cur->next;
			cur->next = pre;
			pre = cur;
			cur = tmp;
		}
		head->next = nullptr;
		return pre;
	}

    static ListNode* reorderList(ListNode* head) {
		ListNode *slow, *fast, *pre, *sechead;
		slow = fast = head;

		while (fast && fast->next) {
			pre = slow;
			slow = slow->next;
			fast = fast->next->next;
		}

		if (!fast) {	// even elements
			pre->next = nullptr;
			sechead = slow;
		} else {		// odd elements
			sechead = slow->next;
			slow->next = nullptr;
		}

		printList(head);
		printList(sechead);

		sechead = reverseList(sechead);

		ListNode *dummy = new ListNode(-1);
		dummy->next = head;
		ListNode *cur = dummy;
		while (sechead) {
			ListNode *tmp = head->next;

			cur->next = head;
			cur->next->next = sechead;

			head = tmp;
			sechead = sechead->next;

			cur = cur->next->next;
		}

		cur->next = head ? head : nullptr;
		return dummy->next;
    }

};

int main()
{
	int ary1[] = {1, 2, 3, 4, 5, 6};
	int ary2[] = {1, 2, 3, 4, 5};

	ListNode *head1 = createListFromIntArray(ary1, lengthArray(ary1));
	ListNode *head2 = createListFromIntArray(ary2, lengthArray(ary2));

	ListNode *result1 = Solution::reorderList(head1);
	ListNode *result2 = Solution::reorderList(head2);
	printList(result1);
	printList(result2);
	return 0;
}
