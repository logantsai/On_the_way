#include <iostream>
#include <climits>
#include "LinkListTools.h"
using namespace std;


class Solution {
public:
	static ListNode* insertionSortList(ListNode* head) {
		ListNode *Sorted = new ListNode(-1);
		ListNode *cur = Sorted;

		while (head) {
			ListNode *nextHead = head->next;
			cur = Sorted;
			while(cur->next && cur->next->val <= head->val)
				cur = cur->next;

			head->next = cur->next;
			cur->next = head;
			head = nextHead;
		}

		return Sorted->next;
	}

    static ListNode* selectionSortList(ListNode* head) {
		ListNode *dummy = new ListNode(INT_MAX);
		ListNode *Sorted = new ListNode(INT_MAX);
		ListNode *SortedPtr = Sorted;
		dummy->next = head;
		int min;

		ListNode *minNode, *preNode;
		while (dummy->next != nullptr) {
			min = INT_MAX;
			for (ListNode *ptr = dummy; ptr->next != nullptr; ptr = ptr->next) {
				if (ptr->next->val < min) {
					min = ptr->next->val;
					minNode = ptr->next;
					preNode = ptr;
				}
			}
			preNode->next = minNode->next;
			SortedPtr->next = minNode;
			SortedPtr = SortedPtr->next;
		}

		return Sorted->next;
    }

	static ListNode* insertionSortList_other(ListNode* head) {
        ListNode *dummy = new ListNode(-1), *cur = dummy;
        while (head) {
            ListNode *t = head->next;
            cur = dummy;
            while (cur->next && cur->next->val <= head->val) {
                cur = cur->next;
            }
            head->next = cur->next;
            cur->next = head;
            head = t;
        }
        return dummy->next;
    }
};

int main()
{
	int ary[] = {5, 6, 1, 2};
	ListNode *head = createListFromIntArray(ary, lengthArray(ary));
	printList(head);
	//ListNode *head2 = Solution::insertionSortList(head);
	//printList(head2);

	ListNode *head3 = Solution::insertionSortList(head);
	printList(head3);
	return 0;
}
