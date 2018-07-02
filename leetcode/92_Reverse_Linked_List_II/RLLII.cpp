#include <iostream>
#include "LinkListTools.h"

using namespace std;

class Solution {
public:
    static ListNode* reverseBetween(ListNode* head, int m, int n) {
		ListNode *dummy = new ListNode(-1);
		dummy->next = head;
		ListNode *pre = dummy;
		ListNode *cur = head;
		int i;
		for (i = 1; i < m; i++) {
			pre = pre->next;
			cur = cur->next;
		}
		ListNode *preMth = pre;
		ListNode *Mth = cur;
		ListNode *tmp;

		for (i = m; i <=n; i++) {
			if (!cur) break;
			tmp = cur->next;
			cur->next = pre;
			pre = cur;
			cur = tmp;
		}

		preMth->next = pre;
		Mth->next = cur;
		return dummy->next;
    }
};


int main()
{
	int ary[] = {1, 2, 3, 4, 5};
	ListNode *head = createListFromIntAarry(ary, lengthArray(ary));
	printList(head);

	ListNode *head2 = Solution::reverseBetween(head, 1, 4);
	printList(head2);
	return 0;
}
