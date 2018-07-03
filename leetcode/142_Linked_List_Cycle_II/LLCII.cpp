#include <iostream>
#include "LinkListTools.h"

using namespace std;


class Solution {
public:
    static ListNode *detectCycle(ListNode *head) {
		ListNode *fast, *slow;
		fast = slow = head;

		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
			if (fast == slow) break;
		}

		if (!fast || !fast->next) return nullptr;

		slow = head;

		while(fast != slow) {
			slow = slow->next;
			fast = fast->next;
		}
		return slow;
    }
};


int main()
{
	int ary[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	ListNode *head = createListFromIntArray(ary, lengthArray(ary));
	printList(head);

	ListNode *end = head;
	while (end->next) end = end->next;
	cout << "end : " << end->val << endl;
	ListNode *ringStart = head;
	for (int i = 0; i< 8; ++i)
		ringStart = ringStart->next;
	cout << "Ring start : " << ringStart->val << endl;
	end->next = ringStart;

	ListNode *ring = Solution::detectCycle(head);
	cout << "detectCycle : " << ring->val << endl;
	return 0;
}
