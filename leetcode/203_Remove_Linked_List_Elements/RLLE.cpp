#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
static ListNode* removeElements(ListNode* head, int val) {
		ListNode *cur;	// point to current work
		ListNode *dummy = new ListNode(-1);
		dummy->next = head;
		cur = dummy;

		while (cur->next) {
			if (cur->next->val == val) {
				ListNode *tmp = cur->next;
				cur->next = cur->next->next;
				delete tmp;
			} else
				cur = cur->next;
		}
		return dummy->next;
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
	struct ListNode *a3 = new ListNode(3);
	struct ListNode *a4 = new ListNode(3);
	struct ListNode *a5 = new ListNode(4);
	struct ListNode *a6 = new ListNode(5);
	a1->next = a2;
	a2->next = a3;
	a3->next = a4;
	a4->next = a5;
	a5->next = a6;

	printList(a1);

	ListNode *tmp = Solution::removeElements(a1, 3);

	printList(tmp);
	return 0;
}
