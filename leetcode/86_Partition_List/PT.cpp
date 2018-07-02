#include <iostream>
#include "LinkListTools.h"
using namespace std;

/**     c
  *  T     B
  * -1->1->4->3->2->5->2->N
  */
class Solution {
public:
	static ListNode* partition(ListNode* head, int x) {
		ListNode *target = new ListNode(-1);	//T
		ListNode *cur;
		ListNode *bigThan = nullptr;	//B
		target->next = head;

		for (cur = target; cur != nullptr; cur = cur->next) {
			if (cur->next->val >= x) {
				bigThan = cur->next;
				break;
			}
		}

		while (bigThan) {
			/*確保下一個node 存在才能比較*/
			if (bigThan->next && bigThan->next->val < x) {
				ListNode *curNext = cur->next;

				cur->next = bigThan->next;
				bigThan->next = bigThan->next->next;

				cur = cur->next;
				cur->next = curNext;
			}
			bigThan = bigThan->next;
		}

		return target->next;
	}

	static ListNode *partition_Grandyang(ListNode *head, int x) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *pre = dummy, *cur = head;;
        while (pre->next && pre->next->val < x) pre = pre->next;
        cur = pre;
		cout << cur << " " << pre << endl;
		cout << cur->next->val << " " << pre->next->val << endl;

        while (cur->next) {
            if (cur->next->val < x) {
				cout << cur << " " << pre << endl;
                ListNode *tmp = cur->next;
                cur->next = tmp->next;
                tmp->next = pre->next;
                pre->next = tmp;
                pre = pre->next;
            } else {
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};

int main()
{
	int ary[] = {1, 4, 3, 2, 5, 2};
	ListNode *head = createListFromIntArray(ary, lengthArray(ary));
	printList(head);

	ListNode *head2 = Solution::partition(head, 3);
	printList(head2);
	return 0;
}

