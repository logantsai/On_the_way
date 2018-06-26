#include <iostream>
#include "LinkListTools.h"
using namespace std;
class Solution {
public:
    static ListNode* oddEvenList(ListNode* head) {
		ListNode *oddPtr, *evenPtr, *tmpOdd, *tmpEven;
		tmpOdd = oddPtr = head;
		tmpEven = evenPtr = head->next;

		while (tmpEven !=  nullptr && tmpEven->next != nullptr) {
			tmpOdd->next = tmpOdd->next->next;
			tmpOdd = tmpOdd->next;
			tmpEven->next = tmpEven->next->next;
			tmpEven = tmpEven->next;
		}
		tmpOdd->next = evenPtr;
		if (tmpEven) tmpEven->next = nullptr;
		return oddPtr;
    }
};


int main()
{
	int ary[] = {2, 1, 3, 5, 6, 4, 7};
	//int ary[] = {2, 1};
	ListNode* head = createListFromIntAarry(ary, lengthArray(ary));
	printList(head);

	ListNode* head2 = Solution::oddEvenList(head);
	printList(head2);

	return 0;
}
