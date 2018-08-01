#include <iostream>
#include <vector>
#include "LinkListTools.h"
using namespace std;


class Solution {
public:
    static ListNode *mergeKLists(vector<ListNode *> &lists) {
		int n = lists.size();
		int k;
		while (n > 1) {
			k = n / 2;
			for (int i = 0; i < k; ++i) {
				lists[i] = mergeLists(lists[i], lists[i+k]);
				lists[i+k] = nullptr;
			}
			n = k;
		}

		if (lists.back() != nullptr) lists[0] = mergeLists(lists[0], lists.back());
		return lists[0];
	}

	static ListNode *mergeLists(ListNode* h1, ListNode *h2) {
		ListNode *dummy = new ListNode(-1);
		ListNode *pre = dummy;
		while (h1 && h2) {
			if (h1->val < h2->val) {
				pre->next = h1;
				h1 = h1->next;
			} else {
				pre->next = h2;
				h2 = h2->next;
			}
			pre = pre->next;
			pre->next = nullptr;
		}

		pre->next = h1 ? h1 : h2;

		return dummy->next;
	}
};

int main()
{
	int ary1[] = {1, 2};
	int ary2[] = {2, 4};
	int ary3[] = {3, 10};
	int ary4[] = {5, 6};
	int ary5[] = {7};

	vector<ListNode*> lists(5, nullptr);
	lists[0] = createListFromIntArray(ary1, lengthArray(ary1));
	lists[1] = createListFromIntArray(ary2, lengthArray(ary2));
	lists[2] = createListFromIntArray(ary3, lengthArray(ary3));
	lists[3] = createListFromIntArray(ary4, lengthArray(ary4));
	lists[4] = createListFromIntArray(ary5, lengthArray(ary5));

	ListNode *head = Solution::mergeKLists(lists);
	printList(head);
	return 0;
}
