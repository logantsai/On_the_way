#include <iostream>
#include "LinkListTools.h"
using namespace std;

class Solution {
public:
    static ListNode* swapPairs(ListNode* head) {
		if (!head) return nullptr;
		if (!head->next) return head;

		ListNode *headNext = head->next;
		head->next = swapPairs(head->next->next);
		headNext->next = head;

		return headNext;
    }

	static ListNode* swapPairs_iter(ListNode* head) {
		ListNode *dummy = new ListNode(-1), *pre = dummy;
		dummy->next = head;
		while (pre->next && pre->next->next) {
			ListNode *t = pre->next->next;
			pre->next->next = t->next;
			cout << "pre->next->next " << pre->next->next->val
				<< " t->next " << t->next->val << endl;
			t->next = pre->next;
			cout << "t->next " << t->next->val << endl;

			pre->next = t;
			cout <<"pre->next " <<pre->next->val << endl;

			pre = t->next;
			cout << pre->val << endl;
		}
		return dummy->next;
	}
};

int main()
{
	int ary[] = {1, 2, 3, 4, 5};
	ListNode *head = createListFromIntArray(ary, lengthArray(ary));
	printList(head);

//	ListNode *head2 = Solution::swapPairs(head);
//	printList(head2);

	ListNode *head3 = Solution::swapPairs_iter(head);
	printList(head3);
	return 0;

}


