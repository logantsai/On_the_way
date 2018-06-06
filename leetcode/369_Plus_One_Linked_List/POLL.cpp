#include <iostream>

using namespace std;

#define reverse_method 0

struct ListNode {
	int val;
	struct ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	static ListNode* reverseList(ListNode* head) {
		if (!head) return NULL;

		ListNode *pre = new ListNode(-1);	//dummy
		pre->next = head;
		ListNode *cur = head;
		while (cur) {
			ListNode *tmp = cur->next;
			cur->next = pre;

			pre = cur;
			cur = tmp;
		}

		delete head->next;
		head->next = NULL;
		return pre;
	}

	static ListNode* plusOne(ListNode *head) {
		if (!head) return NULL;
		ListNode *cur = head;
		ListNode *pre;
		int carry = 1;
		while(cur) {
			int val = cur->val;
			cur->val = (cur->val + carry) % 10;
			carry = (val + 1 + carry) > 9 ? 1 : 0;
			pre = cur;
			cur = cur->next;
		}
		if (carry > 0) {
			ListNode* tmp = new ListNode(carry);
			pre->next = tmp;
		}
		return head;
	}
	/**	8999 9999
	  *	8799
	  *	9889
	  * 1293
	  */
	static ListNode* plusOne2(ListNode *head) {
		if (!head) return NULL;
		ListNode *tmp = head;
		ListNode *index = new ListNode(-1);
		while(tmp) {
			if (tmp->val != 9)
				index = tmp;
			tmp = tmp->next;
		}

		if (index->val == -1) {
			index->next = head;
			++index->val;
			head = index;
			index = head->next;
		} else {
			++index->val;
			index = index->next;
		}

		while(index) {
			index->val = 0;
			index = index->next;
		}
		return head;

	}
};

void printList(struct ListNode* head)
{
	while(head) {
		cout << head->val << "->";
		head = head->next;
	}
	cout << "NULL\n";
}

int main()
{
	struct ListNode *a1 = new ListNode(8);
	struct ListNode *a2 = new ListNode(7);
	struct ListNode *a3 = new ListNode(9);
	struct ListNode *a4 = new ListNode(9);
	a1->next = a2;
	a2->next = a3;
	a3->next = a4;

	printList(a1);
#if reverse_method == 1
	struct ListNode *head2 = Solution::reverseList(a1);
	printList(head2);
	struct ListNode *head3 = Solution::plusOne(head2);
	printList(head3);
	struct ListNode *head4 = Solution::reverseList(head3);
	printList(head4);
#else
	struct ListNode *head5 = Solution::plusOne2(a1);
	printList(head5);
#endif
	return 0;
}
