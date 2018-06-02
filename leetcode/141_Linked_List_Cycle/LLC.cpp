/*
	Given a linked list, determine if it has a cycle in it.

	Follow up:
	Can you solve it without using extra space?
*/

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	struct ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	bool hasCycle(ListNode* head) {
		ListNode *fast = head, *slow = head;
		while(fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast)
				return true;
		}
		return false;
	}
};
