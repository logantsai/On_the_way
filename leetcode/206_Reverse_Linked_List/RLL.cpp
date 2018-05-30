#include <iostream>

using namespace std;

struct ListNode {
	int val;
	struct ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	static ListNode* reverseList(ListNode* head) {
		if (!head) return head;
		ListNode* dummy = new ListNode(-1);
		ListNode* cur = head;
		ListNode* tmp;
		while(cur) {
			tmp = cur->next;
			cur->next = dummy;

			dummy = cur;
			cur = tmp;
		}

		delete head->next;
		head->next = NULL;
		return dummy;
	}

	/* !! Need to think by your self ! */
	static ListNode* reverseListRecursive(ListNode *head) {
		if (!head->next || !head) return head;

		/* temp is the new list head */
		struct ListNode * tmp = reverseListRecursive(head->next);
		head->next->next = head;
		head->next = NULL;
		return tmp;
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
	struct ListNode *a2 = new ListNode(2);
	struct ListNode *a3 = new ListNode(5);
	struct ListNode *a4 = new ListNode(10);
	a1->next = a2;
	a2->next = a3;
	a3->next = a4;

	printList(a1);
	//struct ListNode *head = Solution::reverseList(a1);
	struct ListNode *head2 = Solution::reverseListRecursive(a1);
	printList(head2);
	return 0;
}
