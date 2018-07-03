#include <iostream>
#include "LinkListTools.h"

using namespace std;

class Solution {
public:
    static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int carry = 0, sum;
		ListNode* dummy = new ListNode(-1);
		ListNode* cur = dummy;
		while(l1 && l2) {
			sum = l1->val + l2->val + carry;
			ListNode *tmp = new ListNode(sum % 10);
			cur->next = tmp;
			carry = sum / 10;
			cur = cur->next;
			l1 = l1->next;
			l2 = l2->next;
		}

		if (!l1 && !l2 && carry > 0) {
			cur->next = new ListNode(carry);
			return dummy->next;
		}

		if (!l1 && !l2) return dummy->next;

		ListNode *second;
		if (l1) second = l1;
		else second = l2;

		while (second) {
			cur->next = new ListNode(cur->val + carry);
			cur = cur->next;
			carry = 0;
			second = second->next;
		}

		return dummy->next;
	}
	static ListNode *addTwoNumbers_Grandyang(ListNode *l1, ListNode *l2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        int carry = 0;
        while (l1 || l2) {
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            int sum = n1 + n2 + carry;
            carry = sum / 10;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (carry) cur->next = new ListNode(1);
        return dummy->next;
    }
};

int main()
{
	int ary1[] = {2, 4, 3};
	int ary2[] = {5, 6, 4};
	ListNode *l1 = createListFromIntArray(ary1, lengthArray(ary1));
	ListNode *l2 = createListFromIntArray(ary2, lengthArray(ary2));

	ListNode *head = Solution::addTwoNumbers(l1, l2);
	printList(head);
	return 0;
}
