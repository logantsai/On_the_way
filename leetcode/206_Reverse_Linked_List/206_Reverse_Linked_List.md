# [leetcode] 206_Reverse_Linked_List

Hint: A linked list can be reversed either iteratively or recursively. Could you implement both?

### iteratively

創一個 dummy node，將 list 的每個節點由頭開始依序指向 dummy 在的序列，重複直到走到尾巴。

### recursively

假設有函式可以將第 K 個節點之後的都反轉且回傳其 head，則會變得如下

N~0~->....->N~k~->N~k+1~<-.....<-N~n~

則你只需要再做 N~k~ -> next -> next = N~k~

N~0~->....->N~k~<-N~k+1~<-.....<-N~n

```C++
#include <iostream>

using namespace std;

struct ListNode {
	int val;
	struct ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	static ListNode* reverseList(ListNode* head) {
		if (!head) return head;
		ListNode* dummy = new ListNode(-1);
		ListNode* cur = head;
		ListNode* tmp;
		while(cur) {
			tmp = cur->next;
			cur->next = dummy;

			dummy = cur;
			cur = tmp;
		}

		delete head->next;
		head->next = NULL;
		return dummy;
	}

	/* !! Need to think by your self ! */
	static ListNode* reverseListRecursive(ListNode *head) {
		if (!head->next || !head) return head;

		/* temp is the new list head */
		struct ListNode * tmp = reverseListRecursive(head->next);
		head->next->next = head;
		head->next = NULL;
		return tmp;
	}
};

```

