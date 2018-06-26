#include <iostream>
#include "LinkListTools.h"
#include <stack>
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))
using namespace std;

class Solution {
public:
	static ListNode* recu(ListNode* L1, ListNode* L2)
	{

		if (L1 == nullptr && L2 == nullptr) {
			return nullptr;
		}

		ListNode* post = recu(L1->next, L2->next);
		ListNode* tmp;

		if (post == nullptr) {
			tmp = new ListNode(L1->val + L2->val);
			return tmp;
		}

		if (post->val > 9) {
			tmp = new ListNode(L1->val + L2->val + 1);
			post->val = post->val % 10;
		} else {
			tmp = new ListNode(L1->val + L2->val);
		}
		tmp->next = post;

		return tmp;
	}

    static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int l1_len = 0;
		int l2_len = 0;
		int tmp;
		ListNode* ptr;
		for (ptr = l1; ptr != nullptr; ptr = ptr->next)
			l1_len++;

		for (ptr = l2; ptr != nullptr; ptr = ptr->next)
			l2_len++;

		if (l1_len < l2_len) {
			SWAP(l1, l2, ptr);
			SWAP(l1_len, l2_len, tmp);
		}
		cout << "l1 len: " << l1_len << " l2 len: " << l2_len << endl;

		ListNode *new_l1 = createListWithZero(1);
		ListNode *new_l2 = createListWithZero(l1_len-l2_len+1);
		for (ptr = new_l1; ptr->next != nullptr; ptr = ptr->next)
		{}
		ptr->next = l1;

		for (ptr = new_l2; ptr->next != nullptr; ptr = ptr->next)
		{}
		ptr->next = l2;
		printList(new_l1);
		printList(new_l2);


		ListNode* head = recu(new_l1, new_l2);


		return head;
 	}

	static ListNode* addTwoNumbers_stack(ListNode* l1, ListNode* l2) {
		stack<int> s1, s2;
		for (;l1 != nullptr; l1 = l1->next)
			s1.push(l1->val);
		for (;l2 != nullptr; l2 = l2->next)
			s2.push(l2->val);

		int sum = 0;
		ListNode *cur = new ListNode(0);
		while (!s1.empty() || !s2.empty()) {
			if (!s1.empty()) {sum += s1.top(); s1.pop();}
			if (!s2.empty()) {sum += s2.top(); s2.pop();}
			cur->val = sum % 10;
			ListNode *head = new ListNode(sum / 10);
			head->next = cur;
			cur = head;
			sum = cur->val;
		}
		return cur->val == 0 ? cur->next : cur;

	}

};

int main()
{
	int l1[] = {9, 9, 9, 9};
	int l2[] = {9, 9, 9};
	ListNode* l1Ptr = createListFromIntAarry(l1, lengthArray(l1));
	ListNode* l2Ptr = createListFromIntAarry(l2, lengthArray(l2));
	printList(l1Ptr);
	printList(l2Ptr);


//	ListNode* head = Solution::addTwoNumbers(l2Ptr, l1Ptr);
	ListNode* head = Solution::addTwoNumbers_stack(l2Ptr, l1Ptr);

	if (head->val == 0)
		head = head->next;
	printList(head);
	return 0;
}
