# [leetcode] 21_Merge_Two_Sorted_Lists

Merge two sorted linked lists and return it as a new list. The new list  should be made by splicing together the nodes of the first two lists.

```C++
#include <iostream>

using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}	//C++ Constructor member initializer lists
};

class Solution {
public:
    static ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        /* 兩個皆為NULL */
		if (!l1 && !l2)
			return NULL;
		/* 建一個 temp 作為新的 head */
		struct ListNode *tmp = new ListNode(0);
		struct ListNode *head = tmp;

		while (l1 && l2) {
			if (l1->val > l2->val) {	//若 list2 值小則放到 tmp 後面，
				tmp->next = l2;			//list2 ptr++
				l2 = l2->next;
			} else {
				tmp->next = l1;
				l1 = l1->next;
			}
			tmp = tmp->next;
		}

		/* if (l1 != NULL) <==> if (l1)
		if (l1 != NULL) tmp->next = l1;
		if (l2 != NULL) tmp->next = l2;
		*/
        /* 若 list1 ptr 為 TRUE 則表示 list2已空，直接放到後面 */
		tmp->next = l1 ? l1 : l2;
		return head->next;
    }
};

```

