#include <iostream>

using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}	//C++ Constructor member initializer lists
};

class Solution {
public:
    static ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

		if (!l1 && !l2)
			return NULL;

		struct ListNode *tmp = new ListNode(0);
		struct ListNode *head = tmp;

		while (l1 && l2) {
			if (l1->val > l2->val) {
				tmp->next = l2;
				l2 = l2->next;
			} else {
				tmp->next = l1;
				l1 = l1->next;
			}
			tmp = tmp->next;
		}

		/* if (l1 != NULL) <==> if (l1)
		if (l1 != NULL) tmp->next = l1;
		if (l2 != NULL) tmp->next = l2;
		*/
		tmp->next = l1 ? l1 : l2;
		return head->next;
    }
};

int main()
{
	struct ListNode *a1 = new ListNode(1);
	struct ListNode *a2 = new ListNode(2);
	struct ListNode *a3 = new ListNode(5);
	a1->next = a2;
	a2->next = a3;

	struct ListNode *b1 = new ListNode(1);
	struct ListNode *b2 = new ListNode(3);
	struct ListNode *b3 = new ListNode(4);
	b1->next = b2;
	b2->next = b3;


	ListNode *head = Solution::mergeTwoLists(a1 ,b1);
	while(head) {
		printf("%d->", head->val);
		head = head->next;
	}
	printf("NULL\n");
	return 0;
}
