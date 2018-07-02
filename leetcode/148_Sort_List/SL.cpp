#include <iostream>
#include "LinkListTools.h"

using namespace std;

class Solution {
public:
	static ListNode* merge(ListNode* l1, ListNode* l2) {
		ListNode* dummy = new ListNode(-1);
		ListNode* cur = dummy;

		while(l1 && l2) {
			if (l1->val <= l2->val) {
				cur->next = l1;
				l1 = l1->next;
			} else {
				cur->next = l2;
				l2 = l2->next;
			}
			cur = cur->next;
		}

		cur->next = l1 ? l1 : l2;
		return dummy->next;
	}

    static ListNode* sortList(ListNode* head) {
		if (!head->next) return head;

		ListNode *fast, *slow, *pre;
		fast = slow = pre = head;
		/*find the n/2th element */
		while (fast && fast->next) {
			pre = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		pre->next = nullptr;
		return merge(sortList(head), sortList(slow));
    }

};

int main()
{
	int ary[] = {10, 9 ,7, 8, 5, 6, 3, 4, 1, 2};
	ListNode *head = createListFromIntArray(ary, lengthArray(ary));
	printList(head);
	ListNode *head2 = Solution::sortList(head);
	printList(head2);
	return 0;

}
