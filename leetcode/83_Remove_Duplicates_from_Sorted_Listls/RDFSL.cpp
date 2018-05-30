#include <iostream>

using namespace std;

struct ListNode {
	int val;
	struct ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	static ListNode *deleteDuplicates(ListNode *head) {
		if (!head || !head->next) return head;

		/* Name anchor point as ap. */
		ListNode *ap1 = head;

		while(ap1 && ap1->next) {
			if (ap1->val == ap1->next->val) {
				ListNode *tmp = ap1->next;
				ap1->next = ap1->next->next;
				delete tmp;
			} else {
				ap1 = ap1->next;
			}
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

	struct ListNode *a1 = new ListNode(1);
	struct ListNode *a2 = new ListNode(1);
	struct ListNode *a3 = new ListNode(2);
	struct ListNode *a4 = new ListNode(3);
	struct ListNode *a5 = new ListNode(3);
	a1->next = a2;
	a2->next = a3;
	a3->next = a4;
	a4->next = a5;

	printList(a1);

	struct ListNode *head2 = Solution::deleteDuplicates(a1);
	printList(head2);
	return 0;

}
