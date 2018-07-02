#include <iostream>
#include "LinkListTools.h"

using namespace std;

class Solution {
public:
    static ListNode* deleteDuplicates(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode *dummy = new ListNode(-1);
		dummy->next = head;
		ListNode *pre, *cur;
		pre = dummy;
		cur = head;
		while (cur && cur->next) {
			if (pre->next->val != cur->next->val) {
				if (pre->next == cur)
					pre = pre->next;
				else
					pre->next = cur->next;
			}
			cur = cur->next;
		}
		return dummy->next;
    }

	static ListNode* deleteDuplicates_old(ListNode* head) {
    	if (!head || !head->next) return head;
		ListNode *dummy = new ListNode(-1);
		dummy->next = head;
		ListNode *pre, *cur;
		pre = dummy;
		cur = head;
		while (cur && cur->next) {
			if (pre->next->val == cur->next->val) {
				cur = cur->next;
			} else {
				if (pre->next != cur)
					pre->next = cur->next;
				else
					pre = pre->next;
				cur = cur->next;
			}
		}
    	return dummy->next;
	}

	static ListNode *deleteDuplicates_Grandyang(ListNode *head) {
        if (!head || !head->next) return head;

        ListNode *start = new ListNode(0);
        start->next = head;
        ListNode *pre = start;
        while (pre->next) {
            ListNode *cur = pre->next;
            while (cur->next && cur->next->val == cur->val) cur = cur->next;
            if (cur != pre->next) pre->next = cur->next;
            else pre = pre->next;
        }
        return start->next;
	}
};

int main()
{
	int ary[] = {1, 1, 1, 1, 1, 2, 5};
	ListNode* head = createListFromIntArray(ary, lengthArray(ary));
	printList(head);
	ListNode* head2 = Solution::deleteDuplicates(head);
	printList(head2);
	return 0;
}
