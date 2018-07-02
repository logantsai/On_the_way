#include <iostream>
#include "LinkListTools.h"
using namespace std;


void printList(struct ListNode* head)
{
    for(; head != nullptr; head = head->next)
        cout << head->val << "->";
    cout << "NULL\n";
}

ListNode* createSequenceList(int start, int length)
{
    struct ListNode *pre = new ListNode(start);
	struct ListNode *head = pre;
	for (int i = start+1; i < start + length; i++) {
		ListNode *tmp = new ListNode(i);
		pre->next = tmp;
		pre = tmp;
	}
	return head;
}

ListNode* createListFromIntArray(int ary[], int length)
{
	struct ListNode *pre = new ListNode(ary[0]);
	struct ListNode *head = pre;

	for (int i = 1; i < length; i++) {
		ListNode *tmp = new ListNode(ary[i]);
		pre->next = tmp;
		pre = tmp;
	}
	return head;
}

ListNode* createListWithZero(int length) {

	struct ListNode *pre = new ListNode(0);
	struct ListNode *head = pre;

	for (int i = 1; i < length; i++) {
		ListNode *tmp = new ListNode(0);
		pre->next = tmp;
		pre = tmp;
	}
	return head;
}
