#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    static ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (!headA || !headB) return NULL;

		int sizeA = 0, sizeB = 0;
		struct ListNode *tmpA = headA, *tmpB = headB;
		int diff = 0;

		while (tmpA) {
			sizeA++; tmpA = tmpA->next;
		}
		cout << "sizeA: " << sizeA << endl;

		while (tmpB) {
			sizeB++; tmpB = tmpB->next;
		}
		cout << "sizeB: " << sizeB << endl;

		diff = sizeA - sizeB;
		cout << "diff: " << diff << endl;

		if (diff > 0) {
			for (int i = 0; i < diff; i++)
				headA = headA->next;
		} else {
			diff = 0 - diff;
			for (int i = 0; i < diff; i++)
				headB = headB->next;
		}

		while (headA && headB && (headA != headB)) {
			headA = headA->next;
			headB = headB->next;
		}
		return (headA && headB) ? headA : NULL;
    }

	static ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
		if (!headA || !headB) return NULL;
		ListNode *tmpA = headA, *tmpB = headB;

		while(tmpA != tmpB) {
			tmpA = !tmpA ? headB : tmpA->next;
			tmpB = !tmpB ? headA : tmpB->next;
		}
		return tmpA;
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

	struct ListNode *b1 = new ListNode(11);
	struct ListNode *b2 = new ListNode(13);
	struct ListNode *b3 = new ListNode(15);
    a1->next = a2;
    a2->next = a3;
    a3->next = a4;

	b1->next = b2;
	b2->next = b3;
	//b3->next = a3;

	printList(a1);
	printList(b1);

    //struct ListNode *head = Solution::reverseList(a1);
    struct ListNode *inter = Solution::getIntersectionNode(a1, b1);
	if (inter)
		cout << inter->val << endl;
	else
		cout << "NULL!" << endl;

	struct ListNode *inter2 = Solution::getIntersectionNode2(a1, b1);
	if (inter2)
		cout << inter2->val << endl;
	else
		cout << "NULL!" << endl;


    return 0;
}


