#include <iostream>
#include <vector>
#include "LinkListTools.h"

using namespace std;

class Solution {
public:
	static ListNode* reverse(ListNode *pre, ListNode *end) {
		ListNode *pre2 = pre;
		ListNode *cur, *last;
		cur = last = pre->next;
		while(cur != end) {
			ListNode *tmp = cur->next;
			cur->next = pre2;
			pre2 = cur;
			cur = tmp;
		}
		last->next = end;
		pre->next = pre2;
		return last;
	}

    static ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode *dummy = new ListNode(-1);
		ListNode *pre = dummy;
		dummy->next = head;
		ListNode *cur = head;
		int i = 0;

		while(cur) {
			++i;
			if (i % k == 0) {
				pre = reverse(pre, cur->next);
				cur = pre->next;
			} else {
				cur = cur->next;
			}
		}
		return dummy->next;
    }
};

int main()
{
	int ary[] = {1, 2, 3, 4, 5};
	ListNode *head = createListFromIntArray(ary, lengthArray(ary));
	printList(head);
	ListNode *resultHead = Solution::reverseKGroup(head, 2);
	printList(resultHead);
	return 0;
}
