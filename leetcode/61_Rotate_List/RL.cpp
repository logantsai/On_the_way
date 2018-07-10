#include <iostream>
#include "LinkListTools.h"

using namespace std;

class Solution {
public:
    static ListNode* rotateRight(ListNode* head, int k) {
		ListNode *end = head;
		int length = 1;
		for (; end->next; end = end->next)
			length++;

		end->next = head;

		cout << "length: "<< length << endl;
		int step = length - (k % length);
		for (int i = 0; i < step; ++i) {
			head = head->next;
			end = end->next;
		}
		end->next = nullptr;
		return head;
	}
};

int main()
{
	int ary[] = {1, 2, 3, 4, 5, 6, 7, 8};
	ListNode *head = createListFromIntArray(ary, lengthArray(ary));
	printList(head);

	ListNode *head2 = Solution::rotateRight(head, 2);
	printList(head2);
	return 0;
}
